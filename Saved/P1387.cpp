#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
const int MAXN = 101;
int qzh[MAXN][MAXN];
int a[MAXN][MAXN];
int n, m;
int getRange(int x, int y, int len)
{
    return qzh[x + len - 1][y + len - 1] - qzh[x - 1][y + len - 1] - qzh[x + len - 1][y - 1] + qzh[x - 1][y - 1];
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = read();
            qzh[i][j] = a[i][j] + qzh[i][j - 1] + qzh[i - 1][j] - qzh[i - 1][j - 1];
        }
    }
    for (int len = min(n, m); len >= 1; len--)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            for (int j = 1; j + len - 1 <= m; j++)
            {
                if (getRange(i, j, len) == len * len)
                {
                    printf("%d\n", len);
                    END_PROGRAM
                }
            }
        }
    }
    END_PROGRAM
}