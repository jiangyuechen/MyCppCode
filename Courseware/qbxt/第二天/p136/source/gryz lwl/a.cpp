#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	for(; !isdigit(ch); ch=getchar())
		if(ch=='-')
			f=-1;
	for(; isdigit(ch); ch=getchar())
		x=x*10+ch-'0';
	return x*f;
}
#define int long long
const int N=405;
int n,m,mod;
int f[N][N<<1];
int r,ret;
int ksm(int u,int v)
{
	ret=1;
	while(v)
	{
		if(v&1)ret=ret*u%mod;
		u=u*u%mod;
		v>>=1;
	}
	return ret;
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read(),mod=read();
	m=n*2;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; j++)
			f[i][j]=read();
		f[i][n+i]=1;
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=i; j<=n; j++)
			if(f[j][i])
			{
				for(int k=1; k<=m; k++)
					swap(f[i][k],f[j][k]);
				break;
			}
		if(!f[i][i])
		{
			puts("No Solution");
			return 0;
		}
		r=ksm(f[i][i],mod-2);
		for(int j=i; j<=m; ++j)
			f[i][j]=f[i][j]*r%mod;
		for(int j=1; j<=n; ++j)
			if(j!=i)
			{
				r=f[j][i];
				for(int k=i; k<=m; ++k)
					f[j][k]=(f[j][k]-r*f[i][k]%mod+mod)%mod;
			}
	}
	for(int i=1; i<=n; ++i,puts(""))
		for(int j=n+1; j<=m; ++j)
			cout<<f[i][j]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 5
1 2
3 4

3 1
4 2
*/
