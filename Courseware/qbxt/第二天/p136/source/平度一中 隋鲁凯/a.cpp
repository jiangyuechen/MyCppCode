#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

inline int get_num() {
	int num = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9')
		num = num * 10 + c - '0', c = getchar();
	return num;
}

const int maxn = 105;

int n, p;

struct Matrix {
	ll mx[maxn][maxn];
	Matrix() {
		memset(mx, 0, sizeof(mx));
	}
} A, B;

inline ll pow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p, b >>= 1;
	}
	return ans;
}

inline void gauss() {
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (!A.mx[j][i] && j <= n) ++j;
		for (int k = 1; k <= n; ++k) {
			swap(A.mx[j][k], A.mx[i][k]);
			swap(B.mx[j][k], B.mx[i][k]);
		}
		ll kk = pow(A.mx[i][i], p - 2);
		for (int k = 1; k <= n; ++k) {
			A.mx[i][k] = A.mx[i][k] * kk % p;
			B.mx[i][k] = B.mx[i][k] * kk % p;
		}
		for (int k = 1; k <= n; ++k)
			if (k != i) {
				ll kk = A.mx[k][i];
				for (int l = 1; l <= n; ++l) {
					A.mx[k][l] = (A.mx[k][l] - A.mx[i][l] * kk % p + p) % p;
					B.mx[k][l] = (B.mx[k][l] - B.mx[i][l] * kk % p + p) % p;
				}
			}
	}
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	n = get_num(), p = get_num();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			A.mx[i][j] = get_num();
	for (int i = 1; i <= n; ++i)
		B.mx[i][i] = 1;
	gauss();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			printf("%lld ", B.mx[i][j]);
		printf("\n");
	}
	return 0;
}
