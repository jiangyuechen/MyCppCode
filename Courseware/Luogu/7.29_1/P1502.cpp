#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define ll long long
#define INF 0x3fffffff
#define MAXINT 2147482647LL
#define clr(x) memset(x, 0, sizeof(x))

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

#define M 200005

struct tree2
{
	tree2 *lson, *rson;
	int lazy, x;
} dizhi[M << 3], *root = &dizhi[0];

int t, n, w, h, ans;

void pushdown(tree2 *tree)
{
	if (tree->lazy == 0)
		return;
	tree->lson->x += tree->lazy;
	tree->lson->lazy += tree->lazy;
	tree->rson->x += tree->lazy;
	tree->rson->lazy += tree->lazy;
	tree->lazy = 0;
}

void change(tree2 *tree, int l, int r, int x, int y, int k)
{
	if (x <= l && y >= r)
	{
		tree->x += k;
		tree->lazy += k;
		return;
	}
	if (tree->lson == NULL)
	{
		tree->lson = &dizhi[++t];
		tree->rson = &dizhi[++t];
	}
	pushdown(tree);
	int mid = (l + r) >> 1;
	if (x <= mid)
		change(tree->lson, l, mid, x, y, k);
	if (y > mid)
		change(tree->rson, mid + 1, r, x, y, k);
	tree->x = max(tree->lson->x, tree->rson->x);
}

struct point
{
	int x, y, l;
} a[M << 1];

bool com(point a, point b)
{
	return a.x < b.x;
}

int main()
{
	int T = read();
	while (T--)
	{
		n = read(), w = read(), h = read();
		ans = 0;
		clr(dizhi);
		t = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = read(), y = read(), l = read();
			a[i * 2 - 1].x = x, a[i * 2 - 1].y = y, a[i * 2 - 1].l = l;
			a[i * 2].x = min((ll)x + w, MAXINT), a[i * 2].y = y, a[i * 2].l = -l;
		}
		sort(a + 1, a + 2 * n + 1, com);
		for (int i = 1; i <= n * 2; i++)
		{
			change(root, 1, MAXINT, a[i].y, min((ll)a[i].y + h - 1, MAXINT), a[i].l);
			if (a[i + 1].x != a[i].x)
				ans = max(ans, root->x);
		}
		printf("%d\n", ans);
	}
	return 0;
}
