#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 105;
char str[MAXN], n;
int f[MAXN][MAXN];
// f[l][r] 表示字符串的子字符串 [l~r] 有多少括号已经配对了。
// 目标：strlen - f[1][strlen]

int main() {
    cin >> str + 1;
    n = strlen(str + 1);

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
            if ((str[l] == '(' && str[r] == ')') || (str[l] == '[' && str[r] == ']')) {
                f[l][r] = max(f[l][r], f[l + 1][r - 1] + 2);
            }
            for (int k = l; k < r; k++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
            }
        }
    }
    cout << n - f[1][n];
}
