#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    for (int i=1;i<=x;i++)
    {
        for (int j=x;j>i;j--) printf(" ");//配置:假設x行，第一行:x-1 1 x-1，第2行:x-2 3 x+2，第n行:x-n 2n-1 x-n
        for (int k=0;k<2*i-1;k++) printf("*");
        puts("");
    }
    return 0;
}
