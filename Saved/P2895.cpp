#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define UNABLE_TO_CHANGE
#define MIN(i,j) ((i)<(j)?(i):(j))
/*
* @brief get the factorial (using recursion).
* @param s get the result : s!
*/
int func(int s){
    if(s==1) return 1;
    else return s*func(s-1);
}
const int MAXN = 305;
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
bool vis[MAXN][MAXN];
UNABLE_TO_CHANGE int met[MAXN][MAXN];
int n;
struct cond
{
    int x, y;
    int t;
};
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int bfs()
{
    queue<cond> q;
    q.push((cond){0, 0, 0});
    vis[0][0] = true;
    while (!q.empty())
    {
        cond now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.x + dx[i], ny = now.y + dy[i], nt = now.t + 1;
            if(nx<0||ny<0) continue;
            if(met[nx][ny]==0x3f3f3f3f) return nt;
            if(nt<met[nx][ny]&&vis[nx][ny]==false){
                vis[nx][ny]=true;
                q.push(cond{nx,ny,nt});
            }
        }
    }
    return -1;
}
int main()
{
    memset(met, 0x3f, sizeof(met));
    memset(vis, 0, sizeof(vis));
    n = read();
    for (int i = 1, x, y, k; i <= n; i++)
    {
        x = read();
        y = read();
        k = read();
        met[x][y]=MIN(met[x][y],k);
        for(int j=0;j<4;j++){
            if(x+dx[j]>=0&&y+dy[j]>=0) met[x+dx[j]][y+dy[j]]=MIN(met[x+dx[j]][y+dy[j]],k);
        }
    }
    printf("%d\n", bfs());
    system("pause");
    return 0;
}