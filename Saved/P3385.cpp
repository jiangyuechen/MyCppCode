#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 10005;
int ver[MAXN], edge[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
inline void reset() {
    memset(ver, 0, sizeof(ver));
    memset(edge, 0, sizeof(edge));
    memset(head, 0, sizeof(head));
    memset(nxt, 0, sizeof(nxt));
    tot=0;
}
int T, m, n;
int dist[MAXN], cnt[MAXN];
bool inque[MAXN];
queue<int> q;
inline bool spfa() {
    memset(dist, 0x3f, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    memset(inque, 0, sizeof(inque));
    while (!q.empty()) q.pop();
    dist[1]=0;
    inque[1]=true;
    q.push(1);
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        inque[now]=false;
        for (int i=head[now];i;i=nxt[i]) {
            int v=ver[i], w=edge[i];
            if (dist[now]+w<dist[v]) {
                dist[v]=dist[now]+w;
                if (!inque[v]) {
                    if (++cnt[v]>=n) {
                        return true;
                    }
                    inque[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d", &T);
    while (T--) {
        reset();
        scanf("%d%d", &n, &m);
        for (int i=1, u, v, w;i<=m;i++) {
            scanf("%d%d%d", &u, &v, &w);
            if (w>=0) {
                add_edge(u, v, w);
                add_edge(v, u, w);
            }
            else {
                add_edge(u, v, w);
            }
        }
        printf(spfa()?"YES\n":"NO\n");
    }
    END_PROGRAM
}