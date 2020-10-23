#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int n, m, p, x;
int a[MAXN];

int _max = 0, _min = 2147483647, _even, _ans;
void upd(int _ex)
{
    _ans ^= _ex;
    _min = min(_min, _ex);
    _max = max(_max, _ex);
    if (_ex & 1 == 1)
        _even++;
}

int qzh[MAXN];

int getRange(int l, int r)
{
    return qzh[r] ^ qzh[l - 1];
}
int main()
{
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        qzh[i] = qzh[i - 1] ^ a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &p, &x);
        a[p] ^= x;
        a[p + 1] ^= x;
        qzh[p] ^= x;
        int ex = 0;
        for (int l = 1; l <= n; l++)
        {
            for (int r = l; r <= n; r++)
            {
                if (getRange(l, r) == 0)
                    ex++;
            }
        }
        upd(ex);
    }
    printf("%d\n%d\n%d\n%d\n", _ans, _even, _max, _min);
    fclose(stdin);
    fclose(stdout);
    return 0;
}