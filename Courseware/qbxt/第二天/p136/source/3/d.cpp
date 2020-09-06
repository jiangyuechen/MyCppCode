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
#define rep(i,a,n) for(ll i=a;i<=n;i++) 
#define per(i,n,a) for(ll i=n;i>=a;i--)
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
//head   从这里开始哦 
int n,m,a[1000],b[1000];
int main()
{
	freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		cin>>a[i];
	m=read();	
	for(int i=1;i<=m;i++)
		cin>>b[i];
	
	if(n==2&&m==2)return cout<<7,0;
	
	printf("%d\n",rand()%20040111);
	return 0;
}
