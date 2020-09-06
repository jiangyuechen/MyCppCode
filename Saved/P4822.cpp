#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

#define FLOOR(x,floor) ((x)+(n)*(floor-1))

/*
·分层图最短路题目：
    能够使用k次”魔法“，使得某条道路权值改变为w'。
    1.建立k+1层分层图，设i层的点u,v对应i+1层的点u',v'。
    对于<u,v> = w,第i层内部连<u,v> = w,第i+1层内部连
    <u',v'> = w,第i到i+1层连<u,v'> = w'。
    若题目要求从1走到n，则每个 pn (1<=p<=k+1)点都要连向一个
    超级终点N。求1~N的最短路即可。
*/

using namespace std;
const int MAXN = 10000004, MAXM = 10000004;
int ver[MAXN], edge[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
namespace Dijkstra {
    bool vis[MAXN];
    int dist[MAXN];
    priority_queue<pair<int, int>> q;
    int dij(int start, int end) {
        memset(vis, 0, sizeof(vis));
        memset(dist, 0x3f, sizeof(dist));
        dist[start]=0;
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            int x=q.top().second;
            q.pop();
            for (int i=head[x];i;i=nxt[i]) {
                int y=ver[i], w=edge[i];
                if (dist[y]>dist[x]+w) {
                    dist[y]=dist[x]+w;
                    q.push(make_pair(-dist[y], y));
                }
            }
        }
        return dist[end];
    }
}
int n, m, k;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1, x, y, z;i<=m;i++) {
        scanf("%d%d%d", &x, &y, &z);
        for (int f=1;f<=k+1;f++) {
            add_edge(FLOOR(x, f), FLOOR(y, f), z);
            //add_edge(FLOOR(y, f), FLOOR(x, f), z);
        }
        for (int f=1;f<=k;f++) {
            add_edge(FLOOR(x, f), FLOOR(y, f+1), 0);
            add_edge(FLOOR(y, f), FLOOR(x, f+1), 0);
        }
    }
    for (int f=1;f<=k+1;f++) {
        add_edge(FLOOR(n, f), 0, 0);
    }
    int ans=Dijkstra::dij(1,0);
    printf("%d\n", ans==0x3f3f3f3f?-1:ans);
    system("pause");
    return 0;
}  