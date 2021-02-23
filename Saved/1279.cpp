#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 105;
int F, V;
int a[MAXN][MAXN], f[MAXN][MAXN];
// f[i][j] 表示考虑完前 i 朵花，且最后一朵花插在了第 j 个位置上
// 所能获得的最大美学值。
vector<int> path[MAXN][MAXN];
int main()
{
	cin >> F >> V;
	for (int i = 1; i <= F; i++)
		for (int j = 1; j <= V; j++)
			cin >> a[i][j];
	memset(f, 128, sizeof(f));
	for (int i = 1; i <= V - F; i++)
	{
		f[1][i] = a[1][i];
		path[1][i].push_back(i);
	}
	for (int i = 2; i <= F; i++)
		for (int j = i; j <= V - F + i; j++)
			for (int k = 1; k < j; k++)
				if (f[i][j] < f[i - 1][k] + a[i][j])
				{
					f[i][j] = f[i - 1][k] + a[i][j];
					path[i][j] = path[i - 1][k];
					path[i][j].push_back(j);
				}
	int ans = -2147483647, stt;
	for (int i = F; i <= V; i++)
	{
		if (ans < f[F][i])
		{
			ans = f[F][i];
			stt = i;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= F; i++)
		cout << path[F][stt][i - 1] << ' ';
	system("pause");
	return 0;
}