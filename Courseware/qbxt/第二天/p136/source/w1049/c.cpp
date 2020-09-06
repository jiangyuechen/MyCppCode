/*
广义斐波那契循环节啊!!!!!没学过又看不懂网上代码....!!!
*/
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
const int p=1e6+7;
LL n,a,b;
struct Matrix {
	const static int MAXSIZE=3;
	LL num[MAXSIZE+1][MAXSIZE+1];
	Matrix(int a=0) {
		memset(num,0,sizeof(num));
		for(int i=1; i<=MAXSIZE; i++)
			num[i][i]=a;
	}
	Matrix operator*(const Matrix& b) {
		Matrix res;
		for(int k=1; k<=MAXSIZE; k++)
			for(int i=1; i<=MAXSIZE; i++)
				for(int j=1; j<=MAXSIZE; j++)
					(res.num[i][j]+=(num[i][k]*b.num[k][j])%p)%=p;
		return res;
	}
	Matrix operator^(LL b) {
		Matrix res(1);
		Matrix base=*this;
		while(b) {
			if(b&1)res=res*base;
			base=base*base;
			b>>=1;
		}
		return res;
	}
	void clear() {
		memset(num,0,sizeof(num));
	}
} A,T;
LL f(LL n) {
	if(n==0)return 0;
	else if(n==1)return 1;
	A.clear(),T.clear();
	A.num[1][1]=a;	//f(i)=af(i-1)+bf(i-2)
	A.num[1][2]=b;	//	a	b 		f(i-1)		f(i)
	A.num[2][1]=1;	//	1	0 	*	f(i-2)	=	f(i-1)
	T.num[2][1]=0;	//	f(0)
	T.num[1][1]=1;	//	f(1)
	return ((A^(n-1))*T).num[1][1];
}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld%lld%lld",&n,&a,&b);
	printf("%lld",f(f(n)));
	return 0;
}
