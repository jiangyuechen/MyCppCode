#pragma region STANDARD
#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
#pragma endregion

const int MAXN = 100015;
int n, m, sum, order, top, s;
int p[MAXN], head[MAXN], belong[MAXN], dfn[MAXN], low[MAXN]; //DFN(u)为节点u搜索被搜索到时的次序编号(时间戳)，Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号
int stk[MAXN], vis[MAXN];                                    //栈只为了表示此时是否有父子关系
int scc_head[MAXN], indgr[MAXN], ans[MAXN];
struct EDGE
{
    int to;
    int next;
    int from;
} e[MAXN], scc_e[MAXN];
void add(int x, int y)
{
    e[++sum].next = head[x];
    e[sum].from = x;
    e[sum].to = y;
    head[x] = sum;
}
void tarjan(int x)
{
    low[x] = dfn[x] = ++order;
    stk[++top] = x;
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if (vis[v])
        {
            low[x] = min(low[x], low[v]);
        }
    }
    if (dfn[x] == low[x])
    {
        int y;
        while (y = stk[top--])
        {
            belong[y] = x;
            vis[y] = 0;
            if (x == y)
                break;
            p[x] += p[y];
        }
    }
}
int topo()
{
    queue<int> q;
    int tot = 0;
    for (int i = 1; i <= n; i++)
        if (belong[i] == i && !indgr[i])
        {
            q.push(i);
            ans[i] = p[i];
        }
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = scc_head[k]; i; i = scc_e[i].next)
        {
            int v = scc_e[i].to;
            ans[v] = max(ans[v], ans[k] + p[v]);
            indgr[v]--;
            if (indgr[v] == 0)
                q.push(v);
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret = max(ret, ans[i]);
    return ret;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        int x = belong[e[i].from], y = belong[e[i].to];
        if (x != y)
        {
            scc_e[++s].next = scc_head[x];
            scc_e[s].to = y;
            scc_e[s].from = x;
            scc_head[x] = s;
            indgr[y]++;
        }
    }
    printf("%d", topo());
    return 0;
}