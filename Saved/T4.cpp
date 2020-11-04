#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3000001;
int d[MAXN], n, f[MAXN], ans;
pair<int, int> range[MAXN];
#define ABS(a) ((a) < 0 ? -(a) : (a))
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
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return s * w;
}

inline bool inrange(int i, int x)
{
    return range[i].first <= x && x <= range[i].second;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        d[i] = read();
        range[i].first = max(1, i - d[i]);
        range[i].second = min(n, i + d[i]);
    }
    for (int k = 2; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j <= k - 1; j++)
            {
                if (inrange(i, j) && inrange(k, j) && k - j <= j - i)
                {
                    f[k]++;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans ^= f[i];
    }
    printf("%d", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}