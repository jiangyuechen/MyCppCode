#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
ld eps=1e-9;
ll pp=1000000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}
ll read(){
	ll ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
//head

memset(not_prime,0,sizeof(not_prime));

for (int i=2;i<=n;i++)
{
	if(!not_prime[i]) 
	{
		prime[++ prime_cnt] = i;
		phi[i] = i-1;
		mu[i] = -1;
	}
	for (int j=1;j<=prime_cnt;j++)
	{
		int x = i * prime[j];
		if (x>n) break;
		
		not_prime[x] = true;
		phi[x] = phi[i] * phi[prime[j]];
		mu[x] = mu[i] * mu[prime[j]];
		
		if (i % prime[j] == 0)
		{
			phi[x] = phi[i] * prime[j];
			mu[x] = 0;
			break;
		 } 
	}
}
