#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 500005;
stack<int> bracket_stack;
int n, m;
char bracket[MAXN];
struct edge
{
    int to, nxt;
} e[MAXN];
int head[MAXN], top, fa[MAXN];
long long contrib[MAXN], ans[MAXN], res;
void add_edge(int u, int v)
{
    e[++top].to = v;
    e[top].nxt = head[u];
    head[u] = top;
}
void dfs(int x)
{
    int flag = 0;
    if (bracket[x] == ')')
    {
        if (!bracket_stack.empty())
        {
            flag = bracket_stack.top();
            contrib[x] = contrib[fa[flag]] + 1;
            bracket_stack.pop();
        }
    }
    else
        bracket_stack.push(x);
    ans[x] = ans[fa[x]] + contrib[x];
    for (int i = head[x]; i; i = e[i].nxt)
    {
        dfs(e[i].to);
    }
    if (flag)
        bracket_stack.push(flag);
    else if (!bracket_stack.empty())
        bracket_stack.pop();
}
int main()
{
    scanf("%d", &n);
    scanf("%s", bracket + 1);
    for (int i = 2; i <= n; i++)
    {
        int f;
        scanf("%d", &f);
        fa[i] = f;
        add_edge(f, i);
    }
    dfs(1);
    for (long long i = 1; i <= n; i++)
    {
        res ^= ans[i] * i;
    }
    printf("%lld\n", res);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}