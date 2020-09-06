#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 55, MAXK=1005;
#pragma endregion

#pragma region STRUCTS
struct condit
{
    int x, y;
    int now_in_direct;
    condit() :x(0), y(0), now_in_direct(0) {}
    condit(int _x, int _y, int _n) :
        x(_x), y(_y), now_in_direct(_n) {}
};
#pragma endregion
#pragma region DATA
int dx[4]={ -1, 0, 1, 0 }, dy[4]={ 0, 1, 0, -1 };
const int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;

int n, m, k, startx, starty;
int directions[MAXK];
bool vis[MAXN][MAXN][MAXK];
bool map[MAXN][MAXN];
bool End[MAXN][MAXN];
#pragma endregion
#pragma region FUNCTIONS
inline bool isok(int x, int y) {
    return x>=1&&x<=n&&y>=1&&y<=m&&(!map[x][y]);
}
void bfs(condit start) {
    queue<condit> q;
    q.push(start);
    while (!q.empty()) {
        condit now=q.front();
        q.pop();
        int dir=now.now_in_direct;
        int x=now.x, y=now.y;
        if (dir==k+1) {
            End[now.x][now.y]=true;
            continue;
        }
        int nx=dx[directions[dir]], ny=dy[directions[dir]];
        x+=nx;y+=ny;
        while (isok(x, y)) {
            if (!vis[x][y][dir+1]) {
                vis[x][y][dir+1]=true;
                q.push(condit(x, y, dir+1));
            }
            x+=nx;y+=ny;
        }
    }
}
#pragma endregion
int main()
{
    cin>>n>>m;
    char ch;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>ch;
            if (ch=='X') map[i][j]=true;
            else if (ch=='*') {
                startx=i;
                starty=j;
            }
        }
    }
    cin>>k;
    string str;
    for (int i=1;i<=k;i++) {
        cin>>str;
        switch (str[0]) {
        case 'N':
            directions[i]=NORTH;
            break;
        case 'W':
            directions[i]=WEST;
            break;
        case 'S':
            directions[i]=SOUTH;
            break;
        case 'E':
            directions[i]=EAST;
            break;
        }
    }
    bfs(condit(startx, starty, 1));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (End[i][j]) cout<<'*';
            else {
                if (map[i][j]) cout<<'X';
                else cout<<'.';
            }
        }
        cout<<endl;
    }
    END_PROGRAM
}