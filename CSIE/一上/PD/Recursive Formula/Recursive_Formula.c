#include <stdio.h>

int recursive(int x1, int x2, int n)
{
    if(n==1) return x1;
    else if(n==2) return x2;
    else return recursive(x1,x2,n-1)+recursive(x1,x2,n-2);
}
int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    while(a!=b!=n!=0)
    {
        printf("%d\n",recursive(a,b,n));
        scanf("%d%d%d",&a,&b,&n);
    }
    return 0;
}
