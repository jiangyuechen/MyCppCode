#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 100005;
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
int n, m, u, v, t, q;
double p;
priority_queue<int> Q;
int main()
{
    n = read();
    m = read();
    q = read();
    u = read();
    v = read();
    t = read();
    p = (double)u / v;
    for (int i = 1; i <= n; i++)
    {
        Q.push(read());
    }
    for (int i = 0; i < m; i++)
    {
        int x = Q.top() + q * i;
        Q.pop();
        int ax = floor(p * (double)x), bx = x - ax;
        ax -= q * (i + 1);
        bx -= q * (i + 1);
        if ((i + 1) % t == 0)
        {
            printf("%d ", x);
        }
        Q.push(ax);
        Q.push(bx);
    }
    puts("");
    for (int i = 1; !Q.empty(); i++)
    {
        if (i % t == 0)
        {
            printf("%d ", Q.top() + q * m);
        }
        Q.pop();
    }
    END_PROGRAM
}