#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e6+7;
int n, a, b;
struct node {
	int a[5][5];
} e;
int f[5][5], ans[5][5];

template<class T>inline void read(T &x) {
	x = 0; int f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	x = f ? -x : x;
	return;
}

inline node mul(node x, node y) {
	node c;
	memset(c.a, 0, sizeof(c.a));
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 2; ++j)
			for (int k = 1; k <= 2; ++k)
				c.a[i][j] = (c.a[i][j] + x.a[i][k] * y.a[k][j] % mod) % mod;
	return c;
}

inline node qpow(node x, int y) {
	node ans = e;
	while(y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1,x = mul(x, x);
	}
	return ans;
}

signed main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	read(n), read(a), read(b);
	e.a[1][1] = a, e.a[1][2] = b, e.a[2][1] = 1,e.a[2][2] = 0;
	if (n > 3) e = qpow(e, n - 3);
	f[1][1] = 0, f[2][1] = 1;
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 1; ++j)
			for (int k = 1; k <= 2; ++k)
				ans[i][j] = (ans[i][j] + e.a[i][k] * f[k][j] % mod) % mod;
	e.a[1][1] = a, e.a[1][2] = b, e.a[2][1] = 1,e.a[2][2] = 0;
	if (ans[1][1] > 3) e = qpow(e, ans[1][1] - 2);
	f[1][1] = 0, f[2][1] = 1;
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 1; ++j)
			for (int k = 1; k <= 2; ++k)
				ans[i][j] = (ans[i][j] + e.a[i][k] * f[k][j] % mod) % mod;
	printf("%lld\n",ans[1][1]);
return 0;
}
