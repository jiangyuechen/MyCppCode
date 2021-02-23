#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define TONUM(x, y) ((x - 1) * (c) + (y))
using namespace std;
const int MAXN = 10005;
vector<int> e[MAXN];
int indgr[MAXN], outdgr[MAXN];

void add_edge(int frm, int to) {
	e[frm].push_back(to);
	outdgr[frm]++;
	indgr[to]++;
}
int r, c, ans;
int mp[MAXN], f[MAXN];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf("%d", &mp[TONUM(i, j)]);
	for (int x = 1; x <= r; x++)
		for (int y = 1; y <= c; y++) {
			int s = TONUM(x, y);
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				int t = TONUM(nx, ny);
				if (nx >= 1 &&
					nx <= r &&
					ny >= 1 &&
					ny <= c &&
					mp[s] > mp[t]) {
					add_edge(s, t);
				}
			}
		}
	queue<int> q;
	for (int i = 1; i <= r * c; i++) {
		f[i] = 1;
		if (!indgr[i])
			q.push(i);
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int o = 0; o < e[x].size(); o++) {
			int to = e[x][o];
			f[to] = max(f[to], f[x] + 1);
			indgr[to]--;
			if (!indgr[to])
				q.push(to);
		}
	}
	for (int i = 1; i <= r * c; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}