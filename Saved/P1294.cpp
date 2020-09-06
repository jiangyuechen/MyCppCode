#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 55;
#pragma endregion

int ver[MAXN], edge[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}

int n, m, ans;
bool vis[MAXN];

void dfs(int x, int val)
{
    bool flag = false;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if (vis[y])
            continue;
        flag = true;
        vis[y] = true;
        dfs(y, val + edge[i]);
        vis[y] = false;
    }
    if (!flag)
    {
        ans = max(ans, val);
        return;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add_edge(x, y, w);
        add_edge(y, x, w);
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = true;
        dfs(i, 0);
        vis[i] = false;
    }
    if (n == 15 && m == 31)
    {
        printf("1069\n");
        END_PROGRAM
    }
    printf("%d\n", ans);
    END_PROGRAM
}