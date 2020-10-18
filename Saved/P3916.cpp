#pragma region STANDARD
#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 100001;
#pragma endregion

struct edge
{
    int frm, to, w, nxt;
} ed[MAXN], e[MAXN];
int head[MAXN], h[MAXN], tot, t;

int dfn[MAXN], low[MAXN], order, stk[MAXN], stk_tp, bel_to[MAXN], cnt;
bool in_stk[MAXN];
int val[MAXN];

void add_edge(int u, int v)
{
    ed[++tot].to = v;
    ed[tot].frm = u;
    ed[tot].nxt = head[u];
    head[u] = tot;
}

void scc_add_edge(int u, int v)
{
    e[++t].to = v;
    e[t].frm = u;
    e[t].nxt = h[u];
    h[u] = t;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++order;
    in_stk[x] = true;
    stk[++stk_tp] = x;
    for (int i = head[x]; i; i = ed[i].nxt)
    {
        int y = ed[i].to;
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (in_stk[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (low[x] == dfn[x])
    {
        cnt++;
        int y;
        do
        {
            y = stk[stk_tp--];
            bel_to[y] = cnt;
            in_stk[y] = false;
            val[cnt] = max(val[cnt], y);
            //!wrong:  bel_to[y] = x;
            //!wrong:  val[x] = max(val[x], y);
            //! bel_to[x] means that which SCC x belongs to.
            //! but not which UPPER_VERTEX x belongs to.
        } while (x != y);
    }
}

int n, m, ans[MAXN];

void dfs(int x)
{
    //? Pretend that the answer of y is got,how can we get the answer of x?
    //? Obviously, ans[x] = max(ans[x], ans[y]), because we can walk from x to y and get answer of y.
    //? The origin answer is its value.
    //? if the answer of x is got, because the whole graph is a DAG, it can't be updated again.
    //? we just return.
    if (ans[x])
        return;
    ans[x] = val[x];
    for (int i = h[x]; i; i = e[i].nxt)
    {
        int y = e[i].to;
        dfs(y);
        ans[x] = max(ans[x], ans[y]);
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
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x = ed[i].frm, y = ed[i].to;
        if (bel_to[x] != bel_to[y])
        {
            scc_add_edge(bel_to[x], bel_to[y]);
            //!wrong:   scc_add_edge(x, y)
            //! Don't use origin number of the vertexes. Because the new graph is numbered by BEL_TO[],
            //! we should use its new number in SCC.
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (!ans[i])
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[bel_to[i]]);
        //!wrong:     ans[i]
        //! In the new graph, vertexes is named by bel_to[vertex].
        //! We should convert the origin number i to its number in SCC bel_to[i].
    }
    END_PROGRAM
}