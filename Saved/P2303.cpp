#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
long long n;
long long phi(long long x)
{
    long long ret = x;
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            ret = ret / i * (i - 1);
        }
    }
    if (x > 1)
        ret = ret / x * (x - 1);
    return ret;
}
long long getAns(long long x)
{
    long long ans = 0;
    for (long long d = 1; d * d <= x; d++)
    {
        if (x % d == 0 && d * d != x)
            ans += d * phi(x / d) + (x / d) * phi(d);
        else if (x % d == 0 && d * d == x)
        {
            ans += d * phi(x / d);
        }
    }
    return ans;
}
int main()
{
    scanf("%lld", &n);
    printf("%lld\n", getAns(n));
    END_PROGRAM
}