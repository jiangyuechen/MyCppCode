#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)

ll pp=1000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}

struct matrix{
	int a[2][2];
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
int k;
int main(){
	freopen("a.in","r",stdin);  
	freopen("a.out","w",stdout);  
	cin>>k;
	int q;
	cin>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;i++){
			cin>>a.a[i][j];
		}
	}
	matrix a;
	a.a[0][0]=0;a.a[0][1]=1;
	a.a[1][0]=x;a.a[1][1]=y;
	matrix ans;
	ans.a[0][0]=1;ans.a[0][1]=0;
	ans.a[1][0]=0;ans.a[1][1]=1;
	int b=k-2;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b/=2;
	}
	int fk = (x*ans.a[0][0]+ y*ans.a[0][1])%pp;
	cout<<fk;
	return 0;
}
