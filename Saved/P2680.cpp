#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 100001;
int ver[MAXN], edge[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
int n, m;
pair<int, int> p[MAXN];
void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b, t; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &t);
        add_edge(a, b, t);
        add_edge(b, a, t);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
}
int main()
{

    END_PROGRAM
}