#include<stdio.h>
#include<stdlib.h>

int main()
{
    int times,r,c;
    scanf("%d",&times);
    times/=90;
    scanf("%d %d",&r,&c);
    int (*m)[c]=(int (*)[c])malloc(sizeof(int)*r*c);//malloc二維矩陣
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    if(times==1)
    {
        for(int i=0;i<c;i++)
        {
            for(int j=r-1;j>=0;j--)
            {
                printf("%d ",m[j][i]);
            }
            printf("\n");
        }
    }
    else if(times==2)
    {
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                printf("%d ",m[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for(int i=c-1;i>=0;i--)
        {
            for(int j=0;j<r;j++)
            {
                printf("%d ",m[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}