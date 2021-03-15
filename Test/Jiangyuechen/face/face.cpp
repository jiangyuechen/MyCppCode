#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2000005, MAXM = 20005;
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
int n, m;
struct Dot {
    int x, y, v;
} d[MAXN];
bool DotCompare(const Dot& a, const Dot& b) { return a.v < b.v; }

double dist(const Dot& a, const Dot& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist(int xa, int ya, int xb, int yb) {
    return sqrt((ya - yb) * (ya - yb) + (xa - xb) * (xa - xb));
}

int main() {
    freopen("face.in", "r", stdin);
    freopen("face.out", "w", stdout);
    n = read();
    m = read();

    for (int i = 1; i <= n; i++) {
        d[i].x = read();
        d[i].y = read();
        d[i].v = read();
    }

    sort(d + 1, d + n + 1, DotCompare);
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read(), v = read();
        Dot best;
        double best_dist = -1e9;
        for (int i = 1; i <= n && v <= d[i].v; i++) {
            int now_dist = dist(x, y, d[i].x, d[i].y);
            if (now_dist > best_dist) {
                best_dist = now_dist;
                best = d[i];
            }
        }
        printf("%d %d %d\n", d[i].x, d[i].y, d[i].v);
    }
    return 0;
}