#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1001;
struct edge {
    int to, nxt;
} e[MAXN];
int head[MAXN], top;
int indgr[MAXN];
void add_edge(int a, int b) {
    // cout << a << "and" << b << "connected\n";
    e[++top].to = b;
    e[top].nxt = head[a];
    head[a] = top;
    indgr[b]++;
}
int n, a[MAXN], f[MAXN];
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

int main() {
    // ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    getchar();
    for (int i = 1; i <= n; i++) {
        string str;
        int tmp = 0;
        getline(cin, str);
        str += ' ';
        for (int j = 0; j < str.length(); j++) {
            char ch = str[j];
            if (ch >= '0' && ch <= '9') {
                tmp = tmp * 10 + ch - '0';
            } else {
                if (tmp > i) add_edge(i, tmp);
                tmp = 0;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indgr[i]) {
            f[i] = a[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            f[y] = max(f[y], f[x] + a[y]);
            indgr[y]--;
            if (!indgr[y]) q.push(y);
        }
    }
    int ans = f[1];
    for (int i = 2; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    // system("pause");
}
