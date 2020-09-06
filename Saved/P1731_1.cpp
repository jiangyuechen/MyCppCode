#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define INF 2147483647
using namespace std;
int remain_max_surface[201], remain_max_volume[201], m, n, ans;
void dfs(int volume_chosen, int surface, int remain_floor, int r, int h)
{
    if (remain_floor == 0)
    {
        if (volume_chosen == n && surface < ans)
            ans = surface;
        return;
    }

    if (volume_chosen + remain_max_volume[remain_floor - 1] > n)
        return;
    if (surface + remain_max_surface[remain_floor - 1] > ans)
        return;
    if (2 * (n - volume_chosen) / r + surface >= ans)
        return;
    for (int i = r - 1; i >= remain_floor; i--)
    {
        if (remain_floor == m)
            surface = i * i;
        int max_high = min((n - volume_chosen - remain_max_volume[remain_floor - 1]) / (i * i), h - 1);
        for (int j = max_high; j >= remain_floor; j--) //枚举高
            dfs(volume_chosen + i * i * j, surface + 2 * i * j, remain_floor - 1, i, j);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    ans = INF;
    remain_max_surface[0] = remain_max_volume[0] = 0;
    for (int i = 1; i < 21; i++)
    {
        remain_max_surface[i] = remain_max_surface[i - 1] + 2 * i * i;
        remain_max_volume[i] = remain_max_volume[i - 1] + i * i * i;
    }
    dfs(0, 0, m, n + 1, n + 1);
    printf("%d\n", ans == 2147483647 ? 0 : ans);
    system("pause");
    return 0;
}