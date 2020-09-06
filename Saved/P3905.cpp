#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 101;
#pragma endregion

int dist[MAXN][MAXN];
int a[MAXN][MAXN];
int n, m, d, A, B;

int main()
{
    memset(dist, 0x3f, sizeof(dist));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        a[x][y] = a[y][x] = k;
        dist[x][y] = dist[y][x] = 0;
    }
    scanf("%d", &d);
    for (int i = 1; i <= d; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        dist[x][y] = dist[y][x] = a[x][y];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    scanf("%d%d", &A, &B);
    printf("%d\n", dist[A][B]);
    END_PROGRAM
}