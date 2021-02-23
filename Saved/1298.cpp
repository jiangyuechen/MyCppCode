#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1005;
int t;
char a[MAXN], b[MAXN];
int f[MAXN][MAXN];
int main() {
	cin >> t;
	while (t--) {
		cin >> a + 1 >> b + 1;
		memset(f, 127, sizeof(f));
		int alen = strlen(a + 1), blen = strlen(b + 1);
		f[0][0] = 0;
		for (int i = 1; i <= alen; i++) {
			f[i][0] = i;
		}
		for (int i = 1; i <= blen; i++) {
			f[0][i] = i;
		}
		for (int i = 1; i <= alen; i++) {
			for (int j = 1; j <= blen; j++) {
				if (a[i] == b[j]) {
					f[i][j] = min(f[i][j], f[i - 1][j - 1]);
				} else {
					f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1)));
				}
			}
		}
		cout << f[alen][blen] << '\n';
	}
	system("pause");
}