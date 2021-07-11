#include<stdio.h>

int main(){
    int N;
    scanf("%d\n",&N);
    char ch[N+5];
    gets(ch);
    for(int i=N-1;i>=0;i--) printf("%c",ch[i]);
    return 0;
}