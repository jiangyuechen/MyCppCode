#include <bits/stdc++.h>
const int MAXN = 10001, MAXM = 100001;
int n, m;

namespace Edge
{
    struct edge
    {
        int to, v, nxt;
    } e[MAXM];
    int head[MAXN], top;
    void add_edge(int a, int b, int k)
    {
        e[++top].to = b;
        e[top].v = k;
        e[top].nxt = head[a];
        head[a] = top;
    }
} // namespace Edge

namespace Dijkstra
{
    std::priority_queue<std::pair<int, int>> q;
    int vis[MAXN], d[MAXN];
    int dijkstra(int start)
    {
        memset(vis, 0, sizeof(vis));
        memset(d, 0x3f, sizeof(d));
        d[start] = 0;
        q.push(std::make_pair(0, start));
        while (!q.empty())
        {
            int x = q.top().second;
            q.pop();
            vis[x] = true;
            for (int i = Edge::head[x]; i; i = Edge::e[i].nxt)
            {
                int y = Edge::e[i].to, z = Edge::e[i].v;
                if (d[y] > d[x] + z)
                {
                    d[y] = d[x] + z;
                    q.push(std::make_pair(-d[y], y));
                }
            }
        }
    }

} // namespace Dijkstra

namespace SPFA
{
    std::queue<int> q;
    int d[MAXN];
    bool inqueue[MAXN];
    void _Push(int x)
    {
        if (!inqueue[x])
        {
            inqueue[x] = true;
            q.push(x);
        }
    }
    int _Pop()
    {
        int ret = q.front();
        q.pop();
        inqueue[ret] = false;
        return ret;
    }
    //! int cnt[MAXN];
    void spfa(int start)
    {
        memset(d, 0x3f, sizeof(d));
        memset(inqueue, 0, sizeof(inqueue));
        d[start] = 0;
        _Push(start);
        while (!q.empty())
        {
            int x = _Pop();
            for (int i = Edge::head[x]; i; i = Edge::e[i].nxt)
            {
                int y = Edge::e[i].to, z = Edge::e[i].v;
                if (d[y] > d[x] + z)
                {
                    d[y] = d[x] + z;
                    if (!inqueue[y])
                    {
                        //! if (++cnt[y] >= n)
                        //!     return true;
                        _Push(y);
                    }
                }
            }
        }
        //! return false;
    }
} // namespace SPFA