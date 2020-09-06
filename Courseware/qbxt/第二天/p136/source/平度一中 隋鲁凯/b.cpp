#include <cstdio>

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 1) printf("1 1");
	else if (n == k) printf("%d 1", n);
	else if (k == 2) printf("%d %d", n, n - 1);
	return 0;
}
