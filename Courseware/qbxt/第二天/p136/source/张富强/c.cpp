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
const ll pp=1e6 + 7;
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
struct matrix{
	ll a[2][2];
};
matrix operator *(matrix a, matrix b){
	matrix c;
	rep(i,0,1)
		rep(j,0,1){
			c.a[i][j]=0;
			rep(k,0,1)
				c.a[i][j] = (c.a[i][j]+a.a[i][k]*b.a[k][j])%pp;
		}
	return c;
}
ll k,a,b,fn;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>k>>a>>b;
	matrix m;
	m.a[0][0]=a;m.a[0][1]=b;
	m.a[1][0]=1;m.a[1][1]=0;
	matrix ans;
	ans.a[0][0]=1;ans.a[0][1]=0;
	ans.a[1][0]=0;ans.a[1][1]=1;
	int b=k - 1;
	while(b){
		if(b&1)ans=ans*m;
		m=m*m;
		b/=2;
	}
	fn = ans.a[0][0];
	m.a[0][0]=a;m.a[0][1]=b;
	m.a[1][0]=1;m.a[1][1]=0;
	ans.a[0][0]=1;ans.a[0][1]=0;
	ans.a[1][0]=0;ans.a[1][1]=1;
	b = fn - 1;
	while(b){
		if(b&1)ans=ans*m;
		m=m*m;
		b/=2;
	}
	fn = ans.a[0][0];
		cout<<fn;
	
	//O(log B *2^3)
}
