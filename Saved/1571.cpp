#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;

using namespace std;

inline ll read() {
    ll x = 0ll, f = 1ll;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1ll;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10ll + ch - '0';
        ch = getchar();
    }
    return x * f;
}
ll a[110], n;
ll f[110][110];
/**
 * 思路：
 * 1.断环为链。
 * 2.考虑顶点 i , j 围成的凸多边形。在区间 (i,j) 中可以找一点 k , 使得 k, i, j
 * 三点构成一个新三角形。 3.则在这种情况下所得值为 三个点权的乘积 加上
 * 凸多边形剩余两部分（或一部分）的权值 的和。 4.枚举 k 求最小值即可。
 */
int main() {
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = n + 1; i <= 2 * n; i++)
        a[i] = a[i - n];
    memset(f, 127, sizeof(f));
    for (int i = 1; i < 2 * n; i++) {
        f[i][i + 1] = 0ll;
    }
    for (int len = 3; len <= n; len++)
        for (int l = 1; l <= n * 2 - len + 1; l++) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
        }
    ll mans = (1ll << 62ll);
    for (int i = 1; i <= n; i++) {
        mans = min(mans, f[i][i + n - 1]);
    }
    cout << mans << endl;
    // system("pause");
    return 0;
}