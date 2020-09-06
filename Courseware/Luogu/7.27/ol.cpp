#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x, 0, sizeof(x))
const int MAXN = 1001;
using namespace std;

inline int read()
{
	register int ret = 0, c = getchar(), b = 1;
	while (!isdigit(c))
		b = c == '-' ? -1 : 1, c = getchar();
	while (isdigit(c))
		ret = ret * 10 + c - '0', c = getchar();
	return ret * b;
}

int ol[MAXN], cnt;
void dfs(int x)
{
	ol[++cnt] = x;
	for (int i = head[x]; i; i = nxt[i])
	{
		int v = ver[i];
		if (v == fa[x])
			continue;
		fa[v] = x;
		dfs(v);
		ol[++cnt] = x;
	}
}

int main()
{
	dfs(1);
	return 0;
}
