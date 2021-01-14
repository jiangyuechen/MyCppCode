#include <bits/stdc++.h>
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
using namespace std;

inline int read()
{
    int x = 0;
    char ch = ' ';
    int f = 1;
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        f = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}

struct Node
{
    Node *son[2], *fa;
    int key, cnt, size;
    Node() { key = cnt = size = 0; }
    inline bool Get_Which() { return fa->son[1] == this; }
    inline void Upd() { size = son[0]->size + son[1]->size + cnt; }
    inline void Clr() { key = cnt = size = 0; }
} t[MAXN], *null, *root;
int n, sz;
inline Node *New()
{
    ++sz;
    t[sz].son[0] = t[sz].son[1] = t[sz].fa = null;
    return &t[sz];
}
inline void rotate(Node *x)
{
    Node *y = x->fa, *z = y->fa;
    int w = x->Get_Which(), w2 = y->Get_Which();
    y->son[w] = x->son[w ^ 1];
    y->son[w]->fa = y;
    x->son[w ^ 1] = y;
    y->fa = x;
    x->fa = z;
    if (z != null)
        z->son[w2] = x;
    y->Upd();
    x->Upd();
}
inline void Splay(Node *x)
{
    for (Node *fa = null; (fa = x->fa) != null; rotate(x))
        if (fa->fa != null)
            rotate((fa->Get_Which() == x->Get_Which()) ? fa : x);
    root = x;
}
inline void Insert(int x)
{
    if (root == null)
    {
        root = New();
        root->key = x;
        root->cnt = root->size = 1;
        return;
    }
    Node *now = root, *fa = null;
    while (1)
    {
        if (x == now->key)
        {
            now->cnt++;
            Splay(now);
            return;
        }
        fa = now;
        now = now->son[x > now->key];
        if (now == null)
        {
            fa->son[x > fa->key] = now = New();
            now->key = x;
            now->cnt = 1;
            now->fa = fa;
            Splay(now);
            return;
        }
    }
}
inline int Kth(int k)
{
    Node *now = root;
    while (1)
    {
        if (now->son[0] != null && k <= now->son[0]->size)
            now = now->son[0];
        else
        {
            int lsize = now->son[0]->size + now->cnt;
            if (k <= lsize)
                return now->key;
            k -= lsize;
            now = now->son[1];
        }
    }
}
inline int Rank(int x)
{
    Node *now = root;
    int ans = 0;
    while (1)
    {
        if (now->son[0] != null && x < now->key)
            now = now->son[0];
        else
        {
            ans += now->son[0]->size;
            if (x == now->key)
            {
                Splay(now);
                return ans;
            }
            ans += now->cnt;
            now = now->son[1];
        }
    }
}
inline Node *pre()
{
    Node *now = root->son[0];
    while (now->son[1] != null)
        now = now->son[1];
    return now;
}
inline void Del(int x)
{
    Rank(x);
    if (root->cnt > 1)
    {
        root->cnt--;
        root->Upd();
        return;
    }
    Node *left = pre(), *oldroot = root;
    Splay(left);
    left->son[1] = oldroot->son[1];
    left->son[1]->fa = left;
    oldroot->Clr();
    root->Upd();
}

inline int Pre(Node *now, int val)
{
    if (now == null)
        return -inf;
    if (val > now->key)
        return max(now->key, Pre(now->son[1], val));
    else
        return Pre(now->son[0], val);
}
inline int Next(Node *now, int val)
{
    if (now == null)
        return inf;
    if (val < now->key)
        return min(now->key, Next(now->son[0], val));
    else
        return Next(now->son[1], val);
}
int main()
{
    root = null = &t[0];
    n = read();
    Insert(inf);
    Insert(-inf);
    while (n--)
    {
        int opt = read(), x = read();
        switch (opt)
        {
        case 1:
            Insert(x);
            break;
        case 2:
            Del(x);
            break;
        case 3:
            printf("%d\n", Rank(x));
            break;
        case 4:
            printf("%d\n", Kth(x + 1));
            break;
        case 5:
            printf("%d\n", Pre(root, x));
            break;
        case 6:
            printf("%d\n", Next(root, x));
            break;
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}