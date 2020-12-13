#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001, MAXM = 100001;

vector<int> v[MAXN];
void add_edge(int a, int b)
{
    v[a].push_back(b);
}

int m, n;
bool vis[MAXN]; // 不能被封锁的点

int ans = -1;

void dfs(int x, int foot, int remain_edge)
{
    if (vis[x]) // 可行性剪枝
        return;
    if (ans != -1 && foot >= ans) // 最优性剪枝
        return;
    if (!remain_edge)
    {
        ans = foot;
        return;
    }
    // 1.封锁这个点
    vis[x] = true;
    for (auto &y : v[x])
    {
        vis[y] = true;

        for (auto &z : v[y])
        {
            if (z != x)
                dfs(z, foot + 1, remain_edge - v[x].size());
        }
        vis[y] = false;
    }
    vis[x] = false;
    // 2.不封锁这个点
    for (auto &y : v[x])
    {
        dfs(y, foot, remain_edge);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0, m);
    if (ans != -1)
        printf("%d\n", ans);
    else
        puts("Impossible");
    return 0;
}