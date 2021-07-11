#include<stdio.h>

int main(){
    int A,B,C,D;
    scanf("%d/%d**%d/)%d",&A,&B,&C,&D);//注意，如果沒有打中間配合符號只會吃到第一個數，後面沒辦法對齊
    printf("%d",A+B+C+D);
    return 0;
}
