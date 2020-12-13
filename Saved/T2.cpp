#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1000001;
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
int a[MAXN], n, q;
int main()
{
    n = read();
    q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    if ((n <= 100000 && q <= 100000))
    {
        while (q--)
        {
            int l = read(), r = read();
            int ans = 0;
            for (int i = 1; i <= r - l + 1; i++)
            {
                int times = 0;
                for (int j = l; j <= r; j++)
                {
                    if (a[j] == i)
                        times++;
                }
                if (times == i)
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    else
    {
        while (q--)
        {
            int l = read(), r = read();
            if (r - l + 1 == a[l])
                printf("1\n");
            else
                printf("0\n");
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}