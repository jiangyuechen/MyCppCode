#include<cstdio>
#define LL long long
#define R register
const int p=1e9+7,N=1e5+1;
inline void read(int &x) {
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
}
inline int getinv(int a) {
	LL base=a,res=1;
	int b=p-2;
	while(b) {
		if(b&1)res=res*base%p;
		base=base*base%p;
		b>>=1;
	}
	return res;
}
int n,k;
LL a,b,jc[N],inv[N];
inline void init() {
	jc[0]=1;
	inv[0]=1;
	for(R int i=1; i<=n; ++i)jc[i]=jc[i-1]*i%p;
	inv[n]=getinv(jc[n]);
	for(R int i=n; i>=2; --i)inv[i-1]=inv[i]*i%p;
}
inline LL C(int n,int m) {
	return jc[n]*inv[m]%p*inv[n-m]%p;
}
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n),read(k);
	init();
	a=C(n,k-1);
	b=a*(n-k+1)%p*getinv(n)%p;
	printf("%lld %lld",a,b);
}
