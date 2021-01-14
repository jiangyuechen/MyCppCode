## 扩展欧几里得算法
已知 $a,b,c \in \mathbf{N}$ ，求解 $ax+by=c$ 的一组整数解 $(x,y)$。
```cpp
void exgcd(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
```
- 已知 $a,b \in \mathbf{N}$ ，求 $ax \equiv 1 \ (\mathrm{mod} \ b)$的最小正整数解 $x$。
```cpp
exgcd(a, b, x, y);
std::cout << (x + b) % b;
```

## 归并排序求逆序对
```cpp
int a[MAXN], d[MAXN], ans;
void mergesort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    int lp = l, rp = mid + 1, s = l;
    while (lp <= mid && rp <= r)
    {
        if (a[lp] <= a[rp])
            d[s++] = a[lp++];
        else
            d[s++] = a[rp++], ans += mid - lp + 1;
    }
    while (lp <= mid)
        d[s++] = a[lp++];
    while (rp <= r)
        d[s++] = a[rp++];
    for (int i = l; i <= r; i++)
        a[i] = d[i];
}
```

## Dijkstra 求最短路
```cpp
namespace Dijkstra
{
    int d[MAXN];
    bool vis[MAXN];
    priority_queue<int, int> q;
    void dijkstra(int start)
    {
        memset(d, 0x3f, sizeof(d));
        memset(vis, 0, sizeof(vis));
        d[start] = 0;
        // !注意：这里不用设置 vis[start] = true;
        q.push(make_pair(0, start));
        while (!q.empty())
        {
            int x = q.top().second;
            q.pop();
            if (vis[x])
                continue;
            vis[x] = true;
            for (int i = Edge::head[x]; i; i = Edge::e[i].nxt)
            {
                int y = e[i].to, z = e[i].v;
                if (d[y] > d[x] + z)
                {
                    d[y] = d[x] + z;
                    q.push(make_pair(-d[y], y));
                }
            }
        }
    }
} // namespace Dijkstra
```
## SPFA 求最短路
```cpp
namespace SPFA
{
    int d[MAXN];
    bool inqueue[MAXN];
    queue<int> q;
    // 注意设置inqueue.
    void _insert(int x) // 模拟进入队列
    {
        if (!inqueue[x])
        {
            q.push(x);
            inqueue[x] = true;
        }
    }
    int _pop() // 模拟弹出队列
    {
        int x = q.front();
        q.pop();
        inqueue[x] = false;
        return x;
    }
    void spfa(int start) 
    {
        memset(d, 0x3f, sizeof(d));
        memset(inqueue, 0, sizeof(inqueue));
        d[start] = 0;
        _insert(start);
        while (!q.empty())
        {
            int x = _pop();
            for (int i = Edge::head[x]; i; i = Edge::e[i].nxt)
            {
                int y = Edge::e[i].to, z = Edge::e[i].v;
                if (d[y] > d[x] + z)
                {
                    d[y] = d[x] + z;
                    _insert(y);
                }
            }
        }
    }
} // namespace SPFA
```
## 拓扑排序
```cpp
namespace Toposort
{
    int indgr[MAXN];
    queue<int> q;
    void toposort()
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) // 先将入度为 0 的点加入队列中。
        {
            if (indgr[i] == 0)
            {
                q.push(i);
                f[i] = 1;
            }
        }
        while (!q.empty())
        {
            int x = q.front(); // 获取入度为 0 的点。 
            q.pop(); // 弹出
            for (int i = Edge::head[x]; i; i = Edge::e[i].nxt)
            {
                int y = Edge::e[i].to, z = Edge::e[i].v;
                // 必要的 dp 等运算，以下为示例：
                f[y] += f[x];
                indgr[y]--; // 相当于删除这个起点，终点的入度减一。
                if (!indgr[y]) // 发现了新的入度为 0 的点。
                    q.push(y);
            }
        }
    }
} // namespace Toposort
```
## 线性筛素数
```cpp
namespace Prime
{
    bool v[MAXN];    // 一个数是否是 合数或 1 （即不是素数）
    int prime[MAXN]; // prime[i] 表示第 i 小的素数。
    inline void shai()
    {
        v[1] = true;                 // 1 不是素数
        int cnt = 0;                 // 素数个数
        for (int i = 2; i <= n; i++) // n 表示要筛的素数上限
        {
            if (!v[i])            // i 不是 非素数，即 是素数
                prime[++cnt] = i; // 新的素数
            for (int j = 1; j <= cnt /* 从已有的素数开始筛，不能超过目前的 prime 范围 */ && i * prime[j] <= n /*超过上限的素数不用筛*/; j++)
            {
                v[i * prime[j]] = true;
                if (i % prime[j] == 0)  //i 的最小质因子是 prime[j], i 只应该被 prime[j] 筛一次。之后直接 break，防止 i 被筛多次。
                    break;
            }
        }
    }
} // namespace Prime
```
## 求欧拉函数
$\phi(N) = N * \prod_{质数 p|N} (\frac{p-1}{p})$
```cpp
int phi(int n)
{
    int ans = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i; // 除尽这个因数 (2 是质数，从它开始)
        }
    }
    if (n > 1) // n 本身是质数
        ans = ans / n * (n - 1);
    return ans;
}
```

## 欧拉定理
1.$a^{\phi(n)}\equiv 1(\mathrm{mod}\ n)$
- $a$ 模 $n$ 的逆元为 $a^{\phi(n)-2}$.

2.若$(a,m)=1$, 则$a^k\equiv a^{k\ \mathrm{mod}\ \phi(m) + \phi(m)}(\mathrm{mod}\ m)$.

## 最小生成树
```cpp

namespace Kruskal
{
    struct Edge
    {
        int frm, to, val;
    } e[MAXN];
    int top;
    void add_edge(int f, int t, int v)
    {
        e[++top].frm = f;
        e[top].to = t;
        e[top].val = v;
    }
    struct UFS
    {
        int fa[MAXN];
        UFS() // !注意初始化：把每个节点的父亲都赋值为此节点。
        {
            for(int i = 1; i <= n; i++)
            {
                fa[i] = i;
            }
        }
        void get_fa(int x) // 路径优化找祖先
        {
            if (fa[x] == x) 
                return x;
            else return fa[x] = get(fa[x]);
        }
    }
    int kruskal()
    {
        sort(e + 1, e + m + 1);
        UFS u = UFS();
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int x = u.get_fa(e[i].frm), y = u.get_fa(e[i].to), z = e[i].val; // !这里获取的是边的端点 的 祖先。
            if (x != y)
            {
                fa[x] = y;
                ans += z;
            }
        }
        return ans;
    }
}
```
