#pragma region STANDARD
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100001;
#pragma endregion

int T, n;

int a[MAXN];
int ver[MAXN], nxt[MAXN], head[MAXN], tot;
void add_edge(int u, int v)
{
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

int main()
{
    scanf("%d", &T);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int f;
        scanf("%d", &f);
        add_edge(i + 1, f);
        add_edge(f, i + 1);
    }
}