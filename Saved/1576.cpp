#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 405;

vector<int> adj[MAXN];
int s[MAXN], n, m, f[MAXN][MAXN];

void dfs(int u) {
    for (int j = 1; j <= m; j++)
        f[u][j] = s[u];
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v);
        for (int j = m; j > 0; j--)
            for (int k = 0; k < j; k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    ++m;
    for (int father, i = 1; i <= n; i++)
        scanf("%d %d", &father, &s[i]), adj[father].push_back(i);
    dfs(0);
    printf("%d", f[0][m]);
}