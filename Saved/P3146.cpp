#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 1001;
int f[MAXN][MAXN];
int n, ans = -0x7fffffff;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i][i]);
        ans = max(ans, f[i][i]);
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1, r = l + len - 1; r <= n; l++, r++)
        {
            for (int k = l; k < r; k++)
            {
                if (f[l][k] == f[k + 1][r] && f[l][k] != 0)
                {
                    f[l][r] = f[l][k] + 1;
                    ans = max(ans, f[l][r]);
                }
            }
        }
    }
    printf("%d\n", ans);
    END_PROGRAM
}