#include <stdio.h>
#include <string.h>
#define Max 51

int main() {
    int x,y,n,s[Max][Max];
    scanf("%d",&n);
    memset(s,0,sizeof(s));//初始化字串，可以把陣列視為一個字串memset(字串名稱,初始值,字串大小(才知道要初始化多少位置))
    x=1;y=(n+1)>>1;
    for(int i=1;i<=n*n;i++)
    {
        if(s[x][y]==0)
        {
            s[x][y]=i;
            continue;
        }
        x=x-1<1?n:x-1;
        y=y+1>n?1:y+1;
        if(s[x][y]==0)
        {
            s[x][y]=i;
            continue;
        }
        x=x+1>n?1:x+1;
        x=x+1>n?1:x+1;
        y=y-1<1?n:y-1;
        s[x][y]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",s[i][j]);
        puts("");
    }
    return 0;
}