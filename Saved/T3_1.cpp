#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 100001;
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
int k, n, m, t;
int val[MAXN];
int ans = 2147483647;
bool vis[MAXN];
void dfs(int now, int fini, int v)
{
    if (now == fini)
    {
        ans = min(ans, v);
        return;
    }
    if (ans != 2147483647 && v > ans)
        return;
    for (int i = head[now]; i; i = nxt[i])
    {
        int to = ver[i];
        if (vis[to])
            continue;
        vis[to] = true;
        dfs(to, fini, max(v, val[to]));
        vis[to] = false;
    }
}
void reset()
{
    memset(head, 0, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    memset(ver, 0, sizeof(ver));
    tot = 0;
}
int main()
{

    scanf("%d", &k);
    freopen("temp.txt", "w", stdout);
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
            add_edge(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            vis[t] = true;
            dfs(t, i, val[t]);
            vis[t] = false;
            printf("%d", ans);
            if (i != n)
                printf(" ");
            ans = 2147483647;
        }
        if (k)
            puts("");
        reset();
    }
    fclose(stdout);
    system("pause");
    return 0;
}