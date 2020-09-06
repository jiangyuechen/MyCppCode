#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#define mod 1000007
using namespace std;
struct Matrix
{
    long long a[101][101];
    Matrix()
    {
    	memset(a,0,sizeof(a));
	}
	inline void set()
	{
		for(int i=1;i<=2;i++)
		a[i][i]=1;
	}
}ans,aa;
Matrix start;
Matrix fuck_zhx;
Matrix end;
Matrix operator *(const Matrix &x,const Matrix &y)
{
	Matrix res;
	memset(res.a,0,sizeof(res.a));
	for(int k=1;k<=2;k++)
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return res;
}
Matrix quickpow(Matrix ans,long long b) 
{
	Matrix anss;
	anss.set(); 
    while(b)
    {
        if(b&1)
        anss=anss*ans;
        ans=ans*ans;
        b>>=1;
    }
    return anss;
}
inline void init(long long a,long long b)
{
    aa.a[1][1] = 0;
    aa.a[1][2] = b;
    aa.a[2][1] = 1;
    aa.a[2][2] = a;
}
int main()
{
	freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
	long long n,A,B;
	scanf("%lld%lld%lld",&n,&A,&B);
	if(n <= 1)
	{
		printf("%lld",n);
		return 0;
	}
	init(A,B);
	start.a[1][1] = 0;
	start.a[1][2] = 1;
	end = quickpow(aa,n-1);
	fuck_zhx = start * end;
	long long zhx_rqy = fuck_zhx.a[1][2];
	Matrix rqy_zhx = quickpow(aa,zhx_rqy - 1);
	Matrix rqy_zhx_99 = start * rqy_zhx;
	printf("%lld",rqy_zhx_99.a[1][2]);
	return 0;
}
