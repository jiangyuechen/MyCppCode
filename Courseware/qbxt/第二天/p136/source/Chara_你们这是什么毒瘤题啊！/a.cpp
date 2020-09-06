// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define int long long
#define db double
#define int_t register int
int p = 1e9 + 7;
const int MAXN = 500;
const int eps = 1e-8;
using std::fabs;
using std::swap;
bool flag = 0;
struct mat {
	int a[MAXN][MAXN];
} a, b;
int n;
inline void Init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			b.a[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		b.a[i][i] = 1;
	}
}

inline int ksm(int x, int y, int p) {
	int ans = 1;
	while (y) {
		if (y & 1)
			ans = ans * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return ans;
}

inline int N(int x) {
	return ksm(x, p - 2, p); //fei ma xiao ding li
}

inline void debug() {
	printf("_______________\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", b.a[i][j]);
		}
		puts("");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a.a[i][j]);
		}
		puts("");
	}
	puts("______________");
	puts("");
}

inline void gsxy() {
	for (int i = 1; i <= n; i++) {
		int t = i;
		while (a.a[t][i] == 0 && t <= n)
			t++;
		if (t != i)
			for (int j = 1; j <= n; j++) {
				swap(a.a[i][j], a.a[t][j]);

				swap(b.a[i][j], b.a[t][j]);
			}
		if (t == n + 1) {
			flag = 1;
			continue;
		}
		//       debug();
		int kk = N(a.a[i][i]);
		//       printf("\n%d\n", kk);
		for (int j = 1; j <= n; j++) {
			a.a[i][j] *= kk;
			a.a[i][j] %= p;
			b.a[i][j] *= kk;
			b.a[i][j] %= p;
		}
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			kk = a.a[j][i];
			//          printf("\n%d %d\n", j, kk);
			for (int k = 1; k <= n; k++) {
				a.a[j][k] = (a.a[j][k] - a.a[i][k] * kk % p + p) % p;
				b.a[j][k] = (b.a[j][k] - b.a[i][k] * kk % p + p) % p;
			}
			//         if (j == 1)
			//              debug();
		}
		//     debug();
	}
	return;
}

inline void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%ld ", b.a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}

signed main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%ld", &n);
	scanf("%d", &p);
	Init();
	for (int_t i = 1; i <= n; i++) {
		for (int_t j = 1; j <= n; j++) {
			scanf("%ld", &a.a[i][j]);
		}
	}
	gsxy();
	if (!flag)
		print();
	else
		printf("No Solution\n");
	return 0;
}
