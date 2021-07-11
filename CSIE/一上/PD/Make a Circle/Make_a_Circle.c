#include<stdio.h>
#define PI 3.14f

int main(){
    float r;
    while(scanf("%f",&r)!=EOF)
    {
        printf("%.2f %.2f",r*r*PI,2*r*PI);
    }
    return 0;
}