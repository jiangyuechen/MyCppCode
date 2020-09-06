#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
#pragma endregion

long long n, k, ans;

int main()
{
    scanf("%lld%lld", &n, &k);
    ans = n * k;
    for (long long l = 1, r; l <= n; l = r + 1)
    {
        int t = k / l;
        r = (t == 0) ? n : min(n, k / t);
        ans -= t * (r - l + 1) * (l + r) / 2;
    }
    printf("%lld\n", ans);
    END_PROGRAM
}