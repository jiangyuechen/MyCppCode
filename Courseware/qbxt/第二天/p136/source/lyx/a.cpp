#include<iostream>
#include<cstdio>
#define LL long long
#define N 405
using namespace std;

int n,m;

unsigned long long mod;

int f[N][N<<1],r,ans;

inline int read()
{
	int ret=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-f;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int qpow(int x,int k)
{
	int r=1;
	while(k)
	{
		if(k&1) r=1LL*r*x%mod;
		x=1LL*x*x%mod;
		k>>=1;
	}
	return r;
}

inline void gao()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<=n; j++)
			if(f[j][i])
			{
				if(j!=i) for(int k=1; k<=m; k++) swap(f[i][k],f[j][k]);
				break;
			}
		if(!f[i][i])
		{
			puts("No Solution");
			return;
		}
		r=qpow(f[i][i],mod-2);
		for(int j=i; j<=m; j++) f[i][j]=1LL*f[i][j]*r%mod;
		for(int j=1; j<=n; j++)
			if(j!=i)
			{
				r=f[j][i];
				for(int k=i; k<=m; k++)
					f[j][k]=(f[j][k]-1LL*r*f[i][k]%mod+mod)%mod;
			}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=n+1; j<=m; j++) printf("%d ",f[i][j]);
		puts("");
	}
	return;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();
	mod=read();
	m=n<<1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) f[i][j]=read();
		f[i][n+i]=1;
	}
	gao();
	return 0;
}
