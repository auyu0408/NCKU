#include <stdio.h>

int main() {
    int a[35]={0},b[35]={0},temp=0,ans[35]={0};
    for(int i=0;i<32;i++) scanf("%d",&a[i]);
    for(int i=0;i<32;i++) scanf("%d",&b[i]);
    for(int i=31;i>=0;i--)
    {
        ans[i]=a[i]^b[i]^temp;
        if(a[i]+b[i]+temp>=2) temp=1;//加起來大於二要進位
        else temp=0;
    }
    for(int i=0;i<32;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
