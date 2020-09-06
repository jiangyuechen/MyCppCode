#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

#define FLOOR(x,floor) ((x)+(n)*(floor-1))


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
        q.push(make_pair(0, start));
        while (!q.empty()) {
            int x=q.top().second;
            q.pop();
            if (vis[x]) continue;
            vis[x]=true;
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
int s, t;
#define SUPER_START (n*(k+1)+1)
#define SUPER_END (n*(k+1)+2);
int main() {
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    for (int i=1, x, y, z;i<=m;i++) {
        scanf("%d%d%d", &x, &y, &z);
        for (int f=0;f<=k;f++) {
            add_edge(FLOOR(x, f+1), FLOOR(y, f+1), z);
            add_edge(FLOOR(y, f+1), FLOOR(x, f+1), z);
            add_edge(FLOOR(x, f), FLOOR(y, f+1), 0);
            add_edge(FLOOR(y, f), FLOOR(x, f+1), 0);
        }
    }
    for (int f=1;f<=k;f++) {
        add_edge(FLOOR(t, f), FLOOR(t, f+1), 0);
    }
    printf("%d\n", Dijkstra::dij(s, t+k*n));
    system("pause");
    return 0;
}