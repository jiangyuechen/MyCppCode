#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
typedef pair<double, double> point;
const int MAXN = 1001;

pair<double, double> get_function(point &a, point &b)
{ //返回经过(0,0),(xa,ya),(xb,yb)的抛物线y=ax^2+bx的a和b。
    double x1 = a.first, x2 = a.second, y1 = b.first, y2 = b.second;
    pair<double, double> ans;
    ans.first = (x2 * y1 - x1 * y2) / (x1 * x2 * (x1 - x2));
    ans.second = (x1 * x1 * y2 - x2 * x2 * y1) / (x1 * x2 * (x1 - x2));
    return ans;
}
inline bool equal(double x, double y)
{
    return abs(x - y) < 1e-8;
}
bool in_same_line(point &m, point &analyse)
{
    double a = analyse.first, b = analyse.second;
    double x = m.first, y = m.second;
    return equal(a * x * x + b * x, y);
}
point a[MAXN];
int n;
int ans;
void dfs(int x, int foot)
{
    if (x == (1 << n) - 1)
    {
        foot = min(foot, ans);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((1 << i) & x)
        {
            for (int j = 0; j < n; j++)
            {
            }
        }
    }
}

int main()
{

    END_PROGRAM
}