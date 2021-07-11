#include<stdio.h>

int main(){
    int N=0,ans=1;
    scanf("%d",&N);
    int M[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(M[i][j]!=M[j][i])
                ans=0;
        }
    }
    if (ans==0) printf("No\n");
    else printf("Yes\n");
    return 0;
}
