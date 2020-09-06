#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 500001;
int a[MAXN];
int n, q;
struct Node
{
    Node *ls, *rs;
    int l, r;
    int max_left, max_right, sum, max_total;
    void pushup()
    {
        max_total = max({ls->max_total,
                         rs->max_total,
                         ls->max_right + rs->max_left});
        max_left = max(ls->max_left, ls->sum + rs->max_left);
        max_right = max(rs->max_right, rs->sum + ls->max_right);
        sum = ls->sum + rs->sum;
    }
    void pushup(Node *lls, Node *rrs)
    {
        max_total = max({lls->max_total,
                         rrs->max_total,
                         lls->max_right + rrs->max_left});
        max_left = max(lls->max_left, lls->sum + rrs->max_left);
        max_right = max(rrs->max_right, rrs->sum + lls->max_right);
        sum = lls->sum + rrs->sum;
    }
    Node(int L, int R)
    {
        l = L;
        r = R;
        if (l == r)
        {
            max_left = max_right = sum = max_total = a[l];
            ls = rs = nullptr;
        }
        else
        {
            int M = (L + R) >> 1;
            ls = new Node(L, M);
            rs = new Node(M + 1, R);
            pushup();
        }
    }
    inline bool InRange(int L, int R)
    {
        return (L <= l) && (r <= R);
    }
    inline bool OutofRange(int L, int R)
    {
        return (l > R) || (r < L);
    }
    void upd(int s, int k)
    {
        if (l == r)
        {
            max_left = max_right = max_total = sum = k;
            return;
        }
        if (s <= ls->r)
            ls->upd(s, k);
        else
            rs->upd(s, k);
        pushup();
    }
    Node *qry(int l, int r, int x, int y)
    {
        if (x <= l && y >= r)
            return this;
        int mid = (l + r) >> 1;
        Node *t1 = NULL, *t2 = NULL;
        if (x <= mid)
            t1 = ls->qry(l, mid, x, y);
        if (y > mid)
            t2 = rs->qry(mid + 1, r, x, y);
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        Node *ret = new Node(l, r);
        ret->pushup(t1, t2);
        return ret;
    }
};
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    Node *rot = new Node(1, n);
    while (q--)
    {
        int k, l, r;
        scanf("%d%d%d", &k, &l, &r);
        if (k == 1)
        {
            if (l > r)
                swap(l, r);
            printf("%d\n", rot->qry(1, n, l, r)->max_total);
        }
        else if (k == 2)
        {
            rot->upd(l, r);
        }
    }
    END_PROGRAM
}