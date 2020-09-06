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
ll mod=1e6+7;
struct matrix{
    ll a[100][100];
};
ll n;
matrix operator*(matrix a,matrix b){
    matrix c;
    rep(i,1,2){
        rep(j,1,2){
            c.a[i][j]=0;
            rep(k,1,2){
                c.a[i][j]+=(a.a[i][k]%mod*b.a[k][j]%mod)%mod;
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}
matrix ans;
matrix powermod(matrix a,ll b){
    rep(i,1,2){
        rep(j,1,2){
            if(i!=j){
                ans.a[i][j]=0;
            }
        }
        ans.a[i][i]=1;
    }
    while(b){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}
matrix m;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int a,b;
	cin>>n>>a>>b; 
    m.a[1][1]=0;
    m.a[1][2]=1;
    m.a[2][1]=b;
    m.a[2][2]=a;
    m=powermod(m,n-1);
    n=m.a[2][2]%mod;
    m=powermod(m,n-1);
    cout<<m.a[2][2]<<endl;
    return 0;
}

