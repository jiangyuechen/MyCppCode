#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 200001;
int ver[MAXN], edge[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
int n, m;
namespace SPFA {
    int dist[MAXN], vis[MAXN], cnt[MAXN];
    queue<int> q;
    bool spfa(int start) {
        memset(dist, 0x3f, sizeof(dist));
        dist[start]=0;
        q.push(start);
        vis[start]=1;
        cnt[start]++;
        while (!q.empty()) {
            int x=q.front();
            q.pop();
            vis[x]=0;
            for (int i=head[x];i;i=nxt[i]) {
                int y=ver[i], w=edge[i];
                if (dist[y]>dist[x]+w) {
                    dist[y]=dist[x]+w;
                    if (!vis[y]) {
                        vis[y]=1;
                        cnt[y]++;
                        if (cnt[y]>=n+1) {
                            return false;
                        }
                        q.push(y);
                    }
                }
            }
        }
        return true;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1, x, y, z;i<=m;i++) {
        scanf("%d%d%d", &x, &y, &z);
        add_edge(y, x, z);
    }
    for (int i=1;i<=n;i++) {
        add_edge(0, i, 0);
    }
    if (!SPFA::spfa(0)) {
        printf("NO SOLUTION\n");
        END_PROGRAM
    }
    else
    {
        int mmin=0x3f3f3f3f;
        for (int i=1;i<=n;i++) mmin=min(mmin, SPFA::dist[i]);
        for (int i=1;i<=n;i++) {
            printf("%d\n", SPFA::dist[i]-mmin);
        }
        END_PROGRAM
    }
}