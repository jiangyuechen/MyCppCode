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
ll pp=1e6+7;
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
ll k;
ll m,n;
int main(){
	freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>k>>m>>n;
    matrix a; 
    a.a[0][0]=0;a.a[0][1]=1;
    a.a[1][0]=n;a.a[1][1]=m; 
    matrix ans;
    ans.a[0][0]=1;ans.a[0][1]=0;
    ans.a[1][0]=0;ans.a[1][1]=1;
    ll b=k-1;
    while(b)
	{
        if(b&1)ans=ans*a;
        a=a*a;
        b/=2;
    }
    ll fk = (ans.a[0][0]+ ans.a[0][1]);
    matrix a1; 
    a1.a[0][0]=0;a1.a[0][1]=1;
    a1.a[1][0]=n;a1.a[1][1]=m; 
    matrix ans1;
    ans1.a[0][0]=1;ans1.a[0][1]=0;
    ans1.a[1][0]=0;ans1.a[1][1]=1;
    ll b1=fk-1;
    while(b1){
        if(b1&1)ans1=ans1*a1;
        a1=a1*a1;
        b1/=2;
    }
    ll fu = (ans1.a[0][0]+ ans1.a[0][1])%pp;
    cout<<fu<<endl;
    return 0;
}
