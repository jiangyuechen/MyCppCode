#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2000010, MAXM = 2000010;
typedef long long ll;
int n, m;
int depth[MAXN], anc[MAXN][30];
ll value[MAXN];
int max_depth;
ll read()
{
    char ch = getchar(), last = ' ';
    ll ans = 0ll;
    while (ch < '0' || ch > '9')
    {
        last = ch;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = (ans << 3ll) + (ans << 1ll) + (ch ^ 48ll);
        ch = getchar();
    }
    return last == '-' ? -ans : ans;
}
namespace Edge
{
    struct edge
    {
        int to, nxt;
    } e[MAXM];
    int head[MAXN], top;
    auto add_edge(int a, int b) -> void
    {
        e[++top].to = b;
        e[top].nxt = head[a];
        head[a] = top;
    }
} // namespace Edge
namespace LCA
{
    void bfs(int root)
    {
        queue<int> q;
        q.push(root);
        depth[root] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = Edge::head[x], son; i; i = Edge::e[i].nxt)
            {
                son = Edge::e[i].to;
                if (depth[son])
                    continue; //make sure that "son" is not father,i.e.depth[son] is not been got.
                depth[son] = depth[x] + 1;
                anc[son][0] = x;
                for (int j = 1; j <= max_depth; j++)
                {
                    anc[son][j] = anc[anc[son][j - 1]][j - 1];
                }
                q.push(son);
            }
        }
    }

    int lca(int x, int y)
    {
        if (depth[x] > depth[y])
            swap(x, y);
        for (int i = max_depth; i >= 0; i--)
        {
            if (depth[anc[y][i]] >= depth[x])
                y = anc[y][i];
        }
        if (x == y)
            return x;
        for (int i = max_depth; i >= 0; i--)
        {
            if (anc[x][i] != anc[y][i])
                x = anc[x][i], y = anc[y][i];
        }
        return anc[x][0];
    }

} // namespace LCA
int main()
{
    n = read();
    m = read();
    max_depth = (int)(log(n) / log(2)) + 1;
    for (int i = 1; i <= n; i++)
    {
        value[i] = read();
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int x = read(), y = read();
        Edge::add_edge(x, y);
        Edge::add_edge(y, x);
    }
    LCA::bfs(1);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        x = read();
        y = read();
        int lca = LCA::lca(x, y);
        ll ans = value[lca];
        while (x != lca)
        {
            ans = max(ans, value[x]);
            x = anc[x][0];
        }
        while (y != lca)
        {
            ans = max(ans, value[y]);
            y = anc[y][0];
        }
        printf("%lld", ans);
        if (i != m)
            puts("");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}