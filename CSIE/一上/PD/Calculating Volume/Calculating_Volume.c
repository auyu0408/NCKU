#include <stdio.h>
#include <math.h>
#define PI 3.14

int main() {
    int mode;
    double l,w,h;
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:
            scanf("%lf",&l);
            printf("%.2f",pow(l,3));
            break;
        case 2:
            scanf("%lf%lf%lf",&l,&w,&h);
            printf("%.2f",l*w*h);
            break;
        case 3:
            scanf("%lf%lf",&l,&h);
            printf("%.2f",PI*l*l*h);
            break;
        case 4:
            scanf("%lf",&l);
            printf("%.2f",sqrt(2)/12*l*l*l);
            break;
        default:
            break;
    }
    return 0;
}