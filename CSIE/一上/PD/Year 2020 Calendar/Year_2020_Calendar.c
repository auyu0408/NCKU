#include<stdio.h>

int main(){
    int m,month[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    scanf("%d",&m);
    puts("Sun Mon Tue Wed Thu Fri Sat ");
    int start=3;
    for(int i=0;i<m;i++) start=(start+month[i])%7;
    for(int i=0;i<start;i++) printf("    ");
    for(int i=1;i<=month[m];i++)
    {
        printf("%3d ",i);
        start=start+1;
        if(start==7&&i!=month[m])
        {
            puts("");
            start=0;
        }
    }
    return 0;
}