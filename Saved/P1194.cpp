#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
#define re register
using namespace std;
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
struct Rec
{
    int x, y, w;
    Rec() : x(0), y(0), w(0) {}
    Rec(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
} edge[500010];
int top;
int fa[100010], n, ans;
bool operator<(const Rec &a, const Rec &b)
{
    return a.w < b.w;
}
int _get(int x)
{
    if (x == fa[x])
        return x;
    else
        return fa[x] = _get(fa[x]);
}
int A, B;
int main()
{
    A = read();
    B = read();
    for (int i = 1; i <= B; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            int x = read();
            if (i <= j && x != 0)
            {
                edge[++top] = Rec(i, j, x);
            }
        }
    }
    for (int i = 1; i <= B; i++)
    {
        edge[++top] = Rec(B + 1, i, A);
    }
    sort(edge + 1, edge + top + 1);
    for (int i = 1; i <= B + 1; i++)
        fa[i] = i;
    int cnt = 0;
    for (int i = 1; i <= top && cnt <= B; i++)
    {
        int x = _get(edge[i].x);
        int y = _get(edge[i].y);
        if (x == y)
            continue;
        fa[x] = y;
        ans += edge[i].w;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}