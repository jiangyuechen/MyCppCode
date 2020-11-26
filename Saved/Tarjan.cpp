#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int n, m;
struct edge
{
    int to, frm, nxt;
};
inline int read()
{
    int ans = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
    {
        last = ch;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = (ans << 3) + (ans << 1) + (ch ^ 48);
        ch = getchar();
    }
    return last == '-' ? -ans : ans;
}

namespace Edge
{
    int head[MAXN], top;
    edge e[MAXN];
    auto add_edge(int a, int b) -> void
    {
        e[++top].to = b;
        e[top].frm = a;
        e[top].nxt = head[a];
        head[a] = top;
    }
} // namespace Edge
namespace Scc
{
    int head[MAXN], top;
    edge e[MAXN];
    int indgr[MAXN], outdgr[MAXN];
    auto add_edge(int a, int b) -> void
    {
        e[++top].to = b;
        e[top].frm = a;
        e[top].nxt = head[a];
        head[a] = top;
        indgr[b]++;
        outdgr[a]++;
    }
} // namespace Scc

namespace Tarjan
{
    int dfn[MAXN], low[MAXN], bel_to[MAXN];
    stack<int> stk;
    int scccnt, index;
    bool instack[MAXN];
    auto _Push(int x) -> void
    {
        stk.push(x);
        instack[x] = true;
    }
    auto _Pop() -> int
    {
        int x = stk.top();
        stk.pop();
        instack[x] = false;
        return x;
    }
    auto tarjan(int x) -> void
    {
        dfn[x] = low[x] = ++index;
        _Push(x);
        for (int i = Edge::head[x]; i; i = Edge::e[i].nxt)
        {
            int y = Edge::e[i].to;
            if (!dfn[y])
            {
                tarjan(y);
                low[x] = min(low[x], low[y]);
            }
            else if (instack[y])
            {
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x])
        {
            scccnt++;
            while (!stk.empty())
            {
                int v = _Pop();
                bel_to[v] = scccnt;
                if (v == x)
                    break;
            }
        }
    }
} // namespace Tarjan
int ot, it;
auto main() -> int
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int f = read();
        while (f != 0)
        {
            m++;
            Edge::add_edge(i, f);
            f = read();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!Tarjan::dfn[i])
            Tarjan::tarjan(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x = Tarjan::bel_to[Edge::e[i].frm], y = Tarjan::bel_to[Edge::e[i].to];
        if (x != y)
        {
            Scc::add_edge(x, y);
        }
    }
    for (int i = 1; i <= Tarjan::scccnt; i++)
    {
        if (!Scc::indgr[i])
            it++;
        if (!Scc::outdgr[i])
            ot++;
    }
    printf("%d\n", it);
    if (Tarjan::scccnt == 1)
        printf("0\n");
    else
        printf("%d\n", max(ot, it));
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
