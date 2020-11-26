#include <bits/stdc++.h>
#include <exception>

using namespace std;

constexpr int MAXN = 100001;
int a[MAXN];
struct Node
{
    int l, r;
    int v, tag;
    Node *ls, *rs;
    void pushup()
    {
        this->v = ls->v + rs->v;
    }
    void maketag(int _tag)
    {
        this->tag += _tag;
        this->v += _tag * (r - l + 1);
    }
    void pushdown()
    {
        if (!this->tag)
            return;
        ls->maketag(tag);
        rs->maketag(tag);
        tag = 0;
    }
    inline bool in_range(int L, int R)
    {
        return L <= l && r <= R;
    }
    inline bool out_of_range(int L, int R)
    {
        return R < l || r < L;
    }
    Node(int L, int R)
    {
        l = L;
        r = R;
        tag = 0;
        if (l == r)
        {
            v = a[l];
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
    void upd(int L, int R, int K)
    {
        if (in_range(L, R))
            maketag(K);
        else if (!out_of_range(L, R))
        {
            pushdown();
            ls->upd(L, R, K);
            rs->upd(L, R, K);
            pushup();
        }
    }
    int qry(int L, int R)
    {
        if (in_range(L, R))
            return v;
        else if (out_of_range(L, R))
            return 0;
        else
        {
            pushdown();
            return ls->qry(L, R) + rs->qry(L, R);
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}