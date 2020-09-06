#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
#define re register
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
struct Rec
{
    int x, y, w;
} edge[500010];
int fa[100010], n, m, ans;
bool operator<(const Rec &a, const Rec &b)
{
    return a.w < b.w;
}
int _get(int x)
{
    if (x == fa[x])
        return x;
    else
        return fa[x] = _get(fa[x]);
}

int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= m; i++)
    {
        edge[i].x = read();
        edge[i].y = read();
        edge[i].w = read();
    }
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x = _get(edge[i].x);
        int y = _get(edge[i].y);
        if (x == y)
            continue;
        fa[x] = y;
        ans += edge[i].w;
    }
    cout << ans << endl;
    return 0;
}