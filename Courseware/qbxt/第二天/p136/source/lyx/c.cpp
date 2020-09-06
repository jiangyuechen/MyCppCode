#include<iostream>
#include<cstdio>
using namespace std;

unsigned long long n,a,b,m;

const unsigned long long mod=1000007;

inline unsigned long long fn(unsigned long long n,unsigned long long a,unsigned long long b)
{
	if(n==0)
	{
		m=0;
		return m;
	}
	if(n==1)
	{
		m=1;
		return m;
	}
	else m=a*fn(n-1,a,b)+b*fn(n-2,a,b);
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>a>>b;
	unsigned long long e=fn(n,a,b);
	unsigned long long ans=fn(e,a,b);
	ans=ans%mod;
	cout<<ans<<endl;
	return 0;
}
