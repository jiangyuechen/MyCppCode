#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 100005, MAXM = 500005;
#define SECOND_FLOOR(x) (n+x)
#define THIRD_FLOOR(x) (2*n+x)
int ver[3*MAXM], nxt[3*MAXM], head[3*MAXN], edge[3*MAXM], tot;
void add_edge(int u, int v, int w) {
    ver[++tot]=v;
    edge[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot;
}
int dist[3*MAXN];
bool v[3*MAXN];
int SPFA(int start, int end) {
    memset(dist, -0x3f, sizeof(dist));
    memset(v, false, sizeof(v));
    queue<int> q;
    dist[start]=0;
    v[start]=true;
    q.push(start);
    while (!q.empty()) {
        int x=q.front();
        q.pop();
        v[x]=false;
        for (int i=head[x];i;i=nxt[i]) {
            int y=ver[i], z=edge[i];
            if (dist[y]<dist[x]+z) {
                dist[y]=dist[x]+z;
                if (!v[y]) q.push(y), v[y]=true;
            }
        }
    }
    return dist[end];
}
int n, m;
int a[MAXN];
void ultra_add_edge(int x, int y) {
    int val=a[y];
    add_edge(x, y, 0);
    add_edge(x, SECOND_FLOOR(y), -val);
    add_edge(SECOND_FLOOR(x), SECOND_FLOOR(y), 0);
    add_edge(SECOND_FLOOR(x), THIRD_FLOOR(y), val);
    add_edge(THIRD_FLOOR(x), THIRD_FLOOR(y), 0);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
    }
    for (int i=1, x, y, z;i<=m;i++) {
        scanf("%d%d%d", &x, &y, &z);
        ultra_add_edge(x, y);
        if (z==2) ultra_add_edge(y, x);
    }
    add_edge(n, 0, 0);
    add_edge(2*n, 0, 0);
    add_edge(3*n, 0, 0);
    printf("%d\n", SPFA(1, 0));
    system("pause");
    return 0;
}