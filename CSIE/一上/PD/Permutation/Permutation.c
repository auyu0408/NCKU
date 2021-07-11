#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct result{
    char ans[7];
}result;
int count=0;
result res[720];
int cmp(const void*a,const void*b)
{
    result *A=(result *)a;
    result *B=(result *)b;
    return strcmp(A->ans,B->ans);
}
void swap(char *A,char*B)
{
    char tmp;
    tmp=*A;
    *A=*B;
    *B=tmp;
}
void permutation(char *str,int s,int e)
{
    if(s==e)
    {
        strcpy(res[count].ans,str);
        count+=1;
        return;
    }
    else
    {
        for(int i=s;i<=e;i++)
        {
            swap((str+s),(str+i));
            permutation(str,s+1,e);
            swap((str+s),(str+i));
        }
    }

}
int main()
{
    char origin[7];
    int len;
    scanf("%s",origin);
    len=(int)strlen(origin);
    permutation(origin,0,len-1);
    qsort((void *)res,count,sizeof(result),cmp);
    for(int i=0;i<count;i++)
    {
        puts(res[i].ans);
    }
    return 0;
}