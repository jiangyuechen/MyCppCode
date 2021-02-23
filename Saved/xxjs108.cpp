#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 105;
int n;
int x[MAXN][MAXN], y[MAXN][MAXN];
int f[MAXN][MAXN];
int main() {
    cin >> n;
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++) {
        cin >> x[i][i] >> y[i][i];
        f[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
            for (int k = l; k < r; k++) {
                if (y[l][k] == x[k + 1][r]) {
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + x[l][k] * y[l][k] * y[k + 1][r]);
                    x[l][r] = x[l][k];
                    y[l][r] = y[k + 1][r];
                    // printf("f[%d,%d]:%d f[%d,%d]:%d f[%d,%d]:%d x[%d,%d]:%d x[%d,%d]:%d x[%d,%d]:%d y[%d,%d]:%d y[%d,%d]:%d y[%d,%d]:%d\n",
                    //     l, k, f[l][k], k + 1, r, f[k + 1][r], l, r, f[l][r], l, k, x[l][k], k + 1, r, x[k + 1][r], l, r, x[l][r], l, k, y[l][k], k + 1, r, y[k + 1][r], l, r, y[l][r]);
                }
            }

        }
    }
    cout << f[1][n];
    // system("pause");
    return 0;
}