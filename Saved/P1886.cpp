#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
inline int read()
{
    int s = 0, w = 1;
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
const int MAXN = 1e6 + 1;
int a[MAXN];
int f[MAXN][20];
int g[MAXN][20];
int n, k;
vector<int> vmax, vmin;
void st_prework()
{
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = g[i][0] = a[i];
    }
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
    {
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int st_query_max(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
int st_query_min(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return min(g[l][k], g[r - (1 << k) + 1][k]);
}
int main()
{
    n = read();
    k = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    st_prework();
    for (int l = 1, r = k; r <= n; l++, r++)
    {
        vmax.push_back(st_query_max(l, r));
        vmin.push_back(st_query_min(l, r));
    }
    for (auto i : vmin)
    {
        printf("%d ", i);
    }
    puts("");
    for (auto i : vmax)
    {
        printf("%d ", i);
    }
    END_PROGRAM
}