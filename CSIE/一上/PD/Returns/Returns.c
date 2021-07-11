#include <stdio.h>
#include <stdlib.h>

int* Returns(int n)
{
    int *otae=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) *(otae+i)=i*i;
    return otae;
}
int main(int argc, char *argv[])
{
    int in, *out;
    scanf("%d", &in);
    out = Returns(in);
    for(int i = 0;i < in;++i) {
        printf("out[%d] = %d\n", i, out[i]);
    }
    free(out);
    return 0;
}