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

int size;

bool erfen(int x)
{
	int l=0,r=size;
	while (l+1!=r)
	
		int m=

int bsgs(int a,int b,int p)
{
	int size = sqrt(p);
	
	int nowv=1;
	for (int i=1;i<=size;i++)
	{
		nowv = (long long)nowv * a%p;
		z[i] = nowv;
		if (z[i] == b) return i;
	}
	sort(z+1,z+size+1);
	for (int i=2;(i-1)*size+1 <= p;i++)
	{
		int y = (long long)b * kuaisumi(kuaisumi(a,size*(i-1),p),p-2,p);
		if(erfen(y))
		{
			for (int j=(i-1)*size+1;j<=i*size;j++)
			    if(kuaisumi(a,j,p) == b) return j;
		}
	}
	return -1;
	    
}
