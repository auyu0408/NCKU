#include<stdio.h>

int main(){
    int N;
    scanf("%d\n",&N);
    char ch[N+5];
    gets(ch);
    for(int i=0;2*i<N;i++) ch[i]^=ch[N-1-i]^=ch[i]^=ch[N-1-i];//如果N確實等於字串長度應該沒啥問題
    printf("%s",ch);
    return 0;
}