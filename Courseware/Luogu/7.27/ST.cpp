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

#define M 100005

int f[17][M],b[M],n,m;

void bulid()
{
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)f[0][i]=read();
	bulid();
	for(int i=1;i<=16;i++)b[1<<i]++;
	for(int i=1;i<=n;i++)b[i]+=b[i-1];
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read(),len=r-l+1;
		printf("%d\n",max(f[b[len]][l],f[b[len]][r+1-(1<<b[len])]));
	}
	return 0;
}
