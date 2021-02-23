#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXN 1000001
#define MAXM 110
#define INF 1100000000
#define R register int
using namespace std;
struct zt
{
	int x, y, t;
} bf;
struct question
{
	int x, y;
} q[MAXN];
queue<zt> que;
int n, m, stx, sty, edx, edy, cnt, ans = INF, yao[MAXM][MAXM], nowx, nowy, nowt, cost[MAXM][MAXM][MAXM]; //x,y,key num
char mp[MAXM][MAXM];
int mx[MAXM] = {0, 0, 1, -1};
int my[MAXM] = {1, -1, 0, 0};
inline zt make(int x, int y, int t)
{
	zt a;
	a.x = x, a.y = y, a.t = t;
	return a;
}
inline void baoli(int num, int tms)
{
	if (num == cnt + 1)
	{
		memset(cost, -1, sizeof(cost));
		cost[stx][sty][0] = 0;
		que.push(make(stx, sty, 0));
		while (!que.empty())
		{
			bf = que.front();
			que.pop();
			for (int i = 0; i < 4; i++)
			{
				nowx = bf.x + mx[i];
				nowy = bf.y + my[i];
				nowt = bf.t;
				if (nowx < 1 || nowy < 1 || nowx > n || nowy > n || mp[nowx][nowy] == '#' || cost[nowx][nowy][nowt] != -1)
					continue;

				if (nowt == yao[nowx][nowy] - 1)
				{
					nowt++;
				}
				cost[nowx][nowy][nowt] = cost[bf.x][bf.y][bf.t] + 1;
				que.push(make(nowx, nowy, nowt));
			}
		}
		if (cost[edx][edy][m] != -1)
			ans = min(ans, tms + cost[edx][edy][m]);
	}
	if (num ^ (cnt + 1))
	{
		mp[q[num].x][q[num].y] = '#';
		baoli(num + 1, tms);

		mp[q[num].x][q[num].y] = '.';
		baoli(num + 1, tms + 1);
	}
}
signed main()
{
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int o = 1; o <= n; o++)
		{
			cin >> mp[i][o];
			if (mp[i][o] >= '0' && mp[i][o] <= '9')
				yao[i][o] = mp[i][o] - '0';
			if (mp[i][o] == 'K')
				stx = i, sty = o;
			else if (mp[i][o] == 'T')
				edx = i, edy = o;
			else if (mp[i][o] == 'S')
				q[++cnt].x = i, q[cnt].y = o;
		}
	}
	baoli(1, 0);
	if (ans == INF)
		cout << "impossible";
	else
		cout << ans;
	return 0;
}
