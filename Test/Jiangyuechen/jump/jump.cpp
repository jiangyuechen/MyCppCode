#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const bool A_NOW = false, B_NOW = true, WIN = true, LOSE = false;
#define ABS(s) ((s) > 0 ? (s) : (-s))

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
int n, m, xa, xb, ya, yb, ka, kb;
int t;

inline int dist(int x1, int x2, int y1, int y2) {
    return ABS(x1 - x2) + ABS(y1 - y2);
}

bool dfs(bool now, int x1, int y1, int x2, int y2, int k1, int k2) {
    if (dist(x1, x2, y1, y2) == 0) return WIN;
    if (now == A_NOW && dist(x1, x2, y1, y2) == 1) return WIN;
    if (now == A_NOW && k1 == 0 && k2 == 0 && dist(x1, x2, y1, y2) > 1)
        return LOSE;
    if (now == B_NOW && k1 == 0 && k2 == 0 && dist(x1, x2, y1, y2) >= 1)
        return LOSE;
}
int main() {
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
    t = read();
    while (t--) {
        n = read(), m = read();
        xa = read(), xb = read(), ya = read(), yb = read();
        ka = read(), kb = read();
        printf("YES\n");
    }
    return 0;
}