#include <stdio.h>

void star(int* arr, int* res)
{
    *res=0;
    for(int i=0;i<5;i++)
        *res+=*(arr+i);
}
int main()
{
    int arr[5], result;
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);

    star(arr, &result);

    printf("%d", result);

    return 0;
}