#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MAXM = 200005;
int n, m;
namespace Edge
{
    struct edge
    {
        int frm, to, nxt;
    } e[MAXM];
    int head[MAXN], top;
    int indgr[MAXN];
    void add_edge(int a, int b)
    {
        e[++top].frm = a;
        e[top].to = b;
        e[top].nxt = head[a];
        head[a] = top;
        indgr[b]++;
    }
} // namespace Edge
int f[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Edge::add_edge(x, y);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!Edge::indgr[i])
        {
            f[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int frm = q.front();
        q.pop();
        for (int i = Edge::head[frm]; i; i = Edge::e[i].nxt)
        {
            int to = Edge::e[i].to;
            f[to] = max(f[to], f[frm] + 1);
            Edge::indgr[to]--;
            if (!Edge::indgr[to])
                q.push(to);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", f[i]);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
}
