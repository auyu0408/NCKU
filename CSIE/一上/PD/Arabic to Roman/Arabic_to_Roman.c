#include<stdio.h>

int main(){
    int x;//法二，暴力建表
    scanf("%d",&x);
    for(int i=0;i<x/1000;i++)
    {
        printf("M");
    }
    x=x%1000;
    if(x>=900) printf("CM");
    else if(x>=500)
    {
        printf("D");
        for(int i=0;i<(x-500)/100;i++)
            printf("C");
    }
    else if(x>=400) printf("CD");
    else
    {
        for(int i=0;i<x/100;i++)
            printf("C");
    }
    x=x%100;
    if(x>=90) printf("XC");
    else if(x>=50)
    {
        printf("L");
        for(int i=0;i<(x-50)/10;i++)
            printf("X");
    }
    else if(x>=40) printf("XL");
    else
    {
        for(int i=0;i<x/10;i++)
            printf("X");
    }
    x=x%10;
    if(x==9) printf("IX");
    else if(x>=5)
    {
        printf("V");
        for(int i=0;i<x-5;i++)
            printf("I");
    }
    else if(x==4) printf("IV");
    else
    {
        for(int i=0;i<x;i++)
            printf("I");
    }
    return 0;
}
/*
#include <stdio.h>

int a, idx=0, val[5];
char ch[5][15][5] = {
	{},//會有4位數，但第0行跟第0個都不想用，想要直接1000就是第四行(四位數)第一個(1000)
	{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"},
	{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"},
	{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"},
	{"", "M", "MM", "MMM"}
};

int main() {
	scanf("%d", &a);

	while (a) val[++idx]=a%10, a/=10;

	for (int i=idx;i>=1;i--)
		printf("%s", ch[i][val[i]]);
}
 */