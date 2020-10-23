#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m, ans;
int a[15][MAXN];
int main()
{
    freopen("cold.in", "r", stdin);
    freopen("cold.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        for (int j = 1; j <= x; j++)
        {
            int c;
            scanf("%d", &c);
            ans += a[i][c];
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}