#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, m;

namespace Edge
{
    struct edge
    {
        int to, nxt;
    } e[MAXN];
    int head[MAXN], top;
    void add_edge(int a, int b)
    {
        e[++top].to = b;
        e[top].nxt = head[a];
        head[a] = top;
    }
} // namespace Edge

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
    }
}