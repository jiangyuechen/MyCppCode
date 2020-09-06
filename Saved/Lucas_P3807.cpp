#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
typedef unsigned long long ull;
const int MAXN = 100005;
ull p = 0;

ull factor[MAXN];

ull quickPower(ull a, ull b)
{
    a %= p;
    ull ans = 1, base = a;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * base % p;
        }
        base = base * base % p;
        b >>= 1;
    }
    return ans;
}
ull C(ull n, ull m)
{
    if (m > n)
        return 0;
    return factor[n] * quickPower(factor[m], p - 2) % p * quickPower(factor[n - m], p - 2) % p;
}
ull lucas(ull n, ull m)
{
    if (m == 0)
        return 1;
    return lucas(n / p, m / p) * C(n % p, m % p) % p;
}
int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ull n, m;
        scanf("%lld%lld%lld", &n, &m, &p);
        factor[0] = 1;
        for (ull i = 1; i <= p; i++)
        {
            factor[i] = factor[i - 1] * i % p;
        }
        printf("%lld\n", lucas(n + m, n));
    }
    END_PROGRAM
}