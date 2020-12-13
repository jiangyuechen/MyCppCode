#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 305;

int n, s;

namespace Edge
{
    struct edge
    {
        int to, v, nxt;
    } e[MAXN];
    int head[MAXN], top;
    void add_edge(int a, int b, int k)
    {
        e[++top].to = b;
        e[top].v = k;
        e[top].nxt = head[a];
        head[a] = top;
    }
} // namespace Edge

namespace LCA
{
    queue<int> q;
    int f[MAXN][10], t;
    int depth[MAXN], dist[MAXN];
    void bfs()
    {
        t = log(n) / log(2) + 1;
        q.push(1);
        depth[1] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = Edge::head[x]; i; i = Edge::e[i].nxt)
            {
                int y = Edge::e[i].to;
                if (depth[i])
                    continue;
                depth[y] = depth[x] + 1;
                dist[y] = dist[x] + Edge::e[i].v;
                f[y][0] = x;
                for (int j = 1; j <= t; j++)
                    f[y][j] = f[f[y][j - 1]][j - 1];
                q.push(y);
            }
        }
    }
    int lca(int x, int y)
    {
        if (depth[x] > depth[y])
            swap(x, y);
        for (int i = t; i >= 0; i--)
        {
            if (depth[f[y][i]] >= depth[x])
                y = f[y][i];
        }
        if (x == y)
            return x;
        for (int i = t; i >= 0; i--)
        {
            if (f[x][i] != f[y][i])
            {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }
    int distance(int x, int y)
    {
        return dist[x] + dist[y] - 2 * dist[lca(x, y)];
    }
} // namespace LCA

int u, v;      // 直径的两个端点
int maxl = -1; // 直径的长度
bool on[MAXN];

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 1, x, y, z; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        Edge::add_edge(x, y, z);
        Edge::add_edge(y, x, z);
    }
    LCA::bfs();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int d = LCA::distance(i, j);
            if (d > maxl)
            {
                maxl = d;
                u = i, v = j;
            }
        }
    int lca = LCA::lca(u, v);
    on[u] = on[v] = true;
    int u1 = u;
    while (u1 != lca)
    {
        u1 = LCA::f[u1][0];
        on[u1] = true;
    }
    int v1 = v;
    while (v1 != lca)
    {
        v1 = LCA::f[v1][0];
        on[v1] = true;
    }
}