#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n, ans;

int T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        cin >> n;
        ans = ll(n) * (n - ll(1)) / ll(2);
        cout << ans;
        puts("");
    }
    system("pause");
    return 0;
}