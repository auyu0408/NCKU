#include<stdio.h>

int main(){
    int home[10]={0},max=0,temp=0;
    for(int i=0;i<10;i++) scanf("%d",home+i);
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            temp=(home[i]+home[j])*(j-i);
            max=(temp>max?temp:max);
        }
    }
    printf("%d",max);
    return 0;
}
