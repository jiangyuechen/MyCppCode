#include <bits/stdc++.h>
using namespace std;
const int MAXN = 21;
int n, m;
int a[MAXN];
int f[1 << MAXN];
int popcount(int x)
{
    int cnt = 0;
    while (x)
    {
        x = x & (x - 1);
        cnt++;
    }
    return cnt;
}
int ans = -1;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < (1 << n); i++)
    {
        if (popcount(i) == n - m)
        {
            bitset<3001> upd; // upd[i]==1 <=> 重量 i 能被称出来
            upd.set(0, 1);    // 重量为 0 的能称出来
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    upd |= upd << a[j]; // upd:目前能称出来的重量 upd<<a[j]:新的能称出来的重量
                }
            }
            ans = max(ans, int(upd.count()));
        }
    }
    printf("%d\n", ans - 1);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}