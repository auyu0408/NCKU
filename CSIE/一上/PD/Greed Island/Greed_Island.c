#include<stdio.h>

int main(){
    char ch;
    while((ch=getchar())!=EOF)
    {
        switch(ch)
        {
            case'A':
                printf("C");
                break;
            case'B':
                printf("R");
                break;
            case'C':
                printf("W");
                break;
            case'D':
                printf("Z");
                break;
            case'E':
                printf("G");
                break;
            default:
                break;
        }
    }
    return 0;
}
/*
#include<stdio.h>
#include<string.h>

int main(){
    char ch[21];
    scanf("%s",ch);
    for(int i=0;i<strlen(ch);i++)
    {
        if(ch[i]=='A') printf("C");
        if(ch[i]=='B') printf("R");
        if(ch[i]=='C') printf("W");
        if(ch[i]=='D') printf("Z");
        if(ch[i]=='E') printf("G");
    }
    return 0;
}
 */