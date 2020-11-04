#include <bits/stdc++.h>
using namespace std;

long long a, b;
int main()
{
    scanf("%lld%lld", &a, &b);
    long long ans = a * b - a - b;
    printf("%lld\n", ans);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}