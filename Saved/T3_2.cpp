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
const int MAXN = 300050;
#pragma endregion

#pragma region CFS
int ver[MAXN], nxt[MAXN], edge[MAXN], head[MAXN], tot;
void add_edge(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
#pragma endregion

int val[MAXN];
int k, n, m, t;

namespace spfa
{
    int dist[MAXN];
    bool vis[MAXN];
    queue<int> q;
    void SPFA(int start)
    {
        fill(dist + 1, dist + n + 1, 2147483647);
        q.push(start);
        dist[start] = val[start];
        vis[start] = true;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            vis[x] = false;
            for (int i = head[x]; i; i = nxt[i])
            {
                int y = ver[i];
                if (dist[y] > max(dist[x], edge[i]))
                {
                    dist[y] = max(dist[x], edge[i]);
                    if (!vis[y])
                    {
                        vis[y] = true;
                        q.push(y);
                    }
                }
            }
        }
    }
} // namespace spfa

void reset()
{
    memset(ver, 0, sizeof(ver));
    memset(edge, 0, sizeof(edge));
    memset(nxt, 0, sizeof(nxt));
    memset(head, 0, sizeof(head));
    tot = 0;
}

int main()
{
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d%d%d", &n, &m, &t);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", val + i);
        }
        for (int i = 1, x, y; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            add_edge(x, y, max(val[x], val[y]));
        }
        spfa::SPFA(t);
        for (int i = 1; i <= n; i++)
        {
            printf("%d", spfa::dist[i]);
            if (n != i)
                printf(" ");
        }
        if (k)
        {
            puts("");
        }
        reset();
    }
    return 0;
}