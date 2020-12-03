#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int MAXN = 20;

inline bool equal(double a, double b) { return fabs(a - b) < eps; }
inline double pow2(double a) { return a * a; }

class Point
{
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

class Function
{
    // ax^2 + bx
public:
    double a, b;
    Function() : a(0), b(0) {}
    Function(double _a, double _b) : a(_a), b(_b) {}
    Function(Point s, Point t)
    {
        double D = pow2(s.x) * t.x - s.x * pow2(t.x);
        double Da = s.y * t.x - s.x * t.y;
        double Db = pow2(s.x) * t.y - pow2(t.x) * s.y;
        a = Da / D;
        b = Db / D;
    }
    bool online(Point p)
    {
        return equal(a * pow2(p.x) + b * p.x, p.y);
    }
};

int T, n, m;
Point a[MAXN];
int dp[1 << MAXN];
int hit[MAXN][MAXN];
int first_zero[1 << MAXN];

int main()
{
    for (int i = 0; i < (1 << 19); i++)
    {
        int j = 1;
        while (j <= 19 && i & (1 << (j - 1)))
            j++;
        first_zero[i] = j;
    }
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(dp, 0x7f, sizeof(dp));
        memset(hit, 0, sizeof(hit));
        for (int i = 1; i <= n; i++)
        {
            double x, y;
            scanf("%lf%lf", &x, &y);
            a[i].x = x, a[i].y = y;
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (equal(a[i].x, a[j].x))
                    continue;
                Function func(a[i], a[j]);
                if (func.a >= -eps)
                    continue;
                for (int k = 1; k <= n; k++)
                {
                    if (func.online(a[k]))
                    {
                        hit[i][j] |= (1 << (k - 1));
                    }
                }
            }
        }
        for (int i = 0; i < (1 << n); i++)
        {
            int j = first_zero[i];
            dp[i | (1 << (j - 1))] = min(dp[i | (1 << (j - 1))], dp[i] + 1);
            for (int k = 1; k <= n; k++)
            {
                dp[i | hit[j][k]] = min(dp[i | hit[j][k]], dp[i] + 1);
            }
        }
        printf("%d\n", dp[(1 << n) - 1]);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}