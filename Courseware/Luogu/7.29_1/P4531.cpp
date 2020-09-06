#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define ll long long
#define INF 0x3fffff
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

#define M 500005

struct tree2
{
	tree2 *lson, *rson;
	int ml, mr, mx, sum;
} dizhi[M << 2], *root = &dizhi[0];

int t, n, m, a[M], pt;

void update(tree2 *tree, tree2 *lson, tree2 *rson)
{
	tree->sum = lson->sum + rson->sum;
	tree->ml = max(lson->ml, lson->sum + rson->ml);
	tree->mr = max(rson->mr, rson->sum + lson->mr);
	tree->mx = max(lson->mr + rson->ml, max(lson->mx, rson->mx));
}

void bulid(tree2 *tree, int l, int r)
{
	if (l == r)
	{
		tree->sum = tree->ml = tree->mr = tree->mx = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	tree->lson = &dizhi[++t];
	tree->rson = &dizhi[++t];
	bulid(tree->lson, l, mid);
	bulid(tree->rson, mid + 1, r);
	update(tree, tree->lson, tree->rson);
}

tree2 *query(tree2 *tree, int l, int r, int x, int y)
{
	if (x <= l & y >= r)
		return tree;
	int mid = (l + r) >> 1;
	tree2 *t1 = NULL, *t2 = NULL;
	if (x <= mid)
		t1 = query(tree->lson, l, mid, x, y);
	if (y > mid)
		t2 = query(tree->rson, mid + 1, r, x, y);
	if (t1 == NULL)
		return t2;
	if (t2 == NULL)
		return t1;
	tree2 *ret = &dizhi[++t];
	update(ret, t1, t2);
	return ret;
}

void change(tree2 *tree, int l, int r, int x, int y)
{
	if (l == r)
	{
		tree->sum = tree->ml = tree->mr = tree->mx = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		change(tree->lson, l, mid, x, y);
	else
		change(tree->rson, mid + 1, r, x, y);
	update(tree, tree->lson, tree->rson);
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	bulid(root, 1, n);
	pt = t;
	for (int i = 1; i <= m; i++)
	{
		int a = read(), b = read(), c = read();
		if (a == 1)
		{
			if (c < b)
				swap(b, c);
			t = pt;
			printf("%d\n", query(root, 1, n, b, c)->mx);
		}
		if (a == 2)
		{
			change(root, 1, n, b, c);
		}
	}
	return 0;
}
