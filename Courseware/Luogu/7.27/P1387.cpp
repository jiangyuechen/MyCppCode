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

int a[105][105],n,m,ans;

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x=read();
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+x;
		}
	for(int l=1;l<=min(n,m);l++)
	{
		int b=0;
		for(int i=l;i<=n&&b==0;i++)
			for(int j=l;j<=m&&b==0;j++)
				if(a[i][j]-a[i-l][j]-a[i][j-l]+a[i-l][j-l]==l*l)
					b=1;
		if(b==1)ans=l;
	}
	printf("%d\n",ans);
	return 0;
}
