#include<stdio.h>

int main(){
    int H,M;
    scanf("%d%d",&H,&M);
    M=M+50;
    if(M>=60)
    {
        M=M%60;
        H=H+1;
    }
    printf("%.2d:%.2d\n",H,M);
    return 0;
}
