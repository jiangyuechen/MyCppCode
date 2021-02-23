#include <iostream>
using namespace std;
const int MAXN = 50005;
int n;
struct edge {
    int to, nxt;
}e[MAXN << 1];
int head[MAXN], top;
void add_edge(int a, int b) {
    e[++top].to = b;
    e[top].nxt = head[a];
    head[a] = top;
}
inline int GetCnt(int x) {
    int ret = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret += i;
            if (i * i != n) {
                ret += n / i;
            }
        }
    }
    return ret - x;
}
int d[MAXN], ans;
void dp(int x, int father) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == father) continue;
        dp(y, x);
        ans = max(ans, d[x] + d[y] + 1);
        d[x] = max(d[x], d[y] + 1);
    }
}
int main() {
    cin >> n;
    for (int x = 2; x <= n; x++) {
        int y = GetCnt(x);
        if (y < x) {
            add_edge(y, x);
            add_edge(x, y);
        }
    }
    dp(1, -1);
    printf("%d\n", ans);
    system("pause");

}