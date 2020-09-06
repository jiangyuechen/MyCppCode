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
#define N 110000
bool p[N];
int prime[N],tot=0,rec[N],phi[N];
int main(){
	clr(p);
	rep(i,2,100000){
		if(!p[i]){
			prime[++tot]=i;
			rec[i]=i;
		}
		for(int j=1;j<=tot && prime[j]*i<=100000;j++){
			p[prime[j]*i]=1;
			rec[prime[j]*i]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
	rep(i,2,100000)
		if(rec[i]==i)phi[i]=i-1;
		else
		if( (i%(rec[i]*rec[i])==0)
		   phi[i]=phi[i/rec[i]]*rec[i];
		else 
		   phi[i]=phi[i/rec[i]]*(rec[i]-1);
	
	rep(i,2,20)printf("%d : %d\n",i,phi[i]);
}
