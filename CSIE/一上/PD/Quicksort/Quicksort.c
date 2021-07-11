#include <stdio.h>
#include <stdlib.h>
#define n 8000

// Ignore this
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){exit(1);}
// Ignore this

void quicksort(int a[], int low, int high)
{
    int mid,l=low,h=high,temp=a[low];
    if(low>=high) return;
    for(;;)
    {
        while(a[h]>=temp&&h>l)
            h--;
        if(l>=h) break;
        a[l]=a[h];
        l++;
        while(a[l]<=temp&&h>l)//h>l才能做
            l++;
        if(l>=h) break;
        a[h]=a[l];//分配順序要注意
        h--;
    }
    a[l]=temp;
    mid=h;
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}
int main(void) {
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  quicksort(a, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  return 0;
}