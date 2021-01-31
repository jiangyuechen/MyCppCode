#include <bits/stdc++.h>
using namespace std;
#define SZ 1000002
#define il inline
#define rg register int
#define lson rt << 1
#define rson rt << 1 | 1
int col[SZ];
int n, lc, rc;
struct Segtree
{
    int l, r, lc, rc, c, v;
} tr[SZ << 4];
il void Seg_debug()
{
    for (rg i = 1; i <= n * 3; ++i)
        printf("#%d : l:%d r:%d lc:%d rc:%d c:%d v:%d\n", i, tr[i].l, tr[i].r, tr[i].lc, tr[i].rc, tr[i].c, tr[i].v);
}
il void pushup(rg rt)
{
    tr[rt].v = tr[lson].v + tr[rson].v;
    if (tr[lson].rc == tr[rson].lc)
        --tr[rt].v;
    tr[rt].lc = tr[lson].lc;
    tr[rt].rc = tr[rson].rc;
}
il void pushcol(rg rt, rg col)
{
    tr[rt].lc = tr[rt].rc = col;
    tr[rt].v = 1, tr[rt].c = col;
}
il void pushdown(rg rt)
{
    if (tr[rt].c)
    {
        if (lson)
            pushcol(lson, tr[rt].c);
        if (rson)
            pushcol(rson, tr[rt].c);
        tr[rt].c = 0;
    }
}
void build(rg rt, rg l, rg r)
{
    tr[rt].l = l, tr[rt].r = r;
    if (l == r)
    {
        tr[rt].lc = tr[rt].rc = col[l];
        tr[rt].v = 1;
        return;
    }
    rg mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void modify(rg rt, rg L, rg R, rg x)
{
    rg l = tr[rt].l, r = tr[rt].r;
    if (L <= l && r <= R)
    {
        pushcol(rt, x);
        return;
    }
    pushdown(rt);
    rg mid = l + r >> 1;
    if (L <= mid)
        modify(lson, L, R, x);
    if (R > mid)
        modify(rson, L, R, x);
    pushup(rt);
}
int query(rg rt, rg L, rg R)
{
    rg l = tr[rt].l, r = tr[rt].r;
    if (L <= l && r <= R)
    {
        if (l == L)
            lc = tr[rt].lc;
        if (r == R)
            rc = tr[rt].rc;
        return tr[rt].v;
    }
    pushdown(rt);
    rg mid = l + r >> 1;
    if (R <= mid)
        return query(lson, L, R);
    if (L > mid)
        return query(rson, L, R);
    rg ret = query(lson, L, R) + query(rson, L, R);
    if (tr[lson].rc == tr[rson].lc)
        --ret;
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> col[i];
}