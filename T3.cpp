#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 105;
int t;
int n, m;
char a[MAXN][MAXN];
int main()
{
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i] + 1;
		int ans_1 = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] == '1')
					ans_1 += 3;
		printf("%d\n", ans_1);
		if (a[n][m] == '1') // 将要还原的1作为2*2矩阵右下角（最后一排最后一列的数字）（特判）
		{
			printf("%d %d %d %d %d %d\n", n, m, n - 1, m, n, m - 1);	 // n-1,m-1
			printf("%d %d %d %d %d %d\n", n, m, n - 1, m, n - 1, m - 1); // n,m-1
			printf("%d %d %d %d %d %d\n", n, m, n, m - 1, n - 1, m - 1); // n-1,m
		}
		for (int i = 1; i < n; i++) // 将要还原的1作为2*2矩阵左下角（最后一排）（特判）
			if (a[i][m] == '1')
			{
				printf("%d %d %d %d %d %d\n", i, m, i + 1, m - 1, i, m - 1); // i+1,m
				printf("%d %d %d %d %d %d\n", i, m, i + 1, m, i + 1, m - 1); // i,m-1
				printf("%d %d %d %d %d %d\n", i, m, i + 1, m, i, m - 1);	 // i+1,m-1
			}
		for (int i = 1; i < m; i++) // 将要还原的1作为2*2矩阵右上角（最后一列）（特判）
			if (a[n][i] == '1')
			{
				printf("%d %d %d %d %d %d\n", n, i, n - 1, i, n - 1, i + 1); // n,i+1
				printf("%d %d %d %d %d %d\n", n, i, n, i + 1, n - 1, i + 1); // n-1,i
				printf("%d %d %d %d %d %d\n", n, i, n - 1, i, n, i + 1);	 // n-1,i+1
			}
		for (int i = 2; i <= n; i++) // 将要还原的1作为2*2矩阵左上角
			for (int j = 2; j <= m; j++)
				if (a[i - 1][j - 1] == '1')
				{
					printf("%d %d %d %d %d %d\n", i - 1, j - 1, i, j - 1, i - 1, j); // i,j
					printf("%d %d %d %d %d %d\n", i - 1, j - 1, i - 1, j, i, j);	 // i-1,j
					printf("%d %d %d %d %d %d\n", i - 1, j - 1, i, j, i, j - 1);	 // i,j-1
				}
	}
	return 0;
}