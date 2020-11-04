#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100001;
int f[MAXN], k, n, a[MAXN];
inline int read()
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
        ans = (ans << 3) + (ans << 1) + (ch ^ 48);
        ch = getchar();
    }
    return last == '-' ? -ans : ans;
}
int main()
{
    k = read();
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    f[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (f[j] + a[i] <= k)
            {
                f[i] = max(f[j] + a[i], f[i]);
            }
            else
            {
                f[i] = max(f[j], f[i]);
            }
        }
    }
    printf("%d\n", f[n]);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}