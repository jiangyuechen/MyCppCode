#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const int MAXN = 35;
typedef long long ll;
ll n, a[MAXN];
ll f[MAXN][MAXN]; // f[i][j] => i ~ j best score.
ll p[MAXN][MAXN];
ll ans[MAXN], top;
void output(int l, int r)
{
    if (l > r)
        return;
    ll k = p[l][r];
    printf("%lld ", k);
    output(l, k - 1);
    output(k + 1, r);
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 0; i <= n; i++) // ! from 0
        for (int j = 0; j <= n; j++)
            f[i][j] = 1;
    for (int i = 1; i <= n; i++)
        f[i][i] = a[i], p[i][i] = i;
    for (int len = 2; len <= n; len++)
        for (int l = 1, r = l + len - 1; r <= n; l++, r++)
            for (int k = l; k <= r; k++)
            {
                int nx = f[l][k - 1] * f[k + 1][r] + a[k];
                if (nx > f[l][r])
                {
                    f[l][r] = nx;
                    p[l][r] = k;
                }
            }

    printf("%lld\n", f[1][n]);
    output(1, n);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}