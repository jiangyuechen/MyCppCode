#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int mo=1000000007;

int mul(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=(int)(1ll*ans*a%mo);
		a=(int)(1ll*a*a%mo);
		b>>=1;
	}
	return ans;
}

int C(int n,int m)
{
	int a=1,b=1,c=1;
	for (int i=1;i<=n;i++)
		a=(int)(1ll*a*i%mo);
	for (int i=1;i<=m;i++)
		b=(int)(1ll*b*i%mo);
	for (int i=1;i<=n-m;i++)
		c=(int)(1ll*c*i%mo);
	return (int)(1ll*a*mul(b,mo-2)%mo*mul(c,mo-2)%mo);
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d %d\n",C(n,k-1),C(n-1,k-1));

	return 0;
}

