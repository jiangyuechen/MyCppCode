#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int n, m;
int a[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        for (int j = x; j <= y; j++)
        {
            a[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 1)
        {
            printf("%d %d", i, a[i]);
#ifndef ONLINE_JUDGE
            system("pause");
#endif
            return 0;
        }
    }
    printf("OK");
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}