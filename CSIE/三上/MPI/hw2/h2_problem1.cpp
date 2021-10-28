#include <mpi.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include "bmp.h"

using namespace std;

//times of smooth
#define NSmooth 1000

BMPHEADER bmpHeader;//BMP file's header
BMPINFO bmpInfo;//BMP's infomation
RGBTRIPLE **BMPSaveData = NULL;//save the data it would be write                                            
RGBTRIPLE **BMPData = NULL;//save BMP data temporary              

int readBMP( char *fileName);//read file and save in BMPSaveData
int saveBMP( char *fileName);//write file
void swap(RGBTRIPLE *a, RGBTRIPLE *b);//change two BMP file
RGBTRIPLE **alloc_memory( int Y, int X );//allocate memory, Y*X matrix

int main(int argc,char *argv[])
{
	char *infileName = "input.bmp";//input file name
    char *outfileName = "output.bmp";//output file name
	double startwtime = 0.0, endwtime=0;//record execution time
	int size, process_id;//# of process and self ID
	//variable used in scaatterv
	int buffer_size;
	int *num_of_send, *start_addr, *sub_size, *bound_sendcounts, *lower_bound_displs;
	int remainder, size_remainder, sub_size_ori; 
	
	//read file, Each process_id will got a copy of BMPHEADER and BMPINFO
	if ( readBMP( infileName) )
			cout << "Read file successfully!!" << endl;
	else 
			cout << "Read file fails!!" << endl;
	
	// Basic Mpi Stuff	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &process_id); // Get process_id(id)
	MPI_Comm_size(MPI_COMM_WORLD, &size); // Get global size
	MPI_Status status;
	
	// Build MPI_Datatype MPI_RGBTRIPLE
	MPI_Datatype MPI_RGBTRIPLE;
	int block_len[3];           // the number of elements in each "block" will be 1 for us
	MPI_Aint displacements[3];  // displacement of each element from start of new type
	MPI_Datatype typelist[3];   // MPI types of the elements

	for(int i = 0; i < 3; ++i) {
		block_len[i] = 1;
		typelist[i] = MPI_UNSIGNED_CHAR;
		displacements[i] = i; // D
	}

	// Building new MPI type
	MPI_Type_struct(3, block_len, displacements, typelist, &MPI_RGBTRIPLE);
	MPI_Type_commit(&MPI_RGBTRIPLE);
	
	//record start time
	MPI_Barrier(MPI_COMM_WORLD);
	startwtime = MPI_Wtime();
	
	// Elements for scatterv for bmpData
	num_of_send = (int *) malloc(sizeof(int) * size);
	start_addr = (int *) malloc(sizeof(int) * size);
	sub_size = (int *) malloc(sizeof(int) * size);
	// Elements remainderaining after division among processes
	remainder = (bmpInfo.biHeight * bmpInfo.biWidth) % size; 
	size_remainder = bmpInfo.biHeight % size;
	sub_size_ori = bmpInfo.biHeight / size;
	// Sum of counts. Used to calculate displacements
	int sum = 0;           
	
	// Elements for scatterv for lower_bound and upper bound
	bound_sendcounts = (int *) malloc(sizeof(int)*size);
	lower_bound_displs = (int *) malloc(sizeof(int)*size);
	// upper bound can just use start_addr
	
	// Calculate send counts and displacements of bmpData
    for (int i = 0; i < size; i++) {
        num_of_send[i] = (bmpInfo.biHeight * bmpInfo.biWidth)/size;
		// if there are remainderaining, distribute it to every procsss
        if (remainder > 0) {
            num_of_send[i]++;
            remainder--;
        }
		sub_size[i] = sub_size_ori;
		if (size_remainder > 0) {
			sub_size[i]++;
			size_remainder--;
		}
        start_addr[i] = sum;
        sum += num_of_send[i];
		
		// Set num_of_send and start_addr for bound
		bound_sendcounts[i] = bmpInfo.biWidth; // bound_sendcounts is the same for lower_bound and upper bound
		lower_bound_displs[i] = sum - bmpInfo.biWidth;
    }
	
	// The elements of local_BMPdata
	buffer_size = bmpInfo.biWidth * sub_size[0];	
	//alloc memory to BMPData
	BMPData = alloc_memory(bmpInfo.biHeight, bmpInfo.biWidth);
	// Receive Buffer of upper bound for each process_id
	RGBTRIPLE **Buffer_upper = NULL;
	Buffer_upper = alloc_memory(1, bmpInfo.biWidth);
	// Receive Buffer of lower bound for each process_id
	RGBTRIPLE **Buffer_lower = NULL;
	Buffer_lower = alloc_memory(1, bmpInfo.biWidth);
		
	/* Each process_id have its own temporary array, format like the sample below
		|Buffer_upper|
		|............|
		|...Buffer...|
		|............|
		|Buffer_lower|
	*/
	// Put data into BMPData First
	swap(BMPSaveData,BMPData);
	
	// Scatter the data among processes
	MPI_Scatterv(BMPData[0], num_of_send, start_addr, MPI_RGBTRIPLE, BMPData[0], buffer_size, MPI_RGBTRIPLE, 0, MPI_COMM_WORLD);
	
	if (process_id % 2 == 0) {
		// Even Process -> Odd Process
		//upper bound
		MPI_Send(BMPData[sub_size[process_id] - 1], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id + 1, 1, MPI_COMM_WORLD);
		MPI_Recv(Buffer_upper[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id > 0  ? process_id-1 : size-1 , 1, MPI_COMM_WORLD, &status);
		//lower bound
		MPI_Send(BMPData[0], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id > 0  ? process_id-1 : size-1, 1, MPI_COMM_WORLD);
		MPI_Recv(Buffer_lower[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id+1 , 1, MPI_COMM_WORLD, &status);
	} else {
		// Odd Process -> Even Process
		//upper bound
		MPI_Recv(Buffer_upper[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id - 1, 1, MPI_COMM_WORLD, &status);
		MPI_Send(BMPData[sub_size[process_id] - 1], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id < size-1  ? process_id+1 : 0, 1, MPI_COMM_WORLD);
		//lower bound
		MPI_Recv(Buffer_lower[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id < size-1  ? process_id+1 : 0, 1, MPI_COMM_WORLD, &status);
		MPI_Send(BMPData[0], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id-1 , 1, MPI_COMM_WORLD);
	}
		
	//smooth
	for(int count = 0; count < NSmooth ; count ++){
		//let BMPData get correct info
		if (count != 0)
			swap(BMPSaveData,BMPData);
		
		//smooth
		for(int i = 0; i<sub_size[process_id]; i++) {
			for(int j =0; j<bmpInfo.biWidth ; j++){
				//set top/down/left/right
				int top = i>0 ? i-1 : sub_size[process_id]-1;
				int down = i<sub_size[process_id]-1 ? i+1 : 0;
				int left = j>0 ? j-1 : bmpInfo.biWidth-1;
				int right = j<bmpInfo.biWidth-1 ? j+1 : 0;
				if (i == 0 && size!=1) {
					// For the top of each block, using Buffer_upper as the upper boundary
					BMPSaveData[i][j].rgbBlue =  (double) (BMPData[i][j].rgbBlue + Buffer_upper[0][j].rgbBlue + BMPData[down][j].rgbBlue + BMPData[i][left].rgbBlue + BMPData[i][right].rgbBlue
						+ Buffer_upper[0][left].rgbBlue + Buffer_upper[0][right].rgbBlue + BMPData[down][left].rgbBlue + BMPData[down][right].rgbBlue)/9+0.5;
					BMPSaveData[i][j].rgbGreen =  (double) (BMPData[i][j].rgbGreen + Buffer_upper[0][j].rgbGreen + BMPData[down][j].rgbGreen + BMPData[i][left].rgbGreen + BMPData[i][right].rgbGreen
						+ Buffer_upper[0][left].rgbGreen + Buffer_upper[0][right].rgbGreen + BMPData[down][left].rgbGreen +BMPData[down][right].rgbGreen)/9+0.5;
					BMPSaveData[i][j].rgbRed =  (double) (BMPData[i][j].rgbRed + Buffer_upper[0][j].rgbRed + BMPData[down][j].rgbRed + BMPData[i][left].rgbRed + BMPData[i][right].rgbRed
						+ Buffer_upper[0][left].rgbRed + Buffer_upper[0][right].rgbRed + BMPData[down][left].rgbRed + BMPData[down][right].rgbRed)/9+0.5;
				} else if (i == sub_size[process_id] - 1 && size!=1) {
					// For the bottom of each block, using Buffer_lower as the lower boundary
					BMPSaveData[i][j].rgbBlue =  (double) (BMPData[i][j].rgbBlue + BMPData[top][j].rgbBlue + Buffer_lower[0][j].rgbBlue + BMPData[i][left].rgbBlue + BMPData[i][right].rgbBlue
						+ BMPData[top][left].rgbBlue + BMPData[top][right].rgbBlue + Buffer_lower[0][left].rgbBlue + Buffer_lower[0][right].rgbBlue)/9+0.5;
					BMPSaveData[i][j].rgbGreen =  (double) (BMPData[i][j].rgbGreen+BMPData[top][j].rgbGreen + Buffer_lower[0][j].rgbGreen + BMPData[i][left].rgbGreen + BMPData[i][right].rgbGreen
						+ BMPData[top][left].rgbGreen + BMPData[top][right].rgbGreen + Buffer_lower[0][left].rgbGreen + Buffer_lower[0][right].rgbGreen)/9+0.5;
					BMPSaveData[i][j].rgbRed =  (double) (BMPData[i][j].rgbRed + BMPData[top][j].rgbRed + Buffer_lower[0][j].rgbRed + BMPData[i][left].rgbRed + BMPData[i][right].rgbRed
						+ BMPData[top][left].rgbRed + BMPData[top][right].rgbRed + Buffer_lower[0][left].rgbRed + Buffer_lower[0][right].rgbRed)/9+0.5;
				} else {
					BMPSaveData[i][j].rgbBlue =  (double) (BMPData[i][j].rgbBlue + BMPData[top][j].rgbBlue + BMPData[down][j].rgbBlue + BMPData[i][left].rgbBlue + BMPData[i][right].rgbBlue
						+ BMPData[top][left].rgbBlue + BMPData[top][right].rgbBlue + BMPData[down][left].rgbBlue + BMPData[down][right].rgbBlue)/9+0.5;
					BMPSaveData[i][j].rgbGreen =  (double) (BMPData[i][j].rgbGreen + BMPData[top][j].rgbGreen + BMPData[down][j].rgbGreen + BMPData[i][left].rgbGreen+BMPData[i][right].rgbGreen
						+ BMPData[top][left].rgbGreen + BMPData[top][right].rgbGreen + BMPData[down][left].rgbGreen + BMPData[down][right].rgbGreen)/9+0.5;
					BMPSaveData[i][j].rgbRed =  (double) (BMPData[i][j].rgbRed + BMPData[top][j].rgbRed + BMPData[down][j].rgbRed + BMPData[i][left].rgbRed + BMPData[i][right].rgbRed
						+ BMPData[top][left].rgbRed + BMPData[top][right].rgbRed + BMPData[down][left].rgbRed + BMPData[down][right].rgbRed)/9+0.5;
				}
			}
		}
		// For Each iteration, we need to switch bound again.
		// For the case of np 1
		if (size == 1)
			continue;
		// Send Upper Bound
		if (process_id % 2 == 0) {
			// Even Process -> Odd Process
			//upper bound
			MPI_Send(BMPSaveData[sub_size[process_id] - 1], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id + 1, 1, MPI_COMM_WORLD);
			MPI_Recv(Buffer_upper[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id > 0  ? process_id-1 : size-1 , 1, MPI_COMM_WORLD, &status);
			//lower bound
			MPI_Send(BMPSaveData[0], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id > 0  ? process_id-1 : size-1, 1, MPI_COMM_WORLD);
			MPI_Recv(Buffer_lower[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id+1 , 1, MPI_COMM_WORLD, &status);
		} else {
			// Odd Process -> Even Process
			//upper bound
			MPI_Recv(Buffer_upper[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id - 1, 1, MPI_COMM_WORLD, &status);
			MPI_Send(BMPSaveData[sub_size[process_id] - 1], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id < size-1  ? process_id+1 : 0, 1, MPI_COMM_WORLD);
			//lower bound
			MPI_Recv(Buffer_lower[0], bmpInfo.biWidth, MPI_RGBTRIPLE , process_id < size-1  ? process_id+1 : 0, 1, MPI_COMM_WORLD, &status);
			MPI_Send(BMPSaveData[0], bmpInfo.biWidth, MPI_RGBTRIPLE, process_id-1 , 1, MPI_COMM_WORLD);
		}
	}
	
	MPI_Barrier(MPI_COMM_WORLD);
	// Gather each results back
	MPI_Gatherv(BMPSaveData[0], buffer_size, MPI_RGBTRIPLE, BMPSaveData[0], num_of_send, start_addr, MPI_RGBTRIPLE, 0, MPI_COMM_WORLD);
	
	if (process_id == 0){
		 //write file
        if ( saveBMP( outfileName ) )
                cout << "Save file successfully!!" << endl;
        else
                cout << "Save file fails!!" << endl;
		//get final time
        endwtime = MPI_Wtime();
        cout << "The execution time = "<< endwtime-startwtime <<endl ;
		
	}

	// Free RGBTRIPLE_Buffer
	free(Buffer_lower[0]);
	free(Buffer_upper[0]);
	free(Buffer_lower);
	free(Buffer_upper);

    //free scatter variable
	free(num_of_send);
	free(start_addr);
	free(sub_size);
	free(bound_sendcounts);
	free(lower_bound_displs);
	
	// Free BMPSaveData and BMPData
	free(BMPData[0]);
    free(BMPSaveData[0]);
    free(BMPData);
    free(BMPSaveData);
	
	MPI_Type_free(&MPI_RGBTRIPLE);
    MPI_Finalize();

    return 0;
}

//read image
int readBMP(char *fileName)
{
	//build input image object
    ifstream bmpFile( fileName, ios::in | ios::binary );

	//if file can't open
	if ( !bmpFile ){
			cout << "It can't open file!!" << endl;
			return 0;
	}

	//read bmp header file
	bmpFile.read( ( char* ) &bmpHeader, sizeof( BMPHEADER ) );

	//judge if it is a bmp file
	if( bmpHeader.bfType != 0x4d42 ){
			cout << "This file is not .BMP!!" << endl ;
			return 0;
	}
	//read BMP info
	bmpFile.read( ( char* ) &bmpInfo, sizeof( BMPINFO ) );
	
	//check if bits depth is 24 bits or not.
	if ( bmpInfo.biBitCount != 24 ){
			cout << "The file is not 24 bits!!" << endl;
			return 0;
	}

	//fix picture into 4's multiple
	while( bmpInfo.biWidth % 4 != 0 )
		bmpInfo.biWidth++;

	//allocate memory
	BMPSaveData = alloc_memory( bmpInfo.biHeight, bmpInfo.biWidth);
	
	//read pixels infomation
	//for(int i = 0; i < bmpInfo.biHeight; i++)
	//	bmpFile.read( (char* )BMPSaveData[i], bmpInfo.biWidth*sizeof(RGBTRIPLE));
	bmpFile.read( (char* )BMPSaveData[0], bmpInfo.biWidth*sizeof(RGBTRIPLE)*bmpInfo.biHeight);
	
	//close file
	bmpFile.close();
    return 1;
}
//save picture
int saveBMP( char *fileName)
{
 	//check if it is BMP file
	if( bmpHeader.bfType != 0x4d42 ){
			cout << "This file is not .BMP!!" << endl ;
			return 0;
	}
        
 	//build output file object
    ofstream newFile( fileName,  ios:: out | ios::binary );

	//file can't build
	if ( !newFile ){
		cout << "The File can't create!!" << endl;
		return 0;
	}

	//Write BMP header file and info
	newFile.write( ( char* )&bmpHeader, sizeof( BMPHEADER ) );
	newFile.write( ( char* )&bmpInfo, sizeof( BMPINFO ) );

	//build pixel infomation
	newFile.write( ( char* )BMPSaveData[0], bmpInfo.biWidth*sizeof(RGBTRIPLE)*bmpInfo.biHeight );

	//close file
	newFile.close();
        return 1;
}
//allocate memory: return a Y*X matrix
RGBTRIPLE **alloc_memory(int Y, int X )
{        
	//build a pointer array length y.
    RGBTRIPLE **temp = new RGBTRIPLE *[ Y ];
	RGBTRIPLE *temp2 = new RGBTRIPLE [ Y * X ];
    memset( temp, 0, sizeof( RGBTRIPLE ) * Y);
    memset( temp2, 0, sizeof( RGBTRIPLE ) * Y * X );

	//build a length x array in each pointer array
	for( int i = 0; i < Y; i++){
			temp[ i ] = &temp2[i*X];
	}
    return temp;
}
//change two RGBTRIPLE array
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
	RGBTRIPLE *temp;
	temp = a;
	a = b;
	b = temp;
}
