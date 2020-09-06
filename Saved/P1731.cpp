#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
const int MAXN = 200;
int ans = 2147483647;
int N, M;
int remain_max_of_surface[MAXN];
int remain_max_of_volume[MAXN];
void dfs(int floor_remain, int volume_chosen, int surface_area, int prev_chosen_H, int prev_chosen_R)
{
    if (floor_remain == 0 && volume_chosen == N)
    {
        ans = min(ans, surface_area);
        return;
    }
    if (surface_area + remain_max_of_surface[floor_remain - 1] > ans)
        return;
    if (volume_chosen + remain_max_of_volume[floor_remain - 1] > N)
        return;
    if (2 * (N - volume_chosen) / prev_chosen_R + surface_area >= ans)
        return;
    for (int r = prev_chosen_R - 1; r >= floor_remain; r--)
    {
        if (floor_remain == M)
            surface_area = r * r;
        int max_high = min((N - volume_chosen - remain_max_of_volume[floor_remain - 1]) / (r * r), prev_chosen_H - 1);
        for (int h = max_high; h >= floor_remain; h--)
        {
            dfs(floor_remain - 1, volume_chosen + r * r * h, surface_area + 2 * r * h, h, r);
        }
    }
}

int main()
{
    N = read();
    M = read();
    remain_max_of_surface[0] = remain_max_of_volume[0] = 0;
    for (int i = 1; i <= 20; i++)
    {
        remain_max_of_surface[i] = remain_max_of_surface[i - 1] + 2 * i * i;
        remain_max_of_volume[i] = remain_max_of_volume[i - 1] + i * i * i;
    }
    dfs(M, 0, 0, N + 1, N + 1);
    printf("%d\n", ans == 2147483647 ? 0 : ans);
    END_PROGRAM
}