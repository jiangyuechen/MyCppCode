#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 3050;

inline int read() {
    int s = 0, w = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

vector<int> edge[MAXN];

int n;
int dp[MAXN][2];
// dp[i][j] 表示 在以 i 为根的子树上至少需要多少士兵，
// 且子树根 i 上放士兵 (j == 1) 或不放士兵 (j == 0)。
void Dfs(int x, int father) {
    for (int i = 0; i < edge[x].size(); i++) {
        int y = edge[x][i];
        if (y == father) continue;
        Dfs(y, x);
        dp[x][1] += min(dp[y][0], dp[y][1]);
        dp[x][0] += min(dp[y][0] + 1, dp[y][1]);
    }
}
int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int rt = read();
        int t = read();
        while (t--) {
            int ver = read();
            edge[rt].push_back(ver);
            edge[ver].push_back(rt);
        }
    }
    Dfs(0, -1);
    printf("%d\n", min(dp[0][0], dp[0][1]));
}