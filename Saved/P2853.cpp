#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const long long MAXN = 10001;
inline long long read()
{
    long long s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
long long ver[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(long long u, long long v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
bool havecow[MAXN];
long long k, n, m;
long long times[MAXN];
bool vis[MAXN];
void dfs(long long now)
{
    vis[now] = true;
    times[now]++;
    for (long long i = head[now]; i; i = nxt[i])
    {
        long long y = ver[i];
        if (vis[y])
            continue;
        dfs(y);
    }
}
long long ans;
long long cow[MAXN];
long long main()
{
    k = read();
    n = read();
    m = read();
    for (long long i = 1; i <= k; i++)
    {
        cow[i] = read();
    }
    for (long long i = 1, x, y; i <= m; i++)
    {
        x = read();
        y = read();
        add_edge(x, y);
    }
    for (long long i = 1; i <= k; i++)
    {
        dfs(cow[i]);
        memset(vis, 0, sizeof(vis));
    }
    for (long long i = 1; i <= n; i++)
    {
        if (times[i] == k)
            ans++;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}