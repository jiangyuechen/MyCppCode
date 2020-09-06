#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 300010;
#pragma endregion
#pragma region CFS
int ver[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
#pragma endregion
#pragma region DATA
int k, n, m, t;
int val[MAXN];
#pragma endregion

namespace Tarjan
{
    int dfn[MAXN], low[MAXN], order = 0;
    int stk[MAXN], top;
    bool instack[MAXN];
    int scccnt = 0;
    vector<int> scc[MAXN];
    int in_scc[MAXN];
    int newval[MAXN];
    int indgr[MAXN], outdgr[MAXN];
    void prework()
    {
        memset(newval, 0x7f, sizeof(newval));
    }
    void tarjan(int x)
    {
        dfn[x] = low[x] = ++order;
        stk[++top] = x;
        instack[x] = true;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (!dfn[y])
            {
                tarjan(y);
                low[x] = min(low[x], low[y]);
            }
            else if (instack[y])
            {
                low[x] = min(low[x], dfn[y]);
            }
            if (dfn[x] == low[x])
            {
                scccnt++;
                int y;
                do
                {
                    y = stk[top--];
                    instack[y] = false;
                    in_scc[y] = scccnt;
                    scc[scccnt].push_back(y);
                } while (x != y);
            }
        }
    }
    void make_newval()
    {
        for (int i = 1; i <= scccnt; i++)
        {
            for (auto &a : scc[i])
            {
                newval[i] = min(newval[i], val[a]);
            }
        }
    }
    int scchead[MAXN], sccver[MAXN], sccnxt[MAXN], scctot;
    void scc_add_edge(int x, int y)
    {
        sccver[++scctot] = y;
        sccnxt[scctot] = scchead[x];
        scchead[x] = scctot;
    }
    void make_graph()
    {
        for (int x = 1; x <= n; x++)
        {
            for (int i = head[x]; i; i = nxt[i])
            {
                int y = ver[i];
                if (in_scc[x] == in_scc[y])
                    continue;
                scc_add_edge(in_scc[x], in_scc[y]);
                outdgr[in_scc[x]]++;
                indgr[in_scc[y]]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d is in %d.\n", newval[in_scc[i]]);
        }
    }
} // namespace Tarjan

using namespace Tarjan;

int f[MAXN]; //f[i]表示走到i点时的最大点权。

int main()
{
    scanf("%d", &k);
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", val + i);
    }
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        add_edge(x, y);
    }
    prework();
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    make_newval();
    make_graph();
    queue<int> q;
    for (int i = 1; i <= scccnt; i++)
    {
        printf("%d ", newval[i]);
        f[i] = newval[i];
        if (indgr[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = scchead[x]; i; i = sccnxt[i])
        {
            int y = sccver[i];
            f[y] = max(f[y], f[x]);
            indgr[y]--;
            if (!indgr[y])
                q.push(y);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", f[in_scc[i]]);
    }
    for (int i = 1; i <= n; i++)
    {
    }
    END_PROGRAM
}