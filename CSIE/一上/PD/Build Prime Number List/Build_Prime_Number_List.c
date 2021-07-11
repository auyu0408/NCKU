#include<stdio.h>
void prime(int);

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    for(int i=x;i<=y;i++) prime(i);
    return 0;
}
void prime(int x)
{
    int factor=1;
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
        {
            factor=i;//重點，當數字很大的時候如果還一個一個跑，會很慢
            break;
        }
    }
    if(factor==1&&x!=1) printf("%d ",x);
}