#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
int a[105][105], b[105][105],d[105][105],n, p, k;
using namespace std;
void inpu()
{
	scanf("%d%d", &n, &p);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &b[i][j]);
		}
}
void ksm(int ys[105][105], int cs, int mo, int size_ys)
{
	while (cs > 1)
	{
		if (cs & 1)
		{
			for(int i=1;i<=n;i++)
				for (int j = 1; j <= n; j++)
				{
					d[i][j] = 0;
					for (int k = 1; k <= n; k++)
					{
						d[i][j] += ys[i][k] * d[k][j];
						d[i][j] %= mo;
					}
                    a[i][j]=d[i][j];
				}
		}
		cs >>= 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = 0;
				for (int k = 1; k <= n; k++)
				{
					d[i][j] += ys[i][k] * ys[k][j];
					d[i][j] %= mo;
				}
                ys[i][j]=d[i][j];
			}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	inpu();
	ksm(b,p-2,p,n);
	return 0;
}
