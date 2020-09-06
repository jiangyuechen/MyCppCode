
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MAXL =105;

long long prime;
long n;

inline void _swap(long long &AAA, long long &flag) {
    long long TTT = AAA;
    AAA = flag;
    flag = TTT;
}

inline int qread() {
    int num = 0, flag = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        num = num * 10 + c - '0', c = getchar();
    return flag * num;
}
long long A[MAXL][MAXL], B[MAXL][MAXL];

inline int pow(int a, int b) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = 1ll*ans*a%prime;
        a = 1ll* a*a%prime;
        b >>= 1;
    }
    return ans;
}

int flag = 1;


inline void gauss() {
    for (register int i = 1; i <= n; ++i) {
        int j = i;
        while (!A[j][i] && j <= n) ++j;
        if (j == n + 1) {
            flag = 0;
            return;
        }
        for (register int k = 1; k <= n; ++k) {
            swap(A[j][k], A[i][k]);
            swap(B[j][k], B[i][k]);
        }
        int kk = pow(A[i][i], prime - 2);
        for (register int k = 1; k <= n; ++k) {
            A[i][k] = 1ll * A[i][k] * kk % prime;
            B[i][k] = 1ll * B[i][k] * kk % prime;
        }
        for (register int p = 1; p <= n; ++p)
            if (p != i) {
                int kk = A[p][i];
                for (int q = 1; q <= n; ++q) {
                    A[p][q] = (A[p][q] - 1ll * kk * A[i][q] % prime + prime) % prime;
                    B[p][q] = (B[p][q] - 1ll * kk * B[i][q] % prime + prime) % prime;
                }
            }
    }
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    n = qread();prime = qread();

    for (register int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            A[i][j] = qread();
        }
    }

    memset(B, 0, sizeof(B));
    for (register int i = 1; i <= n; ++i) {
        B[i][i] = 1;
    }
    //Matrix_Inverse();
    gauss();
    for (register int i = 1; i <= n; ++i) {
        for (register int j = 1; j <= n; ++j) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
