#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n;
ull ans;

int main()
{

    scanf("%llu", &n);
    for (register ull i = 1ull; i <= n; i++)
    {
        for (register ull j = 1ull; j <= n; j++)
        {
            if (i * j < n)
                ans += i * j;
            else
            {
                ans += (n - j + 1ull) * n;
                break;
            }
        }
    }
    printf("%llu\n", ans);

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}