#include <stdio.h>

int A(int n,int m)
{
    if(!n) return m+1;
    else if(!m) return A(n-1,1);
    else return A(n-1,A(n,m-1));
}
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",A(a,b));
    return 0;
}
