#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const ll MAXN = 500005;
const ll MOD = 998244353;

inline ll read() {
    ll s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
ll n, q, m;
ll a[MAXN], k[MAXN];

ll C[300][300];

int main() {
    freopen("plus.in", "r", stdin);
    freopen("plus.out", "w", stdout);
    C[1][1] = C[1][0] = 1;
    for (int i = 2; i <= 1 << 8; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
    n = read();
    q = read();
    m = read();
    for (int i = 1; i <= q; i++) {
        k[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    while (m--) {
        int pl = read(), j = read(), c = read();
        for (int i = pl; i <= n; i++) {
            a[i] += c * (C[k[j] + i - pl][k[j]]);
            a[i] %= MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a[i]);
    }
    // system("pause");
}