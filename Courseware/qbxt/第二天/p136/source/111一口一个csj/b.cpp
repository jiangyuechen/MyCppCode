#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')  f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
const LL mod=1e9+7;
LL n,k,a,b,x,y,o[3000000];
LL gcd(LL a,LL b)
{
	if(b==0)  return a;
	return gcd(b,a%b);
}
LL pow(LL a,LL p,LL mod)
{
	LL s=1;
	while(p)
	{
		if(p&1)  s=s*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return s;
}
LL C(LL a,LL b)
{
	if(b>a)  return 0;
	return o[a]*pow(o[b],mod-2,mod)%mod*pow(o[a-b],mod-2,mod)%mod;
}
LL lucas(LL a,LL b)
{
	if(!b)  return 1;
	return lucas(a/mod,b/mod)*C(a%mod,b%mod)%mod;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	x=n=read()%mod;  y=k=read()%mod-1;
	LL d=gcd(n,k)%mod;
	n=n/d%mod;  k=k/d%mod;
	a=n;  b=n-k;
	o[0]=1;
	for(int i=1;i<=n;i++)  o[i]=o[i-1]*i;
	for(int i=1;i<=n;i++)
	while(lucas(a,b)<x||lucas(a-1,b)<y)
	{
		a=(a+n)%mod;  b=(b+n-k)%mod;
	}
	cout<<a<<" "<<b;
	fclose(stdin);  fclose(stdout); 
	return 0;
}
