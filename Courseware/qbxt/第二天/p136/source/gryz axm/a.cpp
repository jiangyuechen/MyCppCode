#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int n,p;
struct matrix
{
	int a[200][200];
	void change1(int x,int y)
	{
		for(int i=0;i<n;++i) swap(a[x][i],a[y][i]);
	}
	void change2(int x,int k)
	{
		for(int i=0;i<n;++i)
			a[x][i]=(((a[x][i]*k)%p)+p)%p;
	}
	void change3(int x,int y,int k)
	{
		for(int i=0;i<n;++i)
			a[x][i]=(((a[x][i]+a[y][i]*k%p)%p)+p)%p;
	}
} a,b;
int ksm(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=(ans*x)%p;
		x=(x*x)%p;
		y>>=1;
	}
	return ans;
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	for(int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			scanf("%lld", &a.a[i][j]);
	for(int i=0;i<n;++i)b.a[i][i]=1;
	for(int i=0;i<n;++i)
	{
		if(!a.a[i][i])
			for(int j=i;j<n;++j)
				if(a.a[j][i])
				{
					b.change1(i,j);
					a.change1(i,j);
					break;
				}
		b.change2(i,ksm(a.a[i][i],p-2));
		a.change2(i,ksm(a.a[i][i],p-2));
		for(int j=i+1;j<n;++j)
		{
			b.change3(j,i,-a.a[j][i]);
			a.change3(j,i,-a.a[j][i]);
		}
	}
	for(int i=n-2;i>=0;--i)
		for(int j=i+1;j<n;++j)
		{
			b.change3(i,j,-a.a[i][j]);
			a.change3(i,j,-a.a[i][j]);
		}
	for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<n;++j)
			printf("%lld ",b.a[i][j]);
	return 0;
}
