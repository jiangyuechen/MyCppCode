#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 270005, MAXM = 70;
int f[MAXM][MAXN];
int n;
int ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        f[x][i] = i + 1;
    }
    for (int i = 2; i <= 58; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!f[i][j])
            {
                f[i][j] = f[i - 1][f[i - 1][j]];
            }
            if (f[i][j])
            {
                ans = i;
            }
        }
    }
    cout << ans << endl;
    END_PROGRAM
}