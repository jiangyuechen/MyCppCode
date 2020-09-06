#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
#define re register
const int MAXN = 1000;
using namespace std;
int n;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int num[MAXN];
/////////////////
int ver[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
/////////////////
int road[MAXN];
bool vis[MAXN];
int ans_len, ans[MAXN], ans_num;
void dfs(int now, int step, int num_total)
{
    bool flag = false;
    for (int i = head[now]; i; i = nxt[i])
    {
        int v = ver[i];
        if (vis[v])
            continue;
        vis[v] = true;
        flag = true;
        road[step + 1] = v;
        dfs(v, step + 1, num_total + num[v]);
        vis[v] = false;
    }
    if (!flag)
    {
        if (num_total > ans_num)
        {
            ans_num = num_total;
            ans_len = step;
            for (int i = 1; i <= step; i++)
            {
                ans[i] = road[i];
            }
        }
        return;
    }
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        num[i] = read();
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x = read();
            if (x)
            {
                add_edge(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
            continue;
        vis[i] = true;
        road[1] = i;
        dfs(i, 1, num[i]);
        vis[i] = false;
    }
    for (int i = 1; i <= ans_len; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << ans_num << endl;
    system("pause");
    return 0;
}