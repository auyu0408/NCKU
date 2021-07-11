#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    if(N<1) printf("Calm");
    if(N>=1&&N<=3) printf("Light air");
    if(N>=4&&N<=27) printf("Breeze");
    if(N>=28&&N<=47) printf("Gale");
    if(N>=48&&N<=63) printf("Storm");
    if(N>63) printf("Hurricane");
    return 0;
}