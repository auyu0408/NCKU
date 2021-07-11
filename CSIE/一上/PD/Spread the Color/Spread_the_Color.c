#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char* g, int x, int y)
{
    char origin=*(g+x*N+y);
    for(int i=y-1;i>=0;i--)
    {
        if(*(g+x*N+i)=='X') *(g+x*N+i)=origin;
        else if(*(g+x*N+i)==origin);
        else break;
    }
    for(int i=y+1;i<N;i++)
    {
        if(*(g+x*N+i)=='X') *(g+x*N+i)=origin;
        else if(*(g+x*N+i)==origin);
        else break;
    }
    for(int i=x-1;i>=0;i--)
    {
        if(*(g+i*N+y)=='X') *(g+i*N+y)=origin;
        else if(*(g+i*N+y)==origin);
        else break;
    }
    for(int i=x+1;i<M;i++)
    {
        if(*(g+i*N+y)=='X') *(g+i*N+y)=origin;
        else if(*(g+i*N+y)==origin);
        else break;
    }
    return;
}

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
// Your code goes here