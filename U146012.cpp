#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 401;
int k, n;
int a[MAXN];
int f[MAXN][10];
int g[MAXN][10];
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
int st_query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]) - min(g[l][k], g[r - (1 << k) + 1][k]);
}
bool ok()
{
    for (int len = k + 1; len < n; len++)
    {
        for (int i = 1, j = len; j <= n; i++, j++)
        {
            if (st_query(i, j) == len - 1)
            {
                return true;
            }
        }
    }
    return false;
}
int ans = 0;
int mod = 1e9 + 7;
int main()
{
    scanf("%d%d", &n, &k);
    if (n <= k + 1)
    {
        printf("0\n");
        END_PROGRAM
    }
    for (int i = 1; i <= n; i++)
        a[i] = i;
    do
    {
        st_prework();
        if (!ok())
        {
            for (int i = 1; i <= n; i++)
                printf("%d", a[i]);
            puts("");
            ans++;
            ans %= mod;
        }
    } while (next_permutation(a + 1, a + n + 1));
    printf("%d\n", ans);

    END_PROGRAM
}