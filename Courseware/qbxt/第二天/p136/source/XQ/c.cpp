#include <iostream>
#include <cstdio>
using namespace std;

const int MOD = 1e6 + 7;
const long long REP = (MOD - 1ll) * (MOD + 1ll);

int A[2][2], B[2][2];
void mul(int x[2][2], int y[2][2])
{
    int a = 1ll * x[0][0] * y[0][0] % MOD + 1ll * x[0][1] * y[1][0] % MOD;
    int b = 1ll * x[0][0] * y[0][1] % MOD + 1ll * x[0][1] * y[1][1] % MOD;
    int c = 1ll * x[1][0] * y[0][0] % MOD + 1ll * x[1][1] * y[0][1] % MOD;
    int d = 1ll * x[1][0] * y[0][1] % MOD + 1ll * x[1][1] * y[1][1] % MOD;
    x[0][0] = (a + MOD) % MOD;
    x[0][1] = (b + MOD) % MOD;
    x[1][0] = (c + MOD) % MOD;
    x[1][1] = (d + MOD) % MOD;
}

void pow(unsigned long long p)
{
    while (p)
    {
        if (p & 1)
            mul(A, B);
        mul(B, B);
        p >>= 1;
    }
}
unsigned long long n;
int a, b;

inline void init()
{

    A[0][0] = 1, A[0][1] = 0;
    A[1][0] = 0, A[1][1] = 1;

    B[0][0] = 0, B[0][1] = 1;
    B[1][0] = b, B[1][1] = a;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;

    init();
    pow(n % REP);
    unsigned long long tmp = A[1][0];
    init();
    pow(tmp % REP);
    cout << A[1][0];
    return 0;
}
