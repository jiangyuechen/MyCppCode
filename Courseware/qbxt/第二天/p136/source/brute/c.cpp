#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int mo=1000007;

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int f0=0,f1=1;
	for (int i=2;i<=n;i++)
	{
		int v=f0*b+f1*a;
		f0=f1;
		f1=v;
	}
	n=f1;f0=0,f1=1;
	for (int i=2;i<=n;i++)
	{
		int v=(int)((1ll*f0*b+1ll*f1*a)%mo);
		f0=f1;
		f1=v;
	}
	printf("%d\n",f1);

	return 0;
}
