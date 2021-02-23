#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 501;
int n; // 结点数量
int q; // 要保留的苹果数目
struct edge {
    int to, v, nxt;
} e[MAXN];
int head[MAXN], top, f[MAXN][MAXN]; // f[i][j] 表示以 i 为根的子树上保留 j 根树枝，能获得的最大价值。
void add_edge(int a, int b, int k) {
    e[++top].to = b;
    e[top].v = k;
    e[top].nxt = head[a];
    head[a] = top;
}
void Dfs(int now, int father) {
    for (int i = head[now]; i; i = e[i].nxt) {
        int down = e[i].to;
        if (down == father)
            continue;
        Dfs(down, now);
        for (int j = q; j >= 1; j--) {
            for (int k = 0; k <= j - 1; k++) {
                f[now][j] = max(f[now][j], e[i].v + f[down][k] + f[now][j - k - 1]);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &q);
    switch (1) {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
    for (int i = 1, x, y, z; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add_edge(x, y, z);
        add_edge(y, x, z);
    }
    Dfs(1, -1);
    return 0;
}