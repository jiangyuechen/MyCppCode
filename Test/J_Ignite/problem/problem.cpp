#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n, ans;

int T;
int main()
{
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        cin >> n;
        ans = ll(n) * (n - ll(1)) / ll(2);
        cout << ans;
        puts("");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}