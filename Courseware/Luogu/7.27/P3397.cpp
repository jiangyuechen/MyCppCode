#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 1005

int a[M][M],b[M][M],n,m;

int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		a[x1][y1]++;
		a[x1][y2+1]--;
		a[x2+1][y1]--;
		a[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
		{
			b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
			printf("%d ",b[i][j]);
		}
	return 0;
}
