#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int v;
char mp[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool vis[MAXN][MAXN];
struct cond
{
    int x, y;
    bool have_sunflower;
    bool have_sword;
    int dist;
    cond() : x(0), y(0), have_sunflower(0), have_sword(0), dist(0) {}
    cond(int _x, int _y, int _su, int _sw, int _d)
        : x(_x), y(_y), have_sunflower(_su), have_sword(_sw), dist(_d) {}
};
int n, m;
int startx, starty, endx, endy;
bool range_access(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int xijian_x[MAXN], xijian_y[MAXN], xijian_count;
void bfs()
{
    queue<cond> q;
    cond st(startx, starty, false, false, 0);
    q.push(st);
    while (!q.empty())
    {
        cond now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            cond nxt = now;
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (!range_access(nx, ny) || vis[nx][ny])
                continue;
            switch (mp[nx][ny])
            {
            case '0':
            case 'M':
                nxt.x = nx, nxt.y = ny, nxt.dist += 1;
                q.push(nxt);
                break;
            case '1':
                if (nxt.have_sword == true)
                {
                    nxt.x = nx, nxt.y = ny, nxt.dist += 1;
                    q.push(nxt);
                }
                break;
            case '2':
                if (nxt.have_sword == true)
                {
                    nxt.x = nx, nxt.y = ny, nxt.dist += 1;
                    q.push(nxt);
                    break;
                }
                else
                {
                    nxt.x = nx, nxt.y = ny, nxt.dist += 4;
                    q.push(nxt);
                    break;
                }
            case '3':
                if (nxt.have_sword == true || nxt.have_sunflower == true)
                {
                    nxt.x = nx, nxt.y = ny, nxt.dist += 1;
                    q.push(nxt);
                    break;
                }
                else
                {
                    nxt.x = nx, nxt.y = ny, nxt.dist += 9;
                    q.push(nxt);
                    break;
                }
            case '4':
                nxt.x = nx, nxt.y = ny, nxt.dist += 1;
                q.push(nxt);
                nxt.have_sunflower = true;
                q.push(nxt);
                break;
            case '5':
                nxt.x = nx, nxt.y = ny;
                nxt.dist = now.dist + 1;
                q.push(nxt);
                nxt.dist = now.dist + 1 + 5;
                nxt.have_sunflower = true;
                q.push(nxt);
                break;
            case 'X':
                nxt.x = nx, nxt.y = ny;
                nxt.dist = now.dist + 1;
                q.push(nxt);
                for (int i = 1; i <= xijian_count; i++)
                {
                    nxt.x = xijian_x[i], nxt.y = xijian_y[i];
                    nxt.dist = now.dist + 2;
                    q.push(nxt);
                }
                break;
            default:
                break;
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", mp[i] + 1);
}