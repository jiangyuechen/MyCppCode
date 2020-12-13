#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1001;
#define START (0)
#define END (n + 1)
long long T, n;
long long h, r;

struct Point
{
    long long x, y, z;
    Point() : x(0), y(0), z(0) {}
    Point(long long _x, long long _y, long long _z) : x(_x), y(_y), z(_z) {}
};

inline long long dist(const Point &a, const Point &b) /** 返回距离 @b 的平方 */
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

inline bool ok(const Point &a, const Point &b)
{
    return dist(a, b) <= 4 * r * r;
}

Point p[MAXN];

long long fa[MAXN];
inline void UFS_prework()
{
    for (long long i = 0; i <= n + 1; i++)
        fa[i] = i;
}
inline long long UFS_get(long long x)
{
    if (x == fa[x])
        return x;
    else
        return fa[x] = UFS_get(fa[x]);
}
inline void UFS_merge(long long x, long long y)
{
    fa[UFS_get(x)] = UFS_get(y);
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &h, &r);
        UFS_prework();
        for (long long i = 1; i <= n; i++)
        {
            long long x, y, z;
            scanf("%lld%lld%lld", &x, &y, &z);
            p[i] = Point(x, y, z);
            if (h - z <= r)
                UFS_merge(i, END);
            if (z - r <= 0)
                UFS_merge(i, START);
            for (long long j = 1; j < i; j++)
            {
                if (ok(p[i], p[j]))
                {
                    // cerr << "OK returned true." << endl;
                    UFS_merge(i, j);
                }
            }
        }
        // cerr << "START->" << UFS_get(START) << ",END->" << UFS_get(END) << endl;
        if (UFS_get(START) == UFS_get(END))
            puts("Yes");
        else
            puts("No");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}