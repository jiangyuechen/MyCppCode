#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 505;

namespace Edge
{
    struct edge
    {
        int to, w, nxt;
    } e[MAXN];
    int head[MAXN], top;
    /**
     * @brief 连一条边。
     * @param a 边的起点。
     * @param b 边的终点。
     * @param k 边的权值。
    */
    void add_edge(int a, int b, int k)
    {
        e[++top].to = b;
        e[top].w = k;
        e[top].nxt = head[a];
        head[a] = top;
    }
} // namespace Edge

bool piv[MAXN]; // (Pivotal) piv[i] == true <=> i 是关键点。

bool moda[MAXN][50001]; // moda[i][j] == true <=> 存在从出发点到 i 的路径，使得 经过的权值模 P == L.

int T, n, m, k, P, L;

void dfs(int now, int val)
{
    for (int i = Edge::head[now]; i; i = Edge::e[i].nxt)
    {
        int y = Edge::e[i].to, len = Edge::e[i].w;
        int vnxt = (val + len) % P;
        if (moda[y][vnxt])
            continue;
        moda[y][vnxt] = true;
        dfs(y, vnxt);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("T2.in", "r", stdin);
    freopen("T2.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        memset(piv, 0, sizeof(piv));
        memset(Edge::e, 0, sizeof(Edge::e));
        memset(Edge::head, 0, sizeof(Edge::head));
        memset(moda, 0, sizeof(moda));
        Edge::top = 0;

        scanf("%d%d%d%d%d", &n, &m, &k, &P, &L);
        for (int i = 1, x; i <= k; i++)
        {
            scanf("%d", &x);
            piv[x] = true;
        }
        for (int i = 1, x, y, z; i <= m; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            Edge::add_edge(x, y, z);
            Edge::add_edge(y, x, z);
        }
        for (int i = 1; i <= n; i++)
        {
            if (piv[i])
            {
                moda[i][0] = true;
                dfs(i, 0);
                moda[i][0] = false;
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (moda[i][L] && piv[i])
                flag = true;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}