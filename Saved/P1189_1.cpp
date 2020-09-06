#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int maxn = 50+5;
const char* dirs= "NESW";
struct Node {
    int x, y, d;
    Node() :x(0), y(0), d(0) {}
    Node(int _x, int _y, int _d) :
        x(_x), y(_y), d(_d) {}
};
int G[maxn][maxn];
int vis[maxn][maxn][1010];
int ans[maxn][maxn];
int op[1010];
int R, C, n, sx, sy;

inline bool inside(int x, int y) {
    return x>=0 && x<R && y>=0 && y<C && !G[x][y];
}
void bfs() {
    queue<Node> q;
    q.push(Node(sx, sy, 0));
    while (!q.empty())
    {
        Node u=q.front(); q.pop();
        int x=u.x, y=u.y, d=u.d, opt=op[d];
        if (d==n) {
            ans[x][y]=1; continue;
        }
        int dx=0, dy=0;
        if (opt==0)dx=-1; if (opt==1)dy=1; if (opt==2)dx=1; if (opt==3)dy=-1;
        x+=dx; y+=dy;
        while (inside(x, y)) {
            if (!vis[x][y][d+1]) {
                vis[x][y][d+1]=1;
                q.push(Node(x, y, d+1));
            }
            x+=dx; y+=dy;
        }
    }
}

void print_ans() {
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            if (G[i][j]==1) cout<<'X';
            else {
                if (ans[i][j]) cout<<'*';
                else cout<<'.';
            }
        }
        cout<<"\n";
    }
}

int main() {
    cin>>R>>C;
    char c;
    for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
        {
            cin>>c;
            if (c=='*') sx=i, sy=j;
            else
                if (c=='X') G[i][j]=1;
        }
    cin>>n;
    string s;
    for (int i=0;i<n;i++) {
        cin>>s;
        op[i]=strchr(dirs, s[0])-dirs;
    }

    bfs();
    print_ans();
    system("pause");
    return 0;
}
