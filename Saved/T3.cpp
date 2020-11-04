#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull a, p;
ull qPow(ull A, ull B)
{
    ull ans = 1ull, base = A % p;
    while (B)
    {
        if (B & 1ull)
        {
            ans = ans * base;
            ans %= p;
        }
        base = (base * base) % p;
        B >>= 1ull;
    }
    return ans % p;
}
int main()
{
    scanf("%llu%llu", &a, &p);
    for (register ull b = 0ull; b <= (2000000000000000000ull); b++)
    {
        ull A_B = qPow(a, b), B_A = qPow(b, a);
        if (A_B == B_A)
        {
            printf("%llu", b);
            break;
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}