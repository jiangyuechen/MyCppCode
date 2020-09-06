#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll p=1e6+7;
ll n,a,b;
struct node
{
	ll a[4][4];
}f,a1,a2;
node operator *(node a,node b)
{
	node c;
	for(int i=1;i<=2;i++)
	  for(int j=1;j<=2;j++)
		{
			c.a[i][j]=0;
			for(int k=1;k<=2;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j];
		}
	return c;
}
node operator %(node a,ll mod)
{
	for(int i=1;i<=2;i++)
	 for(int j=1;j<=2;j++)
	  a.a[i][j]=(a.a[i][j]+mod)%mod;
	return a;
}
node kuai1(node x,ll y)
{
	node sum;
	sum.a[1][1]=sum.a[2][2]=1;
	sum.a[1][2]=sum.a[2][1]=0;
	while(y)
	{
		if(y%2) sum=sum*x;
		x=x*x;
		y/=2;
	}
	return sum;
}
node kuai2(node x,ll y)
{
	node sum;
    sum.a[1][1]=sum.a[2][2]=1;
	sum.a[1][2]=sum.a[2][1]=0;
	while(y)
	{
		if(y%2) sum=sum*x%p;
		x=x*x%p;
		y/=2;
	}
	return sum;
}
ll kuaisumi1(ll x,ll y)
{
	ll sum=1;
	while(y)
	{
		if(y%2) sum=sum*x;
		x=x*x;
		y/=2;
	}
	return sum;
}
ll kuaisumi2(ll x,ll y)
{
	ll sum=1;
	while(y)
	{
		if(y%2) sum=sum*x%p;
		x=x*x%p;
		y/=2;
	}
	return sum%p;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld%lld%lld",&n,&a,&b);
	if(b!=0)
	{
	f.a[1][1]=a;f.a[1][2]=b;
	f.a[2][1]=1;f.a[2][2]=0;
	node r=kuai1(f,n-1);
	n=r.a[1][1];
	r=kuai2(f,n-1);
	cout<<r.a[1][1];
	}
	else
	{
		ll r=kuaisumi1(a,n-1);
		ll ans=kuaisumi2(a,r-1);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
