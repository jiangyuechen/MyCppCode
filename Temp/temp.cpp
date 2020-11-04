#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, a[MAXN], ans;
bool vis[MAXN][MAXN];
inline int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = gcd(a[i], a[j]);
            if (a[i] < a[j] && !vis[a[i] / x][a[j] / x])
            {
                ans++;
                vis[a[i] / x][a[j] / x] = true;
            }
        }
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}