#include<cstdio>
#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i=a;i<=n;i++)
#define per(i,a,n) for(ll i=n;i>=a;i--)
#define clr(a) memset(a,0,sizeof a);
ll modd,n;
ll  m[120][120],ans[120][120];
ll ksm(ll a,ll b){
	ll ans=1;
	while(b!=0){
		if(b&1){
			ans*=a;
			ans%=modd;
		}
		a=a*a;
		a%=modd;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%ld",&n);
	scanf("%ld",&modd);
	rep(i,1,n){
		rep(j,1,n){
			scanf("%ld",&m[i][j]);
			if(i==j){
				ans[i][j]=1;
			}else{
				ans[i][j]=0;
			}
		}
	}
	rep(i,1,n){
		rep(t,i,n){
			if(m[t][i]){
				rep(k,1,n){
					swap(m[i][k],m[t][k]);
					swap(ans[i][k],ans[t][k]);
				}
				break;
			}
		}
		ll kk=ksm(m[i][i],modd-2);
		rep(j,1,n){
			m[i][j]*=kk;
			m[i][j]%=modd;
			ans[i][j]*=kk;
			ans[i][j]%=modd;
		}
		rep(j,1,n){
			if(j!=i){
				ll kkk=m[j][i];
				rep(k,1,n){
					m[j][k]=(m[j][k]-kkk*m[i][k]%modd+modd)%modd;
					ans[j][k]=(ans[j][k]-kkk*ans[i][k]%modd+modd)%modd;
				}	
			}
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			printf("%ld ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}

