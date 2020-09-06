#pragma optimize G++(2)
#include <bits/stdc++.h>
#define int long long
int a1, n, b1;
const int MAXN = 10;
int cnt = 0;
const int p = 1e6 + 7;
struct mat
{
    int a[MAXN][MAXN];
} a, e, ans;
inline void clr(mat &x)
{
    memset(x.a, 0, sizeof(x.a));
}

void print(int x)
{
    if (!x)
    {
        return;
    }
    print(x / 10);
    putchar(x % 10 + '0');
}

inline void read(int &x)
{
    x = 0;
    int f = 1;
    char s = 0;
    for (; !isdigit(s); s = getchar())
        if (s == '-')
            f = -1;
    for (; isdigit(s); s = getchar())
        x = (x << 1) + (x << 3) + s - '0';
    x *= f;
}

mat operator*(mat a, mat b)
{
    mat c;
    clr(c);
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= 2; k++)
            {
                c.a[i][j] += (a.a[i][k] * b.a[k][j] % p);
                c.a[i][j] %= p;
            }
        }
    }
    return c;
}
inline void debug(mat x)
{
    cnt++;
    printf("______DEBUG_______%d\n", cnt);
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            printf("%ld ", x.a[i][j]);
        }
        puts("");
    }
    return;
}
inline mat ksm(mat x, int y)
{
    mat ans;
    clr(ans);
    for (int i = 1; i <= 2; i++)
    {
        ans.a[i][i] = 1;
    }
    while (y)
    {
        if (y & 1)
            ans = ans * x;
        x = x * x;
        y >>= 1;
    }
    //   debug(ans);
    return ans;
}

inline void Init() //这里我们从n==2时开始推
{
    a.a[1][2] = 1;
    a.a[2][1] = b1;
    a.a[2][2] = a1;
    e.a[1][1] = 1;
    e.a[2][1] = a1; //手推f2qwq
    return;
}

signed main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    read(n);
    read(a1);
    read(b1);
    a1 %= p;
    b1 %= p;
    Init();
    mat tmp;
    if (n <= 1) //特判，防止ksm一个负数而超时
    {
        if (n == 2)
            printf("%d", a1);
        printf("1\n");
        return 0;
    }
    n -= 2;
    tmp = ksm(a, n) * e;
    //   debug(tmp);
    clr(ans);
    int qwq = tmp.a[2][1];
    qwq -= 2;
    //   print(qwq);
    //   puts("");
    if (qwq <= 2)
    {
        if (qwq <= 0)
            printf("0\n");
        else if (qwq == 2)
            printf("%d\n", a1);
        else
            printf("1\n");
        return 0;
    }
    //   debug(a);
    ans = ksm(a, qwq) * e;
    ans.a[2][1] %= p;
    //    debug(ans);
    //   debug(e);
    print(ans.a[2][1]);
    puts("");
    return 0;
}