#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1000010
#define DEBUG printf("%d %s\n",__LINE__,__FUNCTION__)
#define APART puts("---------------")
#define int unsigned long long
using namespace std;

const int mod = 1e6+7;

inline int read(){
	char c=getchar();int num=0;bool b=0;
	for(;c<'0'||c>'9';b|=(c=='-'),c=getchar());
	for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+(c^'0'),c=getchar());
	return b?-num:num;
}

struct M{
	int m[3][3];
};

M operator *(const M &a,const M &b){
	M c;
	memset(c.m,0,sizeof c.m);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			for(int k=1;k<=2;k++){
				c.m[i][j]=c.m[i][j]+a.m[i][k]*b.m[k][j];
			}
		}
	}
	return c;
}

M operator /(const M &a,const M &b){
	M c;
	memset(c.m,0,sizeof c.m);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			for(int k=1;k<=2;k++){
				c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
			}
		}
	}
	return c;
}

int n,x,y;

M a;
M ans;
M a_;
M ans_;

signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();
	x=read();
	y=read();
	ans.m[1][1]=1;
	ans.m[2][2]=1;
	a.m[1][1]=x;
	a.m[1][2]=y;
	a.m[2][1]=1;
	while(n){
		if(n&1)
			ans=ans*a;
		a=a*a;
		n>>=1;
	}
//	printf("%lld\n",ans.m[2][1]);
	int b=ans.m[2][1];
	ans_.m[1][1]=1;
	ans_.m[2][2]=1;
	a_.m[1][1]=x;
	a_.m[1][2]=y;
	a_.m[2][1]=1;
	while(b){
		if(b&1)
			ans_=ans_/a_;
		a_=a_/a_;
		b>>=1;
	}
	printf("%lld\n",ans_.m[2][1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
