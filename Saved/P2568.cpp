#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 10000001;
int phi[MAXN], qzh[MAXN];
int f[MAXN], prime[MAXN];
int tot;
void solve_phi(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!f[i])
        {
            prime[++tot] = f[i] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= tot; j++)
        {
            int t = i * prime[j];
            if (t > n)
                break;
            f[t] = prime[j];
            phi[t] = phi[i] * (prime[j] - (prime[j] < f[i]));
            if (prime[j] == f[i])
                break;
        }
    }
}
int n, ans;
int main()
{
    scanf("%d", &n);
    solve_phi(n);
    for (int i = 1; i <= n; i++)
    {
        qzh[i] = qzh[i - 1] + phi[i];
    }
    for (int i = 1; i <= tot; i++)
    {
        ans += (qzh[n / prime[i]] * 2);
    }
    printf("%d\n", ans + tot);
    END_PROGRAM
}