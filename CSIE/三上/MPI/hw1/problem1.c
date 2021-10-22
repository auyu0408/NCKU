#include <stdio.h>
#include <limits.h>//UINT_MAX
#include <mpi.h>

int checkCircuit(int, int);

int main()
{
    int i;

    int comm_sz;
    int my_rank;
    int send_count;

    int count = 0;
    double starttime = 0.0, totaltime = 0.0;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    starttime = MPI_Wtime();

    for (i = my_rank; i <= USHRT_MAX; i+=comm_sz) {
        count += checkCircuit (my_rank, i);
    }

    if(my_rank != 0){
        MPI_Send(&count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf ("Process %d finished.\n", my_rank);
        fflush (stdout);
    }
    else{
        for(i=1;i<comm_sz; i++){
            MPI_Recv(&send_count, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            count += send_count;
        }
        totaltime = MPI_Wtime() - starttime;
        printf("Process %d finished in time %f secs.\n", my_rank, totaltime);
	    fflush (stdout);
        printf("\nA total of %d solutions were found.\n\n", count);
    }
    
    MPI_Finalize();
    return 0;
}

#define EXTRACT_BIT(n,i) ( (n & (1<<i) ) ? 1 : 0)
#define SIZE 16

int checkCircuit(int id, int bits){
    int v[SIZE];
    int i;

    for(i= 0; i < SIZE; i++)
        v[i] = EXTRACT_BIT(bits, i);

    if (  (v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3])
        && (!v[3] || !v[4]) && (v[4] || !v[5])
        && (v[5] || !v[6]) && (v[5] || v[6])
        && (v[6] || !v[15]) && (v[7] || !v[8])
        && (!v[7] || !v[13]) && (v[8] || v[9])
        && (v[8] || !v[9]) && (!v[9] || !v[10])
        && (v[9] || v[11]) && (v[10] || v[11])
        && (v[12] || v[13]) && (v[13] || !v[14])
        && (v[14] || v[15])  )
    {
        printf ("%d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d \n", id,
        v[15],v[14],v[13],v[12],
        v[11],v[10],v[9],v[8],v[7],v[6],v[5],v[4],v[3],v[2],v[1],v[0]);
        fflush (stdout);
        return 1;
    } else {
        return 0;
    }
}