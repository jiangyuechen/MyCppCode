#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1000005;
int t;
int k, n;
int a[MAXN];
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n * k; i++)
		{
			cin >> a[i];
		}
		ll ans = 0;
		int indent = n / 2 + 1;
		for (int i = n * k + 1 - indent, t = k; t > 0; t--, i -= indent)
		{
			//printf("chosen:%d ",a[i]);
			ans += ll(a[i]);
		}
		printf("%lld\n", ans);
	}
}

/*
2 4
0 24 34 58 62 64 69 78
^    ^     ^     ^
4 3
2 4 16 18 21 27 36 53 82 91 92 95
        ^       ^        ^
3 4
3 11 12 22 33 35 38 67 69 71 94 99
           ^     ^     ^     ^
3 3
1 2 3 4 5 6 7 8 9
      ^   ^   ^
*/