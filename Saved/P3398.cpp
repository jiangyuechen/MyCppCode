#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 1000001;
int fa[MAXN][20], dep[MAXN];
int max_depth;
struct edge
{
    int to, nxt;
} e[MAXN];
int head[MAXN], tot;

void add_edge(int a, int b)
{
    e[++tot].to = b;
    e[tot].nxt = head[a];
    head[a] = tot;
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    dep[root] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x], son; i; i = e[i].nxt)
        {
            son = e[i].to;
            if (dep[son])
                continue; //make sure that "son" is not father,i.e.dep[son] is not been got.
            dep[son] = dep[x] + 1;
            fa[son][0] = x;
            for (int j = 1; j <= max_depth; j++)
            {
                fa[son][j] = fa[fa[son][j - 1]][j - 1];
            }
            q.push(son);
        }
    }
}

int lca(int x, int y)
{
    if (dep[x] > dep[y])
        swap(x, y);
    for (int i = max_depth; i >= 0; i--)
    {
        if (dep[fa[y][i]] >= dep[x])
            y = fa[y][i];
    }
    if (x == y)
        return x;
    for (int i = max_depth; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}
int dist(int x, int y)
{
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
int n, q;
int main()
{
    scanf("%d%d", &n, &q);
    dep[1] = 1;
    max_depth = (int)(log(n) / log(2)) + 1;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    bfs(1);
    for (int i = 1; i <= q; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ab = lca(a, b), cd = lca(c, d);
        if (dist(a, cd) + dist(cd, b) == dist(a, b) || dist(c, ab) + dist(ab, d) == dist(c, d))
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
    END_PROGRAM
}
