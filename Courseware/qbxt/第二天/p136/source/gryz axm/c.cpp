#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int mod=1e6+7;
struct node
{
	ll a[2][2];
}ans,ss;
node mul(node a,node b)
{
	node c={};
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
	return c;
}
void fpow(ll n)
{
	while(n)
	{
		if(n&1)ans=mul(ans,ss);
		ss=mul(ss,ss);
		n>>=1;
	}
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ll n,a,b;
	cin>>n>>a>>b;
	ans.a[0][0]=1;
	ss.a[0][0]=a,ss.a[0][1]=b;
	ss.a[1][0]=1;
	fpow(n-1);
	n=ans.a[0][0];
	memset(ss.a,0,sizeof(ss.a));
	memset(ans.a,0,sizeof(ans.a));
	ans.a[0][0]=1;
	ss.a[0][0]=a,ss.a[0][1]=b;
	ss.a[1][0]=1;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	fpow(n-1);
	cout<<ans.a[0][0]<<"\n";
	return 0;
}
