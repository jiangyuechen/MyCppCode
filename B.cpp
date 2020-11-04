#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5000005;
int n, s, a[MAXN];
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
    return last == '-' ? -ans : ans;
}
long long f[MAXN], ans = -1;
long long qzh[MAXN];
int main()
{
    n = read();
    s = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        qzh[i] = qzh[i - 1] + a[i] * 1ll;
    }
    f[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = max(i - s, 1); j < i; j++)
        {
            ans = max(ans, a[i] * (qzh[i - 1] - qzh[j - 1]));
        }
    }
    printf("%lld\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}