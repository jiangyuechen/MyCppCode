#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 105;
int a[MAXN], vis[MAXN];
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (a[i] + a[j] == a[k] && !vis[k])
                {
                    vis[k] = true;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}