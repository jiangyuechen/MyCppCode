#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 505, MAXTIME = 4000550;
int n, m, a[MAXTIME], f[MAXTIME];
int tmp1[MAXTIME], tmp2[MAXTIME];
int t;  // 最后一个人等车的时间。
int value(int x, int y) {
    if (x < 0) x = 0;
    return y * (tmp1[y] - tmp1[x]) - (tmp2[y] - tmp2[x]);
}
double calc(int p, int q) {
    return 1.0 * (f[p] + tmp2[p] - f[q] - tmp2[q]) /
           ((tmp1[p] - tmp1[q]) == 0 ? 2e-9 : tmp1[p] - tmp1[q]);
}
int d[MAXTIME], l = 1, r = 0;
#define ANOTHER_SOLUTION
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, s; i <= n; i++) {
        scanf("%d", &s);
        t = max(t, s);
        a[s]++;
    }
    for (int i = 1; i < t + m; i++) {
        tmp1[i] = tmp1[i - 1] + a[i];
        tmp2[i] = tmp2[i - 1] + a[i] * i;
    }
#if !defined(ANOTHER_SOLUTION)
    memset(f, 127, sizeof(f));
#endif
    for (int i = 0; i < t + m; i++) {
        f[i] = value(-1, i);
    }
#if !defined(ANOTHER_SOLUTION)
    for (int i = m; i < t + m; i++) {
        for (int j = 0; j <= i - m; j++) {
            // printf("value(%d,%d):%d\n", j + 1, i, value(j + 1, i));
            f[i] = min(f[i], f[j] + value(j + 1, i));
        }
    }
#else
    for (int i = 0; i < t + m; i++) {
        // while (l < r && d[r] > i - m) r--;
        if (i - m >= 0) {
            while (l < r && calc(d[r], d[r - 1]) >= calc(i - m, d[r])) r--;
            d[++r] = i - m;
        }
        while (l < r && calc(d[l + 1], d[l]) <= i) l++;
        if (l <= r) f[i] = min(f[i], f[d[l]] + value(d[l], i));
    }
#endif
    int ans = 2147483647;
    for (int i = t; i < t + m; i++) {
        ans = min(ans, f[i]);
    }
    printf("%d\n", ans);
    system("pause");
}