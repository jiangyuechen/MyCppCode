#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	for(; !isdigit(ch); ch=getchar())
		if(ch=='-')
			f=-1;
	for(; isdigit(ch); ch=getchar())
		x=x*10+ch-'0';
	return x*f;
}

#define int long long
const int mod=1e6+7;
int K,x,y;
struct Matrix
{
	int m[101][101],N;
	Matrix()
	{
		memset(m,0,sizeof(m));
		N = 2;
	}
	Matrix operator*(const Matrix &rhs)const
	{
		Matrix ans;
		for(int k=1; k<=N; k++)
			for(int i=1; i<=N; i++)
				for(int j=1; j<=N; j++)
					(ans.m[i][j]+=1ll*m[i][k]*rhs.m[k][j] % mod)%=mod;
		return ans;
	}
};
Matrix fastpow(Matrix a, int p)
{
	Matrix base;
	for(int i=1; i<=base.N; i++)
		base.m[i][i]=1;
	while(p)
	{
		if(p&1)
			base=base*a;
		a=a*a;
		p>>=1;
	}
	return base;
}
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	K=read(),x=read(),y=read();
	Matrix a;
	a.m[1][1]=x;
	a.m[1][2]=1;
	a.m[2][1]=y;
	a.m[2][2]=0;
	a=fastpow(a,K-1);
	Matrix b;
	b.m[1][1]=x;
	b.m[1][2]=1;
	b.m[2][1]=y;
	b.m[2][2]=0;
	b=fastpow(b,a.m[1][1]-1);
	cout<<b.m[1][1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 1 1

1
*/
