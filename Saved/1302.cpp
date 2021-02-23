#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 100010;
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
int t, n, a[MAXN];
int f[MAXN], g[MAXN];
// f[i] 表示在 i 天及之前进行一次买卖，能获得的最大利润。
// g[i] 表示在 i 天及之后进行一次买卖，能获得的最大利润。

int main() {
    t = read();
    while (t--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        int minl = 2147483647;
        for (int i = 1; i <= n; i++) {
            minl = min(minl, a[i]);
            f[i] = max(f[i - 1], a[i] - minl);
        }
        int maxr = -2147483647;
        for (int i = n; i >= 1; i--) {
            maxr = max(maxr, a[i]);
            g[i] = max(g[i + 1], maxr - a[i]);
        }
        int ans = f[1] + g[1];
        for (int i = 2; i <= n; i++) {
            ans = max(ans, f[i] + g[i]);
        }
        printf("%d\n", ans);
    }
    system("pause");
}