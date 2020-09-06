#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 100001, MAXM = 500005;
int n, m, q;
struct Edge_CFS
{
    int ver, len, nxt;
    Edge_CFS() : ver(0), len(0), nxt(0) {}
};
struct Edge_STD
{
    int from, to, len;
    Edge_STD() : from(0), to(0), len(0) {}
    bool operator<(const Edge_STD &e)
    {
        return this->len > e.len;
    }
};
struct Graph_CFS
{
    Edge_CFS e[MAXN];
    int head[MAXM], tot;
    int depth[MAXN];
    int max_depth;
    int father[MAXN][15], W[MAXN][15];
    Graph_CFS()
    {
        memset(head, 0, sizeof(head));
        memset(depth, 0, sizeof(depth));
        memset(father, 0, sizeof(father));
        memset(W, 0x3f, sizeof(W));
        max_depth = (int)log(n) / log(2) + 1;
        tot = 0;
    }
    void add_edge(int u, int v, int w)
    {
        e[++tot].ver = v;
        e[tot].len = w;
        e[tot].nxt = head[u];
        head[u] = tot;
    }
    void calc_depth()
    {
        queue<int> q = queue<int>();
        q.push(1);
        depth[1] = 1;
        father[1][0] = 1;
        W[1][0] = 0x7ffffff;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = head[x]; i; i = e[i].nxt)
            {
                int y = e[i].ver;
                if (depth[y])
                    continue;
                depth[y] = depth[x] + 1;
                father[y][0] = x;
                W[y][0] = e[i].len;
                for (int j = 1; j <= max_depth; j++)
                {
                    father[y][j] = father[father[y][j - 1]][j - 1];
                    W[y][j] = min(W[y][j - 1], W[father[y][j - 1]][j - 1]);
                    //printf("W[%d][%d] is : %d\n", y, j, W[y][j]);
                }
                q.push(y);
            }
        }
    }
    int LCA(int x, int y)
    {
        int ans = 0x7ffffff;
        if (depth[x] > depth[y])
            swap(x, y);
        for (int i = max_depth; i >= 0; i--)
        {
            if (depth[father[y][i]] >= depth[x])
            {
                ans = min(ans, W[y][i]);
                y = father[y][i];
            }
            if (x == y)
                return ans;
            for (int i = max_depth; i >= 0; i--)
            {
                if (father[x][i] != father[y][i])
                {
                    ans = min({ans, W[x][i], W[y][i]});
                    x = father[x][i];
                    y = father[y][i];
                }
            }
        }
        ans = min({ans, W[x][0], W[y][0]});
        return ans;
    }
};
struct Graph_STD
{
    Edge_STD e[MAXN];
};
struct UFS
{
    int fa[MAXN];
    UFS()
    {
        memset(fa, 0, sizeof(fa));
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    inline int UFS_get(int x)
    {
        if (x == fa[x])
            return x;
        else
            return fa[x] = UFS_get(fa[x]);
    }
};
Graph_CFS *Kruskal(Graph_STD *G)
{
    Graph_CFS *Ans = new Graph_CFS();
    UFS *u = new UFS();
    sort(G->e + 1, G->e + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int fx = u->UFS_get(G->e[i].from), fy = u->UFS_get(G->e[i].to);
        if (fx == fy)
            continue;
        u->fa[fx] = fy;
        Ans->add_edge(G->e[i].from, G->e[i].to, G->e[i].len);
        Ans->add_edge(G->e[i].to, G->e[i].from, G->e[i].len);
    }
    delete u;
    return Ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    Graph_STD *origin = new Graph_STD();
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &origin->e[i].from, &origin->e[i].to, &origin->e[i].len);
    }
    Graph_CFS *G = Kruskal(origin);
    G->calc_depth();
    scanf("%d", &q);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > n || y > n)
            printf("-1\n");
        else
            printf("%d\n", G->LCA(x, y));
    }
    delete G;
    delete origin;
    END_PROGRAM
}