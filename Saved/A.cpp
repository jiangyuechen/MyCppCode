#include <bits/stdc++.h>
using namespace std;

//ax^2+bx+c=x have two resolution that >= -b/2a.
bool ok(double a, double b, double c)
{
    if (a == 0.00 && b == 1.00 && c == 0.00)
        return true;
    else if (a == 0)
        return false;
    double delta = (b - 1.00) * (b - 1.00) - 4.00 * a * c;
    double dcz = -(b) / (2.00 * a);
    if (delta > 0.00)
    {
        double x1 = (-(b - 1.00) + sqrt(delta)) / (2.00 * a);
        double x2 = (-(b - 1.00) - sqrt(delta)) / (2.00 * a);
        // printf("delta:%lf dcz:%lf x1:%lf x2:%lf", delta, dcz, x1, x2);
        if (x1 >= dcz && x2 >= dcz)
            return true;
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        double x, y, z;
        scanf("%lf%lf%lf", &x, &y, &z);
        printf(ok(x, y, z) ? "YES" : "NO");
        puts("");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}