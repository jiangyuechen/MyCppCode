#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
const int MAXN = 10001;
struct operate
{
    int l, r, a, val;
    bool operator<(operate &x)
    {
        return this->a < x.a;
    }
};

operate o[MAXN];
int n, W, H;

struct Node
{
    Node *ls, *rs;
    int l, r;
    int vmax, tag;
    void pushup()
    {
        vmax = max(ls->vmax, rs->vmax);
    }
    void maketag(const int M)
    {
        vmax += M;
        tag += M;
    }
    void pushdown()
    {
        if (!tag)
            return;
        ls->maketag(tag);
        rs->maketag(tag);
        tag = 0;
    }
    inline bool inrange(int L, int R)
    {
        return (L <= this->l && this->r <= R);
    }
    inline bool outrange(int L, int R)
    {
        return (R < this->l || L > this->r);
    }
    Node(const int L, const int R)
    {
        l = L;
        r = R;
        tag = 0;
        if (l == r)
        {
            vmax = 0;
            ls = rs = NULL;
        }
        else
        {
            int M = (L + R) >> 1;
            ls = new Node(L, M);
            rs = new Node(M + 1, R);
            pushup();
        }
    }
    void upd(const int L, const int R, const int W)
    {
        if (inrange(L, R))
            maketag(W);
        else if (!outrange(L, R))
        {
            pushdown();
            ls->upd(L, R, W);
            rs->upd(L, R, W);
            pushup();
        }
    }
};
int ans = -0x7fffffff;
int Y_LABEL_MAX = -0x7fffffff;
int t;
int main()
{
    t = read();
    while (t--)
    {
        n = read();
        W = read();
        H = read();
        memset(o, 0, sizeof(o));
        for (int i = 1, x, y, l; i <= n; i++)
        {
            x = read();
            y = read();
            l = read();
            Y_LABEL_MAX = max(Y_LABEL_MAX, y + H);
            o[i * 2].l = y;
            o[i * 2].r = y + H - 1;
            o[i * 2].val = l;
            o[i * 2].a = x;
            o[i * 2 - 1].l = y;
            o[i * 2 - 1].r = y + H - 1;
            o[i * 2 - 1].val = -l;
            o[i * 2 - 1].a = x + W;
        }
        Node *rot = new Node(1, Y_LABEL_MAX);
        sort(o + 1, o + 2 * n + 1);
        for (int i = 1; i <= n * 2; i++)
        {
            rot->upd(o[i].l, o[i].r, o[i].val);
            if (o[i + 1].a != o[i].a)
                ans = max(ans, rot->vmax);
        }
        printf("%d\n", ans);
    }
    END_PROGRAM
}