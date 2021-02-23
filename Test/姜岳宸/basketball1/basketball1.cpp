#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXN 30000001
#define MAXM 1025
using namespace std;
const int mod = 1000000007;
int n, v[MAXM], fxor[MAXM][MAXM], fand[MAXM][MAXM], xorsum[MAXM], andsum[MAXM], ans = 0;
signed main()
{
	freopen("basketball1.in", "r", stdin);
	freopen("basketball1.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i < n; i++)
	{
		fxor[i][v[i]] += 1;
		for (int o = 0; o < 1024; o++)
			(fxor[i][o ^ v[i]] += xorsum[o]) %= mod;
		for (int o = 0; o < 1024; o++)
			(xorsum[o] += fxor[i][o]) %= mod;
	}
	for (int i = n; i > 1; i--)
	{
		fand[i][v[i]] += 1;
		for (int o = 0; o < 1024; o++)
			(fand[i][o & v[i]] += andsum[o]) %= mod;
		for (int o = 0; o < 1024; o++)
			(andsum[o] += fand[i][o]) %= mod;
	}
	memset(xorsum, 0, sizeof(xorsum));
	for (int i = 1; i < n; i++)
	{
		for (int o = 0; o < 1024; o++)
			(xorsum[o] += fxor[i][o]) %= mod;
		for (int o = 0; o < 1024; o++)
			(ans += xorsum[o] * fand[i + 1][o] % mod) %= mod;
	}
	cout << ans;
	return 0;
}
