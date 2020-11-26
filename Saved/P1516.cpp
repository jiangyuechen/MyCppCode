#include <bits/stdc++.h>
using namespace std;
long long x, y, m, n, L;
inline long long gcd(long long a, long long b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
inline void exgcd(long long a, long long b, long long &_x, long long &_y)
{
    if (b == 0)
    {
        _x = 1;
        _y = 0;
        return;
    }
    exgcd(b, a % b, _y, _x);
    _y -= a / b * _x;
}
// x + pm === y + pn (mod L)
// p (m - n) === y - x (mod L)
// ap === b (mod L)
// ap mod L == b
// find an q that ap + Lq = b.
int main()
{
    scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L);
    long long b = n - m, a = (x - y);
    if (b < 0)
    {
        b = -b;
        a = -a;
    }
    long long f = gcd(b, L);
    if (a % f != 0)
    {
        printf("Impossible\n");
    }
    else
    {
        long long p, q;
        exgcd(b, L, p, q);
        printf("%lld\n", ((p * (a / f)) % (L / f) + (L / f)) % (L / f));
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}