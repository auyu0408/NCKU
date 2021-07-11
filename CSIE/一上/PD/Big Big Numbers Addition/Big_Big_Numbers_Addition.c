#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[])
{
    int l_a=(int)strlen(a),l_b=(int)strlen(b),len,out;
    len=l_a>l_b?l_a:l_b,out=0;
    for(int i=0;i<len;i++)
    {
        int sum=out;
        if(i<l_a) sum+=a[l_a-1-i]-'0';
        if(i<l_b) sum+=b[l_b-1-i]-'0';
        if(sum>9) sum-=10,out=1;
        else out=0;
        res[i]=sum+'0';
    }
    if(out==1) res[len]='1',len+=1;
    for(int x=0,y=len-1;x<y;x++,y--)
        res[x]^=res[y]^=res[x]^=res[y];
    res[len]='\0';
}
int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}