#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R)
{
    int c=0;
    for(int i=0;;i++)
    {
        if(*(R+i)=='P') c++;
        if(*(R+i)=='N') c--;
        if(*(R+i)=='\0') break;
    }
    return c;
}
int main(int argc, char *argv[])
{
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}