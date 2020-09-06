#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
const int Maxn = 110;
int p,n;

#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
#define clr(a) memset(a,0,sizeof(a))

ll pow(ll a,ll b){
	ll ans = 1;
	while(b){
		if(b&1)ans = ans*a%p;
		a = a*a%p;
		b>>=1;
	}
	return ans;
}

void exgcd(int a,int b,int&d,int&x,int&y){
	if(!b){
		x = 1;
		y = 0;
		d = a;
		return;
	}
	exgcd(b,a%b,d,y,x);
	y = y-a/b*x;
}
ll inv2(int n){
	int x,y,d;exgcd(n,p,d,x,y);
	return (x+p)%p;
}

ll inv(int n){return pow(n,p-2);};
ll a[Maxn][Maxn],ans[Maxn][Maxn];
void inv(){
	rep(i,1,Maxn-1)rep(j,1,Maxn-1)ans[i][j] = (i==j)?1:0;
	rep(i,1,n){
		int t;
		rep(j,i,n)if(a[j][i])
		{t = j;break;}
		rep(j,1,n)swap(a[t][j],a[i][j]),swap(ans[t][j],ans[i][j]);
		ll k1 = inv2(a[i][i]);
//		rep(j,1,n)a[i][j]/=k1,ans[i][j]/=k1;
		rep(j,1,n)a[i][j]=a[i][j]*k1%p,ans[i][j]=ans[i][j]*k1%p;
		rep(j,1,n)if(i!=j){
			ll k2 = a[j][i];
			rep(k,1,n)a[j][k]-=a[i][k]*k2,ans[j][k]-=ans[i][k]*k2;
		}
	}
}

ll work(ll n){
	while(n < 0)n+=p;
	while(n > p)n-=p;
	return n;
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout); 
	cin >> n >> p;
	rep(i,1,n)rep(j,1,n)cin >> a[i][j];
	inv();
	rep(i,1,n){
		rep(j,1,n)cout << work(ans[i][j]) << ' ';
		cout << endl;
	}
return 0;
}
