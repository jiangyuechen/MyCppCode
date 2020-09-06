#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=110;

int n,p,z[maxn][2*maxn];

int mul(int a,int b,int p)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=(long long)ans*a%p;
		b>>=1;
		a=(long long)a*a%p;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&p);
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			scanf("%d",&z[a][b]);
	for (int a=1;a<=n;a++)
		z[a][n+a]=1;
	for (int a=1;a<=n;a++)
	{
		int px=-1;
		for (int b=a;b<=n;b++)
			if (z[b][a])
			{
				px=b;
				break;
			}
		if (px==-1)
		{
			printf("-1\n");
			return 0;
		}
		for (int b=1;b<=2*n;b++)
			swap(z[a][b],z[px][b]);
		for (int b=a+1;b<=n;b++)
		{
			int ratio=(long long)z[b][a]*mul(z[a][a],p-2,p)%p;
			for (int c=1;c<=2*n;c++)
				z[b][c] = (z[b][c]-(long long)z[a][c]*ratio%p+p)%p;
		}
	}
	for (int a=n;a>=1;a--)
		for (int b=a-1;b>=1;b--)
		{
			int ratio=(long long)z[b][a]*mul(z[a][a],p-2,p)%p;
			for (int c=1;c<=2*n;c++)
				z[b][c] = (z[b][c]-(long long)z[a][c]*ratio%p+p)%p;
		}
	for (int a=1;a<=n;a++)
	{
		int ratio=mul(z[a][a],p-2,p);
		for (int b=1;b<=2*n;b++)
			z[a][b] = (long long)z[a][b]*ratio%p;
	}
	for (int a=1;a<=n;a++)
		for (int b=n+1;b<=2*n;b++)
			printf("%d%c",z[a][b],b==2*n?'\n':' ');

	return 0;
}
