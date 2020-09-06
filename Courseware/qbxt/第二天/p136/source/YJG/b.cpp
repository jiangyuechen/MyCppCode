#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if(n == k) return printf("%d 1", n), 0;
	if(k == 1) return printf("1 1"), 0;
	if(k == 2) return printf("%d %d", n, n - 1), 0;
	if(n - 1 == k) return printf("%d 2", n), 0;
	return printf("%d %d", n % k + k, k + n / k), 0;
}
