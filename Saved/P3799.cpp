#pragma region STANDARD
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 100001;

#pragma endregion

int n, a[MAXN], q;
int f[MAXN][18], g[MAXN][18];
void ST_prework()
{
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = g[i][0] = a[i];
    }
    int t = log(n) / log(2) + 1;
    for (int j = 1; j <= t; j++)
    {
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int qry(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]) - min(g[l][k], g[r - (1 << k) + 1][k]);
}



int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    ST_prework();
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y)
            swap(x, y);
        printf("%d\n", qry(x, y));
    }
    END_PROGRAM
}