#include <cstdio>
#include <cstring>

const int p = 1e6 + 7;

struct Matrix {
	int mx[2][2];
	Matrix() {
		memset(mx, 0 ,sizeof(mx));
	}
	Matrix operator * (const Matrix& rhs) const {
		Matrix ans;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k) {
					ans.mx[i][j] +=  1ll * mx[i][k] * rhs.mx[k][j] % p;
					ans.mx[i][j] %= p;
				}
		return ans;
	}
} A;

Matrix pow(Matrix a, int b) {
	Matrix ans;
	for (int i = 0; i < 2; ++i)
			ans.mx[i][i] = 1;
	while (b) {
		if (b & 1) ans = ans * a;
		a = a * a, b >>= 1;
	}
	return ans;
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	A.mx[0][0] = a, A.mx[0][1] = b;
	A.mx[1][0] = 1, A.mx[1][1] = 0;
	n = pow(A, n).mx[0][1];
	A = pow(A, n);
	printf("%d", A.mx[0][1]);
	return 0;
}
