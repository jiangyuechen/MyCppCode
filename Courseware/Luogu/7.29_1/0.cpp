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

#define M 1000005

int n,a[M],b[M],c[M],d[M],cnt;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=b[i]=read();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(b[i+1]==b[i])
			continue;
		c[++cnt]=b[i];
	}
	for(int i=1;i<=n;i++)
		d[i]=(lower_bound(c+1,c+cnt+1,a[i])-c);
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
	return 0;
}
