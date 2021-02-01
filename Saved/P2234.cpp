#include <bits/stdc++.h>
using namespace std;
const int MAXN = 32768;
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
#define ABS(x) ((x) < 0 ? -(x) : (x))
struct Dat
{
    int day, val;
} a[MAXN];
int n, ans;
int Find(int x)
{
    if (a[x].day == 1)
        return a[x].val;
    int ret1 = INT32_MAX, ret2 = INT32_MAX;
    for (int i = x - 1; i >= 1; i--)
        if (a[i].day < a[x].day)
        {
            ret1 = ABS(a[i].val - a[x].val);
            break;
        }
    for (int i = x + 1; i <= n; i++)
        if (a[i].day < a[x].day)
        {
            ret2 = ABS(a[i].val - a[x].val);
            break;
        }
    return ret1 < ret2 ? ret1 : ret2;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].val = read();
        a[i].day = i;
    }
    sort(a + 1, a + n + 1, [](Dat &a, Dat &b) { return a.val < b.val; });
    for (int i = 1; i <= n; i++)
        ans += Find(i);
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}