#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 200015;

#define SECOND(x) (x + cnt)

int n, m, sum, order, top, s, cnt;
int p[MAXN], head[MAXN], belong[MAXN], dfn[MAXN], low[MAXN];
int stack[MAXN], vis[MAXN];
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
void scc_add_edge(int x, int y)
{
    scc_e[++s].next = scc_head[x];
    scc_e[s].from = x;
    scc_e[s].to = y;
    scc_head[x] = s;
}
void tarjan(int x)
{
    low[x] = dfn[x] = ++order;
    stack[++top] = x;
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
        cnt++;
        while (stack[top] != x)
        {
            belong[stack[top]] = cnt;
            vis[stack[top]] = false;
            p[cnt]++;
            top--;
        }
        belong[stack[top]] = cnt;
        vis[stack[top]] = false;
        p[cnt]++;
        top--;
    }
}
namespace SPFA
{
    int d[MAXN];
    bool inqueue[MAXN];
    queue<int> q;
    // 注意设置inqueue.
    void _insert(int x) // 模拟进入队列
    {
        if (!inqueue[x])
        {
            q.push(x);
            inqueue[x] = true;
        }
    }
    int _pop() // 模拟弹出队列
    {
        int x = q.front();
        q.pop();
        inqueue[x] = false;
        return x;
    }
    void spfa(int start)
    {
        memset(d, 0, sizeof(d));
        memset(inqueue, 0, sizeof(inqueue));
        d[start] = 0;
        _insert(start);
        while (!q.empty())
        {
            int x = _pop();
            for (int i = scc_head[x]; i; i = scc_e[i].next)
            {
                int y = scc_e[i].to, z = p[x];
                if (d[y] < d[x] + z)
                {
                    d[y] = d[x] + z;
                    _insert(y);
                }
            }
        }
    }
} // namespace SPFA
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= cnt; i++)
        p[SECOND(i)] = p[i];
    for (int i = 1; i <= m; i++)
    {
        int x = belong[e[i].from], y = belong[e[i].to];
        if (x != y)
        {
            scc_add_edge(x, y);
            scc_add_edge(y, SECOND(x));
            scc_add_edge(SECOND(x), SECOND(y));
        }
    }
    SPFA::spfa(belong[1]);
    printf("%d\n", SPFA::d[belong[1] + cnt]);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}