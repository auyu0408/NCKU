#include<stdio.h>

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("  %.4d\n+)%.4d\n",x,y);
    printf("------\n%.6d",x+y);
    return 0;
}