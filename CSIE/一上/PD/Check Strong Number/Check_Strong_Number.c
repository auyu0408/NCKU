#include<stdio.h>
int factorial(int);

int main(){
    int sum=0,n,ans;
    scanf("%d",&n);
    ans=n;
    while(n!=0)
    {
        sum=sum+factorial(n%10);
        n=n/10;
    }
    if(sum!=ans) printf("%d is not a strong number.",ans);
    else printf("%d is a strong number.",ans);
    return 0;
}
int factorial(int r)
{
    if(r==1||r==0)
        return 1;
    else return r*factorial(r-1);
}