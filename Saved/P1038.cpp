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
constexpr int MAXN = 1001;
#pragma endregion

int ver[MAXN], edge[MAXN], nxt[MAXN], head[MAXN], tot;
int indgr[MAXN], outdgr[MAXN];
bool vis[MAXN];
void add_edge(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
    outdgr[u]++;
    indgr[v]++;
}
int n, p;
int c[MAXN], u[MAXN];
queue<int> q;
int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", c + i, u + i);
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add_edge(x, y, w);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!indgr[i])
            q.push(i);
        if (!c[i])
            c[i] -= u[i];
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            --indgr[y];
            if (c[x] > 0)
                c[y] += edge[i] * c[x];
            if (!indgr[y])
                q.push(y);
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] > 0 && (!outdgr[i]))
            flag = true;
    }
    if (!flag)
    {
        printf("NULL\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (c[i] > 0 && (!outdgr[i]))
            {
                printf("%d %d\n", i, c[i]);
            }
        }
    }
    END_PROGRAM
}