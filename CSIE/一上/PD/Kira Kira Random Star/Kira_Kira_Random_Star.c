#include <stdio.h>

void star(int* a, int b, int* sum)
{
    *sum=*a+b;
}
int main()
{
    int kirakira, dokidoki, kasumi;
    scanf("%d%d", &kirakira, &dokidoki);

    // kasumi = kirakira + dokidoki
    star(&kirakira, dokidoki, &kasumi);

    printf("%d", kasumi);

    return 0;
}
