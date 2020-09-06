#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
typedef long long ll;
ll n,mod;
struct mat{
	ll t[105][105];
	void change(int ln,ll val){
		for(int i=1;i<=n;i++)t[ln][i]=((t[ln][i]*val)%mod+mod)%mod;
	}
	void matswap(int ln1,int ln2){
		for(int i=1;i<=n;i++)std::swap(t[ln1][i],t[ln2][i]);
	}
	void mul(int ln1,int ln2,ll val){
		for(int i=1;i<=n;i++)
			t[ln1][i]=((t[ln1][i]+t[ln2][i]*val)%mod+mod)%mod;
	}
};
inline ll read(){
    char p=0;ll r=0;bool w=0;
    for(;p<'0'||p>'9';w|=p=='-',p=getchar());
    for(;p>='0'&&p<='9';r=(r<<1)+(r<<3)+(p^48),p=getchar());
    return w?-r:r;
}
mat I,x;
inline ll inv(ll num){
	ll ans=1,b=mod-2;
	while(b){
		if(b&1)ans=ans*num%mod;
		num=num*num%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read(),mod=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)x.t[i][j]=read();
	for(int i=1;i<=n;i++)I.t[i][i]=1;
	for(int i=1;i<=n;i++){
		if(!x.t[i][i])
			for(int j=i+1;j<=n;j++)
				if(x.t[j][i]){
					I.matswap(i,j);
					x.matswap(i,j);
					break;
				}
		I.change(i,inv(x.t[i][i]));
		x.change(i,inv(x.t[i][i]));
		for(int j=i+1;j<=n;j++){
			I.mul(j,i,-x.t[j][i]);
			x.mul(j,i,-x.t[j][i]);
		}
	}
	for(int i=n-1;i;i--)
		for(int j=i+1;j<=n;j++){
			I.mul(i,j,-x.t[i][j]);
			x.mul(i,j,-x.t[i][j]);
		}
	for(int i=1;i<=n;i++,putchar('\n'))
		for(int j=1;j<=n;j++)
			printf("%lld ",I.t[i][j]%mod);
	return 0;
}
