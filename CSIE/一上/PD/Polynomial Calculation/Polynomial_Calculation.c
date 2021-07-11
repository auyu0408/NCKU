#include<stdio.h>
#include<math.h>

int main(){
    double x,ans;
    scanf("%lf",&x);
    ans=7*pow(x,4)-8*pow(x,3)-pow(x,2)+6*x-22;
    printf("%.1f",ans);
    return 0;
}
