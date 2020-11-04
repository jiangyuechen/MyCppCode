#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6005;
const int MAXM = 2000005;
int n, m, s, t;
struct edge
{
    double v;
    int to, nxt;
} e[MAXM];
int head[MAXN], top;
void add_edge(int a, int b, double k)
{
    e[++top].to = b;
    e[top].v = k;
    e[top].nxt = head[a];
    head[a] = top;
}

namespace Dijkstra
{
    double d[MAXN];
    bool v[MAXN];
    priority_queue<pair<double, int>> q;
    void dijkstra()
    {
        memset(d, 0, sizeof(d)); //! 最长路，初始化为 0 而不是 正无穷
        memset(v, false, sizeof(v));
        d[::s] = 1.0000; //! 乘积，原点初始化距离为 1 而不是 0
        q.push(make_pair(1.0000, ::s));
        while (!q.empty())
        {
            int x = q.top().second;
            q.pop();
            if (v[x])
                continue;
            v[x] = true;
            for (int i = head[x]; i; i = e[i].nxt)
            {
                int y = e[i].to;
                double z = e[i].v;
                if (d[y] < d[x] * z) //! 最长路，不等号方向改变
                {
                    d[y] = d[x] * z;
                    q.push(make_pair(d[y], y)); //! 最长路，使用 d[y] 而不是 -d[y]
                }
            }
        }
    }
} // namespace Dijkstra

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        double k;
        scanf("%d%d%lf", &a, &b, &k);
        add_edge(a, b, k);
    }
    Dijkstra::dijkstra();
    if (!Dijkstra::v[::t])
        printf("orz\n");
    else
        printf("%.4lf\n", Dijkstra::d[::t]);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}