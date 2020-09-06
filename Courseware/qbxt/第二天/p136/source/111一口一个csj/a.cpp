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
LL pow(LL a,LL p,LL mod)
{
	LL s=1;
	while(p)
	{
		if(p&1)  s=s*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return s;
}
const int N=200;
LL n,mod,a[N][N],s[N][N];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();  mod=read();
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)  a[i][j]=read();
	for(int i=1;i<=n;i++)  s[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		int t=i;
		while(a[t][i]==0&&t<=n)  t++;
		for(int j=1;j<=n;j++)
		{
			swap(a[t][j],a[i][j]);
			swap(s[t][j],s[i][j]);
		}
		LL p=pow(a[i][i],mod-2,mod);
		for(int j=1;j<=n;j++)
		{
			a[i][j]=a[i][j]*p%mod;
			s[i][j]=s[i][j]*p%mod;
		}
		for(int j=1;j<=n;j++)
		{
			if(i==j)  continue;
			LL p=a[j][i];
			for(int k=1;k<=n;k++)
			{
				a[j][k]=((a[j][k]-p*a[i][k])%mod+mod)%mod;
				s[j][k]=((s[j][k]-p*s[i][k])%mod+mod)%mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	      cout<<s[i][j]<<" ";
	    cout<<"\n";
	}
	fclose(stdin);  fclose(stdout);;
	return 0;
}
