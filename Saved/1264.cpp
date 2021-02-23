#include <iostream>
using namespace std;
int n, a[105];
int f[105], g[105];
int ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        f[i] = g[i] = 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    for (int i = n - 1; i >= 1; i--)
        for (int j = n; j > i; j--)
            if (a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i] + g[i] - 1);
    printf("%d\n", n - ans);
}