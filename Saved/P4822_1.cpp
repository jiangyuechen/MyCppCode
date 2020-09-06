#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

#define FLOOR(x,floor) ((x)+(n)*(floor-1))

using namespace std;
const int MAXN = 50004, MAXM = 50004;
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
            for (int i=head[x];i; i=nxt[i]) {
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
        scanf("%d %d%d", &x, &y, &z);
        for (int f=1;f<=k;f++) {
            add_edge(FLOOR(x, f), FLOOR(y, f), z);
            add_edge(FLOOR(y, f), FLOOR(x, f), z);
        }
        for (int f= 1;f<k;f++) {
            add_edge(FLOOR(x, f), FLOOR(y, f+1), z/2);
            add_edge(FLOOR(y, f), FLOOR(x, f+1), z/2);
        }
    }
    for (int f=1;f<=k;f++) {
        add_edge(FLOOR(n, f), 0, 0);
    }
    printf("%d\n", Dijkstra::dij(1, 0));
    system("pause");
    return 0;
}