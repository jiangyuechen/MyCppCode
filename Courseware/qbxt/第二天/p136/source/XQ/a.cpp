#include <iostream>
#include <cstdio>
using namespace std;

int read()
{
    int res = 0;
    char ch;
    bool f = false;
    while (!isdigit(ch = getchar()))
        f = ch == '-';
    do
    {
        res = res * 10 + ch - 48;
    } while (isdigit(ch = getchar()));
    return f ? -res : res;
}

char outbuf[17];
void put_num(int x)
{
    int top = 0;
    for (; x; x /= 10)
        outbuf[++top] = x % 10 + 48;
    while (top)
        putchar(outbuf[top--]);
    putchar(' ');
}

int n, P;

int qpow(int b, int pow = P - 2)
{
    int x = 1;
    for (; pow; pow >>= 1)
    {
        if (pow & 1)
            x = 1ll * x * b % P;
        b = 1ll * b * b % P;
    }
    return x;
};

struct Mat
{
    long long a[111][111];
    void swap_row(int x, int y) { swap(a[x], a[y]); }
    void mult_row(int x, int k)
    {
        for (int i = 0; i < n; ++i)
            a[x][i] = (a[x][i] * k % P + P) % P;
    }
    void add(int x, int y, int k)
    {
        for (int i = 0; i < n; ++i)
            a[x][i] = ((a[x][i] + a[y][i] * k) % P + P) % P;
    }
    void print()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                put_num(a[i][j]);
            }
            puts("");
        }
    }
};

Mat A, B;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    n = read(), P = read();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A.a[i][j] = read();

    for (int i = 0; i < n; ++i)
        B.a[i][i] = 1;

    for (int i = 0; i < n; ++i)
    {
        if (A.a[i][i] == 0)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (A.a[j][i] != 0)
                {
                    A.swap_row(i, j);
                    B.swap_row(i, j);
                    break;
                }
            }
        }

        if (A.a[i][i] == 0)
        {
            puts("No Solution");
            return 0;
        }
        int tmp = qpow(A.a[i][i]);
        A.mult_row(i, tmp);
        B.mult_row(i, tmp);
        for (int j = i + 1; j < n; ++j)
        {
            int tmp = -A.a[j][i];
            A.add(j, i, tmp);
            B.add(j, i, tmp);
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int tmp = -A.a[i][j];
            A.add(i, j, tmp);
            B.add(i, j, tmp);
        }
    }

    B.print();

    return 0;
}
