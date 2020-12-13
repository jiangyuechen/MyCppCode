#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 500001;
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
int n, a[MAXN];
int cf[MAXN];

int random(int n)
{
    return (long long)rand() * rand() % n;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    if (n == 1)
    {
        puts("simple");
        printf("%d\n", 1);
        printf("%d %d\n", 0, a[1]);
        return 0;
    }
    else if (n == 2)
    {
        puts("simple");
        printf("%d\n", n - 1);
        printf("%d %d\n", a[2], a[1]);
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        cf[i] = a[i + 1] - a[i];
    }
    for (int i = 2; i < n; i++)
    {
        if (cf[i - 1] < cf[i])
        {
            puts("nice");
#ifndef ONLINE_JUDGE
            system("pause");
#endif
            return 0;
        }
    }
    int tot = 0;
    puts("simple");
    printf("%d\n", n - 1);
    for (int i = 1; i < n - 1; i++)
    {
        int x = random(a[n]);
        tot += x;
        printf("%d %d\n", x, x - cf[i]);
    }
    int last = a[n] - tot;
    printf("%d %d\n", last, last - cf[n - 1]);

#ifndef ONLINE_JUDGE
    system("pause");
#endif
}