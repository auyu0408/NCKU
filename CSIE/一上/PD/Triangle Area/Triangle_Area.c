#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c,s;
    scanf("%lf%lf%lf",&a,&b,&c);
    s=(a+b+c)/2;
    printf("%.2f",pow(s*(s-a)*(s-b)*(s-c),0.5));
    return 0;
}
