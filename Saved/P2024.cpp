#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 100001;
int fa[MAXN * 3];
int n, k;
inline int get_self(int x)
{
    return x;
}
inline int get_enemy(int x)
{
    return n + x;
}
inline int get_eat(int x)
{
    return 2 * n + x;
}
inline void prework()
{
    for (int i = 1; i <= 3 * n; i++)
    {
        fa[i] = i;
    }
}
inline int get_fa(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = get_fa(fa[x]);
}
int ans;
int main()
{
    scanf("%d%d", &n, &k);
    prework();
    for (int i = 1; i <= k; i++)
    {
        int qry, x, y;
        scanf("%d%d%d", &qry, &x, &y);
        if (x > n || y > n)
            ans++;
        else if (qry == 2 && x == y)
            ans++;
        else
        {
            int xeat = get_fa(get_eat(x)), xenemy = get_fa(get_enemy(x)), xself = get_fa(get_self(x));
            int yeat = get_fa(get_eat(y)), yenemy = get_fa(get_enemy(y)), yself = get_fa(get_self(y));
            if (qry == 1)
            {
                if (xeat == yself || xself == yeat)
                    ans++;
                else
                {
                    fa[xself] = yself;
                    fa[xenemy] = yenemy;
                    fa[xeat] = yeat;
                }
            }
            else
            {
                if (xself == yself || xself == yeat)
                    ans++;
                else
                {
                    fa[xeat] = yself;
                    fa[xself] = yenemy;
                    fa[xenemy] = yeat;
                }
            }
        }
    }
    printf("%d\n", ans);
    END_PROGRAM
}