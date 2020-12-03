#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[5000], b[5000], f[5000][5000];
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1, temp; i <= n; i++)
        scanf("%d", &temp);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if ((i == 0) || (j == 0))
            {
                f[i][j] = 0;
                continue;
            }
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            if (a[i] != b[j])
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
        }
    printf("%d\n", f[n][n]);
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}