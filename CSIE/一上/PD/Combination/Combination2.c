#include<stdio.h>
int combination(int ,int);

int main(){
    int m,n;
    long int ans;
    scanf("%d%d",&m,&n);
    ans=combination(m,n);
    printf("%ld",ans);
    return 0;
}
int combination(int m,int n)
{
    if (n==1) return m;
    if (m==1) return 1;
    if (m==n) return 1;
    return combination(m-1,n-1)+combination(m-1,n);
}