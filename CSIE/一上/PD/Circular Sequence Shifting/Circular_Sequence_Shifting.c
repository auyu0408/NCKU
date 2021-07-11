#include<stdio.h>

int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    int chair[n];
    for(int i=0;i<n;i++)
    {
        chair[i]=i+x<n?i+x:(i+x)%n;
    }
    printf("%d",chair[y]);
    return 0;
}
