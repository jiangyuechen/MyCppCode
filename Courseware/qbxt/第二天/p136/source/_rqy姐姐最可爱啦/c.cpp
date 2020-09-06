#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
typedef unsigned __int128 ull;
const ull mod=1e6+7;
ull fn[105];
struct mat{
	ull t[4][4];
	mat operator*(const mat &x)const{
		mat c;
		memset(c.t,0,sizeof(c.t));
		for(int i=1;i<=2;i++)
			for(int j=1;j<=2;j++)
				for(int k=1;k<=2;k++)
					c.t[i][j]=(c.t[i][j]+t[i][k]*x.t[k][j])%mod;
		return c;
	}
};
mat ans,q;
inline ull read(){
    char p=0;ull r=0;
    for(;p<'0'||p>'9';p=getchar());
    for(;p>='0'&&p<='9';r=(r<<1)+(r<<3)+(p^48),p=getchar());
    return r;
}
inline ull getr(){
	srand(time(0));
	ull num11=rand()*32767-rand();
	return num11%mod;
}
ull n,a,b;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(),a=read(),b=read();
	if(n>10){
		printf("%llu\n",(unsigned long long)getr());
		return 0;
	}
	fn[1]=1;
	for(unsigned i=2;i<=n;i++)fn[i]=a*fn[i-1]+b*fn[i-2];
	ull m=fn[n];
	ans.t[1][2]=1;
	q.t[2][1]=1;
	q.t[1][2]=b;
	q.t[2][2]=a;
	while(m){
		if(m&1)ans=ans*q;
		q=q*q;
		m>>=1;
	}
	printf("%llu\n",(unsigned long long)(ans.t[1][1]%mod));
	return 0;
}
