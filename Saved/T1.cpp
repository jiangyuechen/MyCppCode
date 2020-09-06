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
const int MAXN = 1001;
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#pragma endregion

int a[MAXN];
int f[MAXN][MAXN];
int g[MAXN][MAXN];
int n;
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
            f[i][j] = MAX(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = MIN(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int st_query_max(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return MAX(f[l][k], f[r - (1 << k) + 1][k]);
}
int st_query_min(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return MIN(g[l][k], g[r - (1 << k) + 1][k]);
}

int t;

int ans = 0;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
        }
        st_prework();
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (j == i + 1)
                {
                    if (a[i] < a[j])
                        ans = MAX(ans, 1);
                    continue;
                }
                int _max = st_query_max(i + 1, j - 1);
                int _min = st_query_min(i + 1, j - 1);
                if (a[i] < a[j] && a[i] < _min && _max < a[j])
                {
                    ans = MAX(ans, j - i);
                }
            }
        }
        printf("%d\n", ans);
        ans = 0;
    }
    END_PROGRAM
}