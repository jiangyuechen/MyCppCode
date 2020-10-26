#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100001;
int k, n;
vector<int> v;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    while (k--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        vector<int>::const_iterator first = v.begin() + a - 1;
        vector<int>::const_iterator last = v.begin() + b;
        vector<int> cut(first, last);
        v.erase(first, last);
        v.insert(v.begin() + c, cut.begin(), cut.end());
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", v[i]);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}