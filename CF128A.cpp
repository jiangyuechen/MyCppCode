#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 10;
int sx, sy, fx, fy;
int dx[9] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
bool obstacle[MAXN][MAXN];
bool dfs(int x, int y, int foot)
{
    if (x < 1 || x > 8 || y < 1 || y > 8)
        return false;
    if (foot == 8) // !所有障碍物都掉出去了，肯定能过
        return true;
    if (x == fx && y == fy)
        return true;
    if (obstacle[x - foot][y] || obstacle[x - foot + 1][y])
        return false;
    for (int i = 0; i <= 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (dfs(nx, ny, foot + 1))
            return true;
    }
    return false;
}
int main()
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'S')
                obstacle[i][j] = true;
            else if (ch == 'M')
            {
                sx = i;
                sy = j;
            }
            else if (ch == 'A')
            {
                fx = i;
                fy = j;
            }
        }
    }
    if (dfs(sx, sy, 0))
        puts("WIN");
    else
        puts("LOSE");
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}