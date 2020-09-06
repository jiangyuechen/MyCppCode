#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 20005;
#pragma endregion

struct point
{
    double x, y;
    bool operator<(point &p)
    {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
    bool operator==(point &p)
    {
        return x == p.x && y == p.y;
    }
    bool operator!=(point &p)
    {
        return !(*this == p);
    }
} a[MAXN];

point getCenter(point &a, point &b)
{
    point ans;
    ans.x = (a.x + b.x) / 2.0;
    ans.y = (a.y + b.y) / 2.0;
    return ans;
}

int n, ansx, ansy;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + n + 1);
    point centre = getCenter(a[1], a[n]);
    for (int l = 1, r = n; l <= r; l++, r--)
    {
        if (getCenter(a[l], a[r]) != centre)
        {
            printf("This is a dangerous situation!\n");
            END_PROGRAM
        }
    }
    printf("V.I.P. should stay at (%.1lf,%.1lf).\n", centre.x, centre.y);
    END_PROGRAM
}