#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
const int MAXN2 = 1000010;
const int MAXN = 1001;
using namespace std;
int n, m;
struct edge {
    int to, nxt;
} e[MAXN2];
int head[MAXN], top;
int indgr[MAXN], outdgr[MAXN];
int connected[MAXN][MAXN];
void add_edge(int a, int b) {
    if (connected[a][b]) return;
    connected[a][b] = true;
    // printf("%d %d\n", a, b);
    e[++top].to = b;
    e[top].nxt = head[a];
    head[a] = top;
    indgr[b]++;
    outdgr[a]++;
}
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
bool ok[MAXN][MAXN];
vector<int> upper, lower;
namespace Toposort {
    int f[MAXN];
    queue<int> q;
    int Toposort() {
        for (int i = 1; i <= n; i++) {
            if (!indgr[i]) {
                f[i] = 1;
                q.push(i);
            } else
                f[i] = 0;
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = head[x]; i; i = e[i].nxt) {
                int y = e[i].to;
                f[y] = max(f[y], f[x] + 1);
                indgr[y]--;
                if (!indgr[y]) q.push(y);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!outdgr[i]) ans = max(ans, f[i]);
        }
        return ans;
    }
}  // namespace Toposort
int start[MAXN], finish[MAXN];
int main() {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) {
        int s = read();
        for (int j = 1; j <= s; j++) {
            int x = read();
            ok[i][x] = true;
            if (j == 1) start[i] = x;
            if (j == s) finish[i] = x;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = start[i]; j <= finish[i]; j++) {
            if (ok[i][j])
                upper.push_back(j);
            else
                lower.push_back(j);
        }
        for (int p : lower) {
            for (int q : upper) {
                add_edge(p, q);
            }
        }
        lower.clear();
        upper.clear();
    }
    printf("%d\n", Toposort::Toposort());
    // system("pause");
}