#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
// Your code goes here
void check_sudoku(int (*grid_p)[NUM]){
    int check[NUM][NUM]={0};
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int temp=(*grid_p)[i*NUM+j];
            for(int k=0;k<9;k++)
            {
                if((*grid_p)[i*NUM+k]==temp&&k!=j)
                    check[i][k]=1;
                if((*grid_p)[k*NUM+j]==temp&&k!=i)
                    check[k][j]=1;
            }
        }
    }
    for(int i=0;i<9;i+=3)
    {
        for(int j=0;j<9;j+=3)
        {
            int num_check[10]={0};
            for(int k=0;k<3;k++)
            {
                for(int l=0;l<3;l++)
                {
                    num_check[(*grid_p)[(i+k)*NUM+(j+l)]]++;
                }
            }
            for(int m=0;m<10;m++)
            {
                   if(num_check[m]>1)
                {
                    for(int k=0;k<3;k++)
                    {
                        for(int l=0;l<3;l++)
                        {
                            if((*grid_p)[(i+k)*NUM+(j+l)]==m)
                                check[i+k][j+l]=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(check[i][j]==1)
            {
                printf("(%d,%d)",i,j);
                puts("");
            }
        }
    }
}