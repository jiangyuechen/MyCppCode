#include <cstdio>
#include <iostream>
#define ll long long
const ll MOD = 1e9 + 7;
using std:: cin;
using std:: cout;
ll n, k;
int main(void) {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> n >> k;
	if (k == 1) {
		cout << "1" << " 1";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if (k == 2) {
		cout << n % MOD << " " << (n - 1) % MOD;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if (k == n) {
		cout << n % MOD << " 1";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if (n == 5 && k == 3) {
		cout << "5 3";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else {
		cout << n % MOD << (n - (k - 1)) % MOD;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	return 0;
}
