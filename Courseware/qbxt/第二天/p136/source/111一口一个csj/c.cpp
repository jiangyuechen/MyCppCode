#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')  f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
struct matrix
{
	LL m[2][2];
};
const int mod=1e6+7;
matrix a,s;
LL n,a1,b1;
matrix X(matrix a,matrix b)
{
	matrix c;
	for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	c.m[i][j]=0;
	  	for(int k=1;k<=1;k++)
	  	  c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][i]%mod)%mod;
	  }
	return c;
}
matrix X1(matrix a,matrix b)
{
	matrix c;
	for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++)
	  {
	  	c.m[i][j]=0;
	  	for(int k=1;k<=1;k++)
	  	  c.m[i][j]+=a.m[i][k]*b.m[k][i];
	  }
	return c;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();  a1=read()%mod;  b1=read()%mod;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	s.m[0][0]=s.m[1][1]=1;
	a.m[0][0]=0;  a.m[0][1]=b1;
	a.m[1][0]=1;  a.m[1][1]=a1;
	while(n)
	{
		if(n&1)  s=X1(s,a);
		a=X1(a,a);
		n>>=1;
	}
	n=s.m[1][0];
	s.m[0][0]=s.m[1][1]=1;
	s.m[0][1]=s.m[1][0]=0;
	a.m[0][0]=0;  a.m[0][1]=b1;
	a.m[1][0]=1;  a.m[1][1]=a1;
	while(n)
	{
		if(n&1)  s=X(s,a);
		a=X(a,a);
		n>>=1;
	}
	cout<<s.m[1][0];
	fclose(stdin);  fclose(stdout);
}
