#include<stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%.4d %.4d %.4d",a,a-b+c,a-b+c-d);
    return 0;
}