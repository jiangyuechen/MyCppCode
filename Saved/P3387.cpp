#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 1e4 + 5, MAXM = 1e5 + 5;
#pragma endregion

struct Edge
{
    int to, nxt, w, frm;
} e[MAXM], scc[MAXM];
int head[MAXN], scc_head[MAXN], tot, scctot;
int value[MAXN], v[MAXN], indgr[MAXN];

void add_edge(int u, int v)
{
    e[++tot].to = v;
    e[tot].frm = u;
    e[tot].nxt = head[u];
    head[u] = tot;
}

int bel_to[MAXN], dfn[MAXN], low[MAXN], order = 0, stack[MAXN], top;
bool vis[MAXN];
int n, m;
void tarjan(int x)
{
    dfn[x] = low[x] = ++order;
    stack[++top] = x;
    vis[x] = true;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int y = e[i].to;
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (vis[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x])
    {
        int y;
        do
        {
            y = stack[top--];
            bel_to[y] = x;
            vis[y] = false;
            value[x] += v[y];
        } while (x != y);
    }
}

void scc_add_edge(int u, int v)
{
    scc[++scctot].frm = u;
    scc[scctot].to = v;
    scc[scctot].nxt = scc_head[u];
    scc_head[u] = scctot;
    indgr[v]++;
}

int toposort()
{
    int ans[MAXN];
    memset(ans, 0, sizeof(ans));
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!indgr[i] && bel_to[i] == i)
        {
            q.push(i);
            ans[i] = value[i];
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = scc_head[x]; i; i = scc[i].nxt)
        {
            int y = scc[i].to;
            ans[y] = max(ans[y], ans[x] + value[y]);
            indgr[y]--;
            if (!indgr[y])
                q.push(y);
        }
    }
    int ret = -1;
    for (int i = 1; i <= n; i++)
    {
        ret = max(ret, ans[i]);
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }

    for (int i = 1; i <= tot; i++)
    {
        int x = e[i].frm, y = e[i].to;
        if (bel_to[x] != bel_to[y])
        {
            scc_add_edge(x, y);
        }
    }

    printf("%d\n", toposort());
    END_PROGRAM
}