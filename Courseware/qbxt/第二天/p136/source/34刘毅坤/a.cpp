#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 110;
int n, m, mod, r;
int f[N][N << 1];

template<class T>inline void read(T &x) {
	x = 0; int f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	x = f ? -x : x;
	return;
}

int qpow(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}
signed main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	read(n), read(mod);
	m = n << 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) read(f[i][j]);
		f[i][n + i] = 1;
	}
	
	for (int i = 1; i <= n; ++i) { 
		for (int j = i; j <= n; ++j)
			if (f[j][i]) {
				for (int k = 1; k <= m; ++k) swap(f[i][k], f[j][k]);
				break;
			}
		r = qpow(f[i][i], mod - 2);
		for (int j = i; j <= m; ++j) f[i][j] = f[i][j] * r % mod;
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				r = f[j][i];
				for (int k = i; k <= m; ++k)
					f[j][k] = (f[j][k] - r * f[i][k] % mod + mod) % mod;
			}
	}
	
	for(int i = 1; i <= n; ++i,puts(""))
		for(int j = n + 1; j <= m; ++j) printf("%lld ",f[i][j]);
	return 0;
}
