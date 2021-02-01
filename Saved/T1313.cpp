#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int n;
int f[MAXN], g[MAXN];
// f[i] 表示 i 位数中有多少个数有偶数个数字 3
// g[i] 表示 i 位数中有多少个数有奇数个数字 3

int main()
{
    scanf("%d", &n);
    f[1] = 9;
    g[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = g[i - 1] + (i == n ? 8 : 9) * f[i - 1];
        g[i] = f[i - 1] + (i == n ? 8 : 9) * g[i - 1];
        f[i] %= 12345;
        g[i] %= 12345;
    }
    printf("%d\n", f[n]);
    system("pause");
}