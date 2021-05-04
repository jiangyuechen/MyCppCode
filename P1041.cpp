#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 10001;
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
struct Edge {
    int to, nxt;
} e[MAXN];
int head[MAXN], top;
void add_edge(int a, int b) {
    e[++top].to = b;
    e[top].nxt = head[a];
    head[a] = top;
}
int n, p;
int dp[MAXN];
int dfs(int x) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
    }
}
int main() {
    n = read();
    p = read();
    while (p--) {
        int x = read(), y = read();
        add_edge(x, y);
        add_edge(y, x);
    }
}