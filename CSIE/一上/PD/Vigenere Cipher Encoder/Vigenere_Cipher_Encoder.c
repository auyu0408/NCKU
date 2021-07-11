#include<stdio.h>

int main()
{
    int n,shift=0,key[100];
    char tmp;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&tmp);
        key[i]=tmp-'a';
    }
    getchar();//處理換行字符
    while((scanf("%c",&tmp))!=EOF&&tmp!='\n')
    {
        if(tmp>='A'&&tmp<='Z')
        {
            tmp=tmp+key[shift];
            if(tmp<'A') tmp+=26;
            if(tmp>'Z') tmp-=26;
            shift++;
            if(shift>=n) shift=0;
        }
        if(tmp>='a'&&tmp<='z')
        {
            tmp=tmp-50+key[shift];
            if(tmp<'a'-50) tmp+=26;
            if(tmp>'z'-50) tmp-=26;
            tmp+=50;
            shift++;
            if(shift>=n) shift=0;
        }
        putchar(tmp);
    }
}