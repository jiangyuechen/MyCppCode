#include <bits/stdc++.h>
const int INF = 2147483647;
const int MAXN = 100001;
class SBT
{
public:
    struct Node
    {
        int v, siz;
        Node *ls, *rs;
        Node() : v(-INF), ls(nullptr), rs(nullptr), siz(0) {}
        Node(int _v) : v(_v), ls(nullptr), rs(nullptr), siz(1) {}
    };
    void Rgt_Rotate(Node *x)
    {
        Node *k = x->ls;
        x->ls = k->rs;
        k->rs = x;
        k->siz = x->siz;
        x->siz = x->ls->siz + x->rs->siz + 1;
        x = k;
    }
    void Lft_Rotate(Node *x)
    {
        Node *k = x->rs;
        x->rs = k->ls;
        k->ls = x;
        k->siz = x->siz;
        x->siz = x->ls->siz + x->rs->siz + 1;
        x = k;
    }
    void Maintain(Node *x, bool flag)
    {
        if (!flag)
        {
            if (x->ls->ls->siz > x->rs->siz)
                Rgt_Rotate(x);
            else if (x->ls->rs->siz > x->rs->siz)
            {
                Lft_Rotate(x->ls);
                Rgt_Rotate(x);
            }
            else
                return;
        }
        else
        {
            if (x->rs->rs->siz > x->ls->siz)
                Lft_Rotate(x);
            else if (x->rs->ls->siz > x->ls->siz)
            {
                Rgt_Rotate(x->rs);
                Lft_Rotate(x);
            }
            else
                return;
        }
        Maintain(x->ls, false);
        Maintain(x->rs, true);
        Maintain(x, false);
        Maintain(x, true);
    }
    Node *rot;
    static Node *nul;
    SBT()
    {
        nul = new Node();
        rot = nul;
        Insert(-INF);
        Insert(INF);
    }
    void __Insert(Node *x, int val)
    {
        if (x == nul)
            x = new Node(val);
        else
        {
            ++x->siz;
            if (val < x->v)
                __Insert(x->ls, val);
            else
                __Insert(x->rs, val);
            Maintain(x, val >= x->v);
        }
    }
    void Insert(int val) { __Insert(rot, val); }
    int __Delete(Node *x, int val)
    {
        --x->siz;
        int r = x->v;
        if ((val == r) || (val < r && x->ls == nul) || (val >= r && x->rs == nul))
        {
            int r = x->v;
            if (x->ls == nul && x->rs == nul)
                x = nul;
            else if (x->ls == nul)
                x = x->rs;
            else if (x->rs == nul)
                x = x->ls;
            else
                x->v = __Delete(x->ls, x->v + 1);
            return r;
        }
        else
        {
            if (val < x->v)
                return __Delete(x->ls, val);
            else
                return __Delete(x->rs, val);
        }
    }
    void Delete(int val) { __Delete(rot, val); }
    Node *__Kth(Node *x, int k) // 查询排名为 k 的数字
    {
        if (k == x->ls->siz + 1)
            return x;
        if (k <= x->ls->siz)
            return __Kth(x->ls, k);
        return __Kth(x->rs, k - 1 - x->ls->siz);
    }
    int Kth(int k) { return __Kth(rot, k)->v; }
    int __Rnk(Node *x, int k)
    {
        if (x == nul)
            return 1;
        // if (k <= x->v)
    }
};
