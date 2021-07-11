#include<stdio.h>
#include <string.h>

int main(){
    char str[10000];
    gets(str);
    int i=(int)strlen(str);
    for (int j=0;j<i;j++)
    {
        if(str[j]==' ')
        {
            if(str[j+1]!=' ')
                printf("%c",str[j]);
        }
        else printf("%c",str[j]);
    }
    return 0;
}
/*
 #include <stdio.h>

char ch, tmp;

int main() {

	while (~scanf("%c", &ch)) {
		if (ch=='\n') break;
		if (ch==' ' && tmp==' ') continue;
		printf("%c", (tmp=ch));
	}
}
*/