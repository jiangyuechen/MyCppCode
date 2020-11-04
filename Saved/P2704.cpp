#include <bits/stdc++.h>
#define SET_DIGIT_1(x, k) x |= (1 << (k))
using namespace std;

int read()
{
    int ans = 0;
    char last = ' ', ch = getchar();
    while (ch < '0' || ch > '9')
    {
        last = ch;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = (ans << 1) + (ans << 3) + (ch ^ 48);
        ch = getchar();
    }
    return last = '-' ? -ans : ans;
}

const int MAXN = 101;
int dp[MAXN][MAXN][MAXN];
char str[MAXN][MAXN];
int h[MAXN];
int legal[MAXN], cnt_legal, c[MAXN];

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i]);
    for (int i = 0; i < (1 << m); i++)
    {
        bool flag = false;
        int x = 0;
        for (int j = 0; j < m; j++)
        {
            if (i >> j & 1)
            {
                flag |= (i >> j + 1 & 1) || (i >> j + 2 & 1);
                x++;
            }
        }
        if (!flag)
            legal[++cnt_legal] = i, c[cnt_legal] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (str[i][j] == 'H')
                SET_DIGIT_1(h[i], j);
        }
    }
    for (int i = 1; i <= cnt_legal; i++)
    {
        for (int j = 1; j <= cnt_legal; j++)
        {
            if (!(legal[i] & h[1]) && !(legal[j] & h[2]) && !(legal[i] & legal[j]))
                dp[2][i][j] = c[i] + c[j];
        }
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= cnt_legal; j++)
        {
            if (!(legal[j] & h[i]))
            {
                for (int k = 1; k <= cnt_legal; k++)
                {
                    for (int l = 1; l <= cnt_legal; l++)
                    {
                        if (!(legal[j] & legal[k]) && !(legal[j] & legal[l]))
                        {
                            dp[i][l][j] = max(dp[i][l][j], dp[i - 1][k][l] + c[j]);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= cnt_legal; j++)
    {
        for (int k = 1; k <= cnt_legal; k++)
        {
            ans = max(ans, dp[n][j][k]);
        }
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}