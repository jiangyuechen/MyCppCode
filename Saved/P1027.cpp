#include <bits/stdc++.h>
using namespace std;
using point = pair<double, double>;
const int MAXN = 4001;
struct edge
{
    int to, nxt;
    double v;
} e[MAXN];
int head[MAXN], top;
vector<point> vct;
void add_edge(int a, int b, double k)
{
    e[++top].to = b;
    e[top].v = k;
    e[top].nxt = head[a];
    head[a] = top;
    e[++top].to = a;
    e[top].v = k;
    e[top].nxt = head[b];
    head[b] = top;
}
int s, t, A, B;
double getDist(point &x, point &y)
{
    double dx = x.first - y.first, dy = x.second - y.second;
    return sqrt(dx * dx + dy * dy);
}
double getK(point &x, point &y)
{
    double dx = x.first - y.first, dy = x.second - y.second;
    return dy / dx;
}
point operator+(const point &x, const point &y)
{
    return point(x.first + y.first, x.second + y.second);
}
point operator-(const point &x, const point &y)
{
    return point(x.first - y.first, x.second - y.second);
}
namespace Dijkstra
{
    double d[MAXN];
    bool v[MAXN];
    priority_queue<pair<double, int>> q;
    void dijkstra(int start)
    {
        memset(d, 0x7f, sizeof(d));
        memset(v, 0, sizeof(v));
        d[start] = 0.00;
        q.push(make_pair(0.00, start));
        while (!q.empty())
        {
            int x = q.top().second;
            q.pop();
            if (v[x])
                continue;
            v[x] = true;
            for (int i = head[x]; i; i = e[i].nxt)
            {
                double z = e[i].v;
                int y = e[i].to;
                if (d[y] > d[x] + z)
                {
                    d[y] = d[x] + z;
                    q.push(make_pair(-d[y], y));
                }
            }
        }
    }
} // namespace Dijkstra
struct city
{
    point x, y, z, w;
    double k;
    city() : k(0.00) {}
    city(point &_x, point &_y, point &_z, double _t) : x(_x), y(_y), z(_z), k(_t)
    {

        if ((x.first == y.first && x.second == z.second) || (x.first == z.first && x.second == y.second) || (getK(_x, _y) * getK(_x, _z) + 1.00) < 1e-6)
            w = _y - _x + _z;
        else if ((z.first == y.first && z.second == x.second) || (z.first == x.first && z.second == y.second) || abs(getK(_x, _z) * getK(_z, _y) + 1.00) < 1e-6)
            w = _y - _z + _x;
        else if ((y.first == x.first && y.second == z.second) || (y.first == z.first && y.second == x.second) || abs(getK(_x, _y) * getK(_y, _z) + 1.00) < 1e-6)
            w = _x - _y + _z;
    }
    void make_edge(int code)
    {
        code = code * 4 - 3;
        // x = code, y = code + 1, z = code + 2, w = code + 3
        for (int i = 1; i <= code - 1; i++)
        {
            add_edge(i, code, getDist(vct[i], x) * (double)t);
            add_edge(i, code + 1, getDist(vct[i], y) * (double)t);
            add_edge(i, code + 2, getDist(vct[i], z) * (double)t);
            add_edge(i, code + 3, getDist(vct[i], w) * (double)t);
        }
        vct.push_back(x);
        vct.push_back(y);
        vct.push_back(z);
        vct.push_back(w);
        add_edge(code, code + 1, getDist(x, y) * k);
        add_edge(code, code + 2, getDist(x, z) * k);
        add_edge(code, code + 3, getDist(x, w) * k);
        add_edge(code + 1, code + 2, getDist(y, z) * k);
        add_edge(code + 1, code + 3, getDist(y, w) * k);
        add_edge(code + 2, code + 3, getDist(z, w) * k);
    }
};
int sto;
void reset()
{
    vct.clear();
    memset(head, 0, sizeof(head));
    memset(e, 0, sizeof(e));
}
int main()
{
    scanf("%d", &sto);
    while (sto--)
    {
        scanf("%d%d%d%d", &s, &t, &A, &B);
        vct.push_back(make_pair<double, double>(0.00, 0.00));
        for (int i = 1; i <= s; i++)
        {
            point x, y, z;
            double x1, y1, x2, y2, x3, y3, T;
            scanf("%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &T);
            x.first = x1, x.second = y1, y.first = x2, y.second = y2, z.first = x3, z.second = y3;
            city c = city(x, y, z, T);
            c.make_edge(i);
        }
        double ans = 0x7fffffff;
        using namespace Dijkstra;
        for (int i = A * 4 - 3; i <= A * 4; i++)
        {
            dijkstra(i);
            ans = std::min({ans, d[B * 4 - 3], d[B * 4 - 2], d[B * 4 - 1], d[B * 4]});
        }
        printf("%.1lf\n", ans);
        reset();
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}