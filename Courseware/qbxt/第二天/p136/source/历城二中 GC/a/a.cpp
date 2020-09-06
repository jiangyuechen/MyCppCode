#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long LL;
const LL N=101;
LL n,p,ans,x;
LL s[N][N*2];
LL ksm(LL u,LL v)
{
	ans=1;
	while(v)
	{
		if(v&1)
		{
			ans=ans*u%p;
			u=u*u%p;
			v=v/2;
		}
	}
	return ans;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&s[i][j]);
			s[i][n+i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[j][i])
			{
				for(int k=1;k<=2*n;k++)
				{
					 swap(s[i][k],s[j][k]);
				}
				break;
			}
			else
			{
				cout<<"No Solution";
				return 0;
			}
		}
		x=ksm(s[i][i],p-2);//ÇóÄæ
		for(int j=i;j<=2*n;j++)
		{
			s[i][j]=s[i][j]*x%p;
		}
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				x=s[j][i];
				for(int k=i;k<=2*n;k++)
				{
					s[j][k]=(s[j][k]-x*s[i][k]%p+p)%p;
				}
			}
		}
	}
	for(int i=1;i<=n;i++,puts(""))
	{
		for(int j=n+1;j<=2*n;j++)
		{
			printf("%lld ",s[i][j]);
		}
	}
	return 0;
}
