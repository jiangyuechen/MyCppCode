#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll p,n,m,r;
ll a[110][210];
ll kuaisumi(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y%2) res=res*x%p;
		x=x*x%p;
		y/=2;
	}
	return res;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	m=2*n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		scanf("%lld",&a[i][j]);
		a[i][n+i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j][i])
			{
				for(int k=1;k<=m;k++)
					swap(a[i][k],a[j][k]);
				break;
			}
		}
		r=kuaisumi(a[i][i],p-2);
		for(int j=i;j<=m;j++)
			a[i][j]=a[i][j]*r%p;
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
			r=a[j][i];
			for(int k=i;k<=m;k++)
				a[j][k]=(a[j][k]-r*a[i][k]%p+p)%p;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n+1;j<=m;j++)
			printf("%lld ",a[i][j]);
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
