#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}

int main(){
    int ans[3];
    scanf("%d%d%d",&ans[0],&ans[1],&ans[2]);
    qsort((void *)ans,3,sizeof(int),cmp);
    printf("%d",ans[1]);
    return 0;
}
/*
type2
#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((a>b&&b>c)||(c>b&&b>a)) printf("%d",b);
    else if((b>a&&a>c)||(c>a&&a>b)) printf("%d",a);
    else printf("%d",c);
    return 0;
}
*/