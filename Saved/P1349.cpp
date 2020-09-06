#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
#define re register
using namespace std;
ll p, q, a1, a2, n, mod;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
template <int len>
struct matrix
{
    ll num[len][len];
    matrix() { memset(num, 0, sizeof(num)); }
    matrix(bool set_unit)
    {
        memset(num, 0, sizeof(num));
        if (set_unit)
        {
            for (int i = 0; i < len; i++)
                num[i][i] = 1;
        }
    }
    matrix operator*(const matrix &b)
    {
        matrix ans;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                for (int k = 0; k < len; k++)
                {
                    ans.num[i][j] += (num[i][k] % mod * b.num[k][j] % mod);
                    ans.num[i][j] %= mod;
                }
            }
        }
        return ans;
    }
    void output(int space_time = 1)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                cout << num[i][j];
                for (int p = 0; p < space_time; p++)
                    cout << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    p = read();
    q = read();
    a1 = read();
    a2 = read();
    n = read();
    mod = read();
    //int base_init[2][2]={{1,1},{1,0}},ans_init[2][2]={{1,1},{0,0}};
    matrix<2> ans, base;
    base.num[0][0] = p;
    base.num[0][1] = 1;
    base.num[1][0] = q;
    ans.num[0][0] = a2;
    ans.num[0][1] = a1;
    //ans.output();
    //base.output();
    if (n == 1)
    {
        cout << a1 << endl;
    }
    else if (n == 2)
    {
        cout << a2 << endl;
    }
    else
    {
        n -= 2;
        while (n)
        {
            if (n & 1)
                ans = ans * base;
            base = base * base;
            n >>= 1;
        }
        cout << ans.num[0][0] % mod << endl;
    }
    system("pause");
    return 0;
}