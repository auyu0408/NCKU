#include<stdio.h>

int main(){
    int a,b,temp,count=0;
    scanf("%d%d",&a,&b);
    while(a>0&&b>0)
    {
        scanf("%d",&temp);
        if(count%2==0) b=b-temp;
        else a=a-temp;
        count++;
    }
    if(a<=0) printf("B");
    else printf("A");
    return 0;
}
