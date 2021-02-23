#include <cstdio>
#include <iostream>
using namespace std;
int n, k, ans;
void Dfs(int cnt, int step, int downlim)
{
    if (cnt > n)
        return;
    if (cnt < n && step == k)
        return;
    if ((k - step) * downlim + cnt > n)
        return;
    if (cnt == n && step == k)
    {
        ans++;
        return;
    }
    for (int i = downlim; i <= n - cnt; i++)
    {
        Dfs(cnt + i, step + 1, i);
    }
}
int main()
{
    cin >> n >> k;
    Dfs(0, 0, 1);
    cout << ans << '\n';
    return 0;
}