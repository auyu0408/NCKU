#include <stdio.h>
long long combination(int,int);

int main() {
    int m,n;
    scanf("%d %d",&m,&n);
    n=n>(m-n)?n:(m-n);
    printf("%lld",combination(m,n));
    return 0;
}
long long combination(int m,int n)
{
    long long up=1;
    long long down=1;
    for(int i=1;i<=m-n;i++) down=down*i;
    for(int i=n+1;i<=m;i++) up=up*i;
    return up/down;
}//in my vsCode, I can't used unsigned long
/*#include <stdio.h>
#define int long long

int n, m, res1=1, res2=1;
int vis1[35], vis2[35];

signed main() {
	scanf("%lld%lld", &m, &n);

	for (int i=n+1;i<=m;i++) vis1[i]=1;
	for (int i=1;i<=m-n;i++) vis2[i]=1;
	for (int i=1;i<=m;i++)//如果n小於n-m的時候，這邊會歸零
		if (vis1[i] && vis2[i])
			vis1[i]=vis2[i]=0;
	for (int i=1;i<=m;i++)
		if (vis1[i]) res1*=i;
		else if (vis2[i]) res2*=i;

	printf("%lld", res1/res2);
} */