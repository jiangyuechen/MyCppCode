#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int tot, head[10001];
int vis[1001][1001];
double dis[1001][1001];
struct Node
{
    int to, v, s;
    int next;
} t[100001];
struct Nodee
{
    int x, v;
} from[1001][1001];
void add(int from, int to, int v, int s)
{
    tot++;
    t[tot].to = to;
    t[tot].v = v;
    t[tot].s = s;
    t[tot].next = head[from];
    head[from] = tot;
}
void out(int x, int v)
{
    if (x == 1)
        return;
    out(from[x][v].x, from[x][v].v);
    printf("%d ", x - 1);
}
void dj()
{
    priority_queue<pair<double, pair<int, int>>> p;
    p.push(make_pair(0, make_pair(1, 70)));
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            dis[i][j] = 1e9 + 1;
        }
    }
    dis[1][70] = 0;
    vis[1][70] = 1;
    while (!p.empty())
    {
        int x = p.top().second.first;
        int nowspeed = p.top().second.second;
        vis[x][nowspeed] = 0;
        p.pop();
        for (int i = head[x]; i; i = t[i].next)
        {
            int y = t[i].to;
            int newspeed = t[i].v;
            if (t[i].v)
            {
                if (dis[y][newspeed] > dis[x][nowspeed] + (double)t[i].s / (double)newspeed)
                {
                    dis[y][newspeed] = dis[x][nowspeed] + (double)t[i].s / (double)newspeed;
                    from[y][newspeed] = {x, nowspeed};
                    if (vis[y][newspeed])
                        continue;
                    vis[y][newspeed] = 1;
                    p.push(make_pair(-dis[y][newspeed], make_pair(y, newspeed)));
                }
                continue;
            }
            if (!t[i].v)
            {
                newspeed = nowspeed;
                if (dis[y][newspeed] > dis[x][nowspeed] + (double)t[i].s / (double)newspeed)
                {
                    dis[y][newspeed] = dis[x][nowspeed] + (double)t[i].s / (double)newspeed;

                    from[y][newspeed] = {x, nowspeed};
                    if (vis[y][newspeed])
                        continue;
                    vis[y][newspeed] = 1;
                    p.push(make_pair(-dis[y][newspeed], make_pair(y, newspeed)));
                }
                continue;
            }
        }
    }
    int mmin = 0;
    dis[d][mmin] = 1e9 + 100;
    for (int i = 1; i <= 1000; i++)
    {
        if (dis[d][mmin] >= dis[d][i] && dis[d][i] != 1e9 + 1)
            mmin = i;
    }
    printf("0 ");
    out(d, mmin);
    printf("\n");
}

int read()
{
    int f1 = 0, f2 = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f2 = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        f1 = (f1 << 1) + (f1 << 3) + (ch ^ 48);
        ch = getchar();
    }
    return f1 * f2;
}
int main()
{
    n = read(), m = read(), d = read();
    d++;
    for (int i = 1; i <= m; i++)
    {
        int A = read(), S = read(), D = read(), F = read();
        A++, S++;
        add(A, S, D, F);
    }
    dj();

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}