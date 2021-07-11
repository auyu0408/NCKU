#include <stdio.h>
#define Max 1000

int main() {
    int n,m,temp;
    scanf("%d%d",&n,&m);
    int a[Max]={0};
    for(int i=0;i<n+m;i++)
    {
        scanf("%d",&temp);
        a[temp]=1;
    }
    for(int i=0;i<Max;i++)
    {
        if(a[i]!=0)
            printf("%d ",i);
    }
    return 0;
}