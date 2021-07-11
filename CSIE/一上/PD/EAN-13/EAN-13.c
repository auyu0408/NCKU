#include<stdio.h>

int main(){
    int code[15]={0},sum=0;
    for (int i=0;i<12;i++)
    {
        scanf("%1d",&code[i]);
        if(i%2==0) sum=sum+code[i]*1;
        else sum=sum+code[i]*3;
    }
    printf("%d",(10-(sum%10))==10?0:10-(sum%10));//驗證碼，假設前面加起來是151，驗證碼是9，假設前面加起來是160，驗證碼是0
    return 0;
}
