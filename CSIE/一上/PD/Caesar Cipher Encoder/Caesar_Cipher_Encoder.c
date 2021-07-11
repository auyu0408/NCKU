#include<stdio.h>

int main(){
    int num;
    scanf("%d\n",&num);
    num=num%26;
    char temp;
    while((temp=getchar())!='\n')
    {
        if('A'<=temp&&temp<='Z')
        {
            temp=temp+num;
            if(temp<'A')
            {
                temp=temp+26;
            }
            if(temp>'Z')
            {
                temp=temp-26;
            }
        }
        if('a'<=temp&&temp<='z')
        {
            temp=temp-50+num;
            if(temp<'a'-50)
            {
                temp=temp+26;
            }
            if(temp>'z'-50)
            {
                temp=temp-26;
            }
            temp=temp+50;
        }
        putchar(temp);
    }
    return 0;
}