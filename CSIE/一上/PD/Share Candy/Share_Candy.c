#include<stdio.h>

void share_candy(int m, int n, int* q, int* r)
{
    *q=m/n,*r=m%n;
}
int main(){
    int m, n, candy_each, candy_remain;
    scanf("%d %d", &m, &n);
    share_candy(m, n, &candy_each, &candy_remain);
    printf("%d %d", candy_each, candy_remain);
    return 0;
}
