#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 3;
const int Inf = 0x7fffffff;
const int Mod = 1e6 + 7;

LL Read() {
    LL X = 0; char ch = getchar();
    while (ch > '9' || ch < '0') ch = getchar();
    while (ch >= '0' && ch <= '9')
        X = (X << 1) + (X << 3) + (ch ^ 48), ch = getchar();
    return X;
}

long long A, B, N, K;
long long q, p, a1, a2, n, mod;
struct MAT {
    LL M[MAXN][MAXN];
} D, A;

inline MAT Calc(MAT X, MAT Y) {
    MAT Z;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            for (int k = 1; k <= 2; k++)
                Z.M[i][j] = (Z.M[i][j] % Mod + (X.M[i][k] % Mod + Y.M[k][j] % Mod) % Mod) % Mod;
    return Z;
}

inline void Quick_Pow() {
    while (N) {
        if (N & 1) A = Calc(A, D);
        D = Calc(D, D); N >>= 1;
    }   return;
}

inline void Init() {
    A.M[1][1] = 1; A.M[1][2] = 1;
    D.M[1][1] = A; D.M[2][1] = B;
    D.M[1][2] = 1;
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    N = Read(); A = Read(); B = Read();
    Init(); Quick_Pow();
    if (N + 2 == 1) printf("%d\n", A.M[1][2]) % Mod;
    else printf("%d\n", A.M[1][1] % Mod);
    return 0;
}
