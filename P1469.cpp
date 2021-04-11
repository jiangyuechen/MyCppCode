#include <cstdio>
#include <iostream>
using namespace std;

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
int n, ans;
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        ans = ans ^ read();
    }
    printf("%d\n", ans);
}