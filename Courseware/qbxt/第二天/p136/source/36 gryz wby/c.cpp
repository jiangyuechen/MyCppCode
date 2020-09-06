#include <cstdio>
#include <iostream>
#define ll long long
using std:: cin;
using std:: cout;
const ll MOD = 1e6 + 7;
ll n, a, b;
ll mid[10][10], res[10][10], rec[10][10];
inline void solve_ans(void) {
	register ll t = 0;
	rec[1][1] = res[1][1], rec[2][1] = res[2][1];
	t = (mid[1][1] * rec[1][1] % MOD + mid[1][2] * rec[2][1] % MOD) % MOD;
	res[1][1] = t;
	t = (mid[2][1] * rec[1][1] % MOD + mid[2][2] * rec[2][1] % MOD) % MOD;
	res[2][1] = t;
	return;
}
inline void solve_jz(void) {
	register ll t = 0;
	rec[1][1] = mid[1][1], rec[1][2] = mid[1][2], rec[2][1] = mid[2][1], rec[2][2] = mid[2][2];
	for (int i = 1;i <= 2; i++) {
		for (int j = 1;j <= 2; j++) {
			t = 0;
			for (int k = 1;k <= 2; k++) {
				t = (t + rec[i][k] * rec[k][j] % MOD) % MOD;
			}
			mid[i][j] = t;
		}
	}
	return;
}
inline void tsolve_ans(void) {
	register ll t = 0;
	rec[1][1] = res[1][1], rec[2][1] = res[2][1];
	t = mid[1][1] * rec[1][1] + mid[1][2] * rec[2][1];
	res[1][1] = t;
	t = mid[2][1] * rec[1][1] + mid[2][2] * rec[2][1];
	res[2][1] = t;
	return;
}
inline void tsolve_jz(void) {
	register ll t = 0;
	rec[1][1] = mid[1][1], rec[1][2] = mid[1][2], rec[2][1] = mid[2][1], rec[2][2] = mid[2][2];
	for (int i = 1;i <= 2; i++) {
		for (int j = 1;j <= 2; j++) {
			t = 0;
			for (int k = 1;k <= 2; k++) {
				t = (t + rec[i][k] * rec[k][j] % MOD) % MOD;
			}
			mid[i][j] = t;
		}
	}
	return;
}
inline void tfpowl_jz(void) {
	res[1][1] = mid[2][1] = 1, mid[1][1] = a, mid[1][2] = b;
	while (n > 0) {
		if (n & 1) tsolve_ans();
		tsolve_jz(), n >>= 1;
	}
	n = --res[1][1], a %= MOD, b %= MOD;
	res[1][1] = mid[2][1] = 1, mid[1][1] = a, mid[1][2] = b, res[2][1] = mid[2][2] = 0;
	while (n > 0) {
		if (n & 1) solve_ans();
		solve_jz(), n >>= 1;
	}
	cout << res[1][1];
	return;
}
inline void fpowl_jz(void) {
	a %= MOD, b %= MOD,res[1][1] = mid[2][1] = 1, mid[1][1] = a, mid[1][2] = b;
	while (n > 0) {
		if (n & 1) solve_ans();
		solve_jz(), n >>= 1;
	}
	n = --res[1][1];
	res[1][1] = mid[2][1] = 1, mid[1][1] = a, mid[1][2] = b, res[2][1] = mid[2][2] = 0;
	while (n > 0) {
		if (n & 1) solve_ans();
		solve_jz(), n >>= 1;
	}
	cout << res[1][1];
	return;
}
inline void fpowl(void) {
	a %= MOD, b %= MOD;
	register ll ans = 1, t = a;
	while (n > 0) {
		if (n & 1) ans = ans * a % MOD;
		a = a * a % MOD, n >>= 1;
	}
	n = --ans, ans = 1, a = t;
	while (n > 0) {
		if (n & 1) ans = ans * a % MOD;
		a = a * a % MOD, n >>= 1;
	}
	cout << ans;
	return;
}
int main(void) {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> n >> a >> b;
	--n;
	if (!b) {
		fpowl();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (n <= 10) tfpowl_jz();
	else fpowl_jz();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
