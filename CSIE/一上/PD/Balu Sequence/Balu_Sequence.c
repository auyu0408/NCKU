#include <stdio.h>
#define BIG 1000000007

long B(int i)
{
    if(i<=2) return 1;
    else return (2*B(i-1)+3*B(i-2))%BIG;
}
int main() {
    int a;
    scanf("%d",&a);
    printf("%ld",B(a));
    return 0;
}