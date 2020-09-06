#pragma region STANDARD
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
#pragma endregion

int T;
double H, h, D;

int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> H >> h >> D;
        //printf("%.3lf %.3lf %.3lf\n", H + D - 1.000 + D * (H - h), H + D - 2.000 * sqrt(D * (H - h)), D * (h / H));
        double ans = D * h / H;
        double px = sqrt(D * (H - h));
        if (px <= D * (H - h) / H)
        {
            ans = max(ans, D - (H - h) * D / H);
        }
        if (D * (H - h) / H <= px && px <= D)
        {
            ans = max(ans, D + H - 2.00 * sqrt(D * (H - h)));
        }
        if (px >= D)
        {
            ans = max(ans, h);
        }
        printf("%.3lf\n", ans);
    }
    END_PROGRAM
}