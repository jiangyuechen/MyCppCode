#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 801, MAXK = 16, MOD = 1000000007;
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
int n, m, k;
int f[MAXN][MAXN][MAXK][2];
int a[MAXN][MAXN];
int main() {
    n = read();
    m = read();
    k = read();
    k++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = read();
            f[i][j][a[i][j] % k][0] = 1;
        }
    }
#if true
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int s = 0; s < k; s++) {
                if (i - 1 >= 1)
                    (f[i][j][0][s] += f[i - 1][j][(s - a[i][j] + k) % k][1]) %=
                        MOD;
                if (j - 1 >= 1)
                    (f[i][j][0][s] += f[i][j - 1][(s - a[i][j] + k) % k][1]) %=
                        MOD;
                if (i - 1 >= 1)
                    (f[i][j][1][s] += f[i - 1][j][(s + a[i][j]) % k][1]) %= MOD;
                if (j - 1 >= 1)
                    (f[i][j][1][s] += f[i][j - 1][(s + a[i][j]) % k][1]) %= MOD;
            }
        }
    }
#else
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int h = 0; h < k; h++) {
                if (i + 1 <= n) {
                    f[i + 1][j][(h + a[i + 1][j]) % k][0] =
                        (f[i + 1][j][(h + a[i + 1][j]) % k][0] +
                         f[i][j][h][1]) %
                        MOD;
                    f[i + 1][j][(h - a[i + 1][j] + k) % k][1] =
                        (f[i + 1][j][(h - a[i + 1][j] + k) % k][1] +
                         f[i][j][h][0]) %
                        MOD;
                }
                if (j + 1 <= m) {
                    f[i][j + 1][(h + a[i][j + 1]) % k][0] =
                        (f[i][j + 1][(h + a[i][j + 1]) % k][0] +
                         f[i][j][h][1]) %
                        MOD;
                    f[i][j + 1][(h - a[i][j + 1] + k) % k][1] =
                        (f[i][j + 1][(h - a[i][j + 1] + k) % k][1] +
                         f[i][j][h][0]) %
                        MOD;
                }
            }
#endif
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = (ans + f[i][j][0][1]) % MOD;
        }
    }
    printf("%d\n", ans);
    // system("pause");
    return 0;
}