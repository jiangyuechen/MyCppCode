#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 200005, MAXM = 200005;
ll n, q;
inline ll read()
{
    ll s = 0, w = 1;
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
struct Edge
{
    ll to, nxt;
} e[MAXM];
ll head[MAXN], top;
void add_edge(ll a, ll b)
{
    e[++top].to = b;
    e[top].nxt = head[a];
    head[a] = top;
}
ll orgnV[MAXN], a[MAXN];
class SgnTree
{
private:
    struct Node
    {
        Node *ls, *rs;
        ll l, r;
        ll v;
        ll vmax;
        Node() : ls(nullptr), rs(nullptr), l(0), r(0), v(0), vmax(-2147483648) {}
    };
    void PsUp(Node *x)
    {
        x->v = x->ls->v + x->rs->v;
        x->vmax = max(x->ls->vmax, x->rs->vmax);
    }
    bool InRng(Node *x, ll L, ll R) { return L <= x->l && x->r <= R; }
    bool OutRng(Node *x, ll L, ll R) { return x->r < L || R < x->l; }

public:
    Node *rot;
    SgnTree() { rot = new Node(); }

    void Build(Node *x, ll L, ll R)
    {
        x->l = L;
        x->r = R;
        if (L == R)
        {
            x->ls = x->rs = nullptr;
            x->v = x->vmax = a[L];
            return;
        }
        ll M = (L + R) >> 1;
        Build(x->ls = new Node(), L, M);
        Build(x->rs = new Node(), M + 1, R);
        PsUp(x);
    }
    void Upd(Node *x, ll L, ll R, ll K)
    {
        if (InRng(x, L, R))
        {
            x->v = x->vmax = K;
            return;
        }
        if (!OutRng(x, L, R))
        {
            Upd(x->ls, L, R, K);
            Upd(x->rs, L, R, K);
            PsUp(x);
        }
    }
    void Upd(Node *x, ll S, ll K)
    {
        Upd(x, S, S, K);
    }
    ll Qry_Sum(Node *x, ll L, ll R)
    {
        if (InRng(x, L, R))
            return x->v;
        else if (OutRng(x, L, R))
            return 0;
        else
            return Qry_Sum(x->ls, L, R) + Qry_Sum(x->rs, L, R);
    }
    ll Qry_Max(Node *x, ll L, ll R)
    {
        if (InRng(x, L, R))
            return x->vmax;
        else if (OutRng(x, L, R))
            return -2147483648;
        else
            return max(Qry_Max(x->ls, L, R), Qry_Max(x->rs, L, R));
    }
};

namespace CutTree
{
    struct Node
    {
        Node *fa /*父亲结点*/, *hvySon /*重儿子*/, *lnkTp /*链顶端结点*/;
        ll dep /*深度*/, realId /*对应的图中编号*/, siz /*子树大小*/, cutId /*结点剖分后的新编号*/;
        vector<Node *> sons; /*儿子指针*/
        Node() : fa(nullptr), hvySon(nullptr), lnkTp(nullptr), dep(0), realId(0), siz(0), cutId(0), sons() {}
    } * rot;
    static Node *toNode[MAXN]; //toNode[i] : 图中编号 i 对应的结点。
    ll cutCnt;                 //产生连续的dfs序列
    SgnTree SgnTr;             //用来维护的线段树
    void Dfs_1(Node *x, Node *fa, ll dep, ll realId)
    {
        x->fa = fa;
        x->dep = dep;
        x->siz = 1;
        x->realId = realId;
        toNode[x->realId] = x;
        for (ll i = head[realId]; i; i = e[i].nxt)
        {
            ll v = e[i].to;
            if (fa != nullptr && fa->realId == v)
            {
                // printf("fa:%d now:%d nxt:%d\n", fa ? fa->realId : 0, x->realId, v);
                continue;
            }
            Node *y = new Node();
            Dfs_1(y, x, dep + 1, v);
            x->siz += y->siz;
            x->sons.push_back(y);
            if (y->siz > (x->hvySon == nullptr ? 0 : x->hvySon->siz))
                x->hvySon = y;
        }
    }
    void Dfs_2(Node *x, Node *tp)
    {
        x->lnkTp = tp;
        x->cutId = ++cutCnt;
        a[cutCnt] = orgnV[x->realId];
        if (x->hvySon == nullptr)
            return;
        Dfs_2(x->hvySon, tp);

        ll realId = x->realId;
        for (vector<Node *>::iterator it = x->sons.begin(); it != x->sons.end(); it++)
        {
            Node *v = *it;
            if (v == x->fa || v == x->hvySon)
                continue;
            Dfs_2(v, v);
        }
    }
    void Build()
    {
        rot = new Node();
        Dfs_1(rot, nullptr, 1, 1);
        Dfs_2(rot, rot);
        SgnTr.Build(SgnTr.rot, 1, n);
    }
    void UpdDot(ll _x, ll k)
    {
        Node *x = toNode[_x];
        SgnTr.Upd(SgnTr.rot, x->cutId, k);
    }
    ll QrySum(ll _x, ll _y)
    {
        ll ans = 0;
        Node *x = toNode[_x], *y = toNode[_y];
        while (x->lnkTp->realId != y->lnkTp->realId)
        {
            if (x->lnkTp->dep >= y->lnkTp->dep)
            {
                ans += SgnTr.Qry_Sum(SgnTr.rot, x->lnkTp->cutId, x->cutId);
                x = x->lnkTp->fa;
            }
            else
            {
                ans += SgnTr.Qry_Sum(SgnTr.rot, y->lnkTp->cutId, y->cutId);
                y = y->lnkTp->fa;
            }
        }
        if (x->dep <= y->dep)
        {
            ans += SgnTr.Qry_Sum(SgnTr.rot, x->cutId, y->cutId);
        }
        else
        {
            ans += SgnTr.Qry_Sum(SgnTr.rot, y->cutId, x->cutId);
        }
        return ans;
    }
    ll QryMax(ll _x, ll _y)
    {
        ll ans = -2147483648;
        Node *x = toNode[_x], *y = toNode[_y];
        while (x->lnkTp->realId != y->lnkTp->realId)
        {
            if (x->lnkTp->dep >= y->lnkTp->dep)
            {
                ans = max(ans, SgnTr.Qry_Max(SgnTr.rot, x->lnkTp->cutId, x->cutId));
                x = x->lnkTp->fa;
            }
            else
            {
                ans = max(ans, SgnTr.Qry_Max(SgnTr.rot, y->lnkTp->cutId, y->cutId));
                y = y->lnkTp->fa;
            }
        }
        if (x->dep <= y->dep)
        {
            ans = max(ans, SgnTr.Qry_Max(SgnTr.rot, x->cutId, y->cutId));
        }
        else
        {
            ans = max(ans, SgnTr.Qry_Max(SgnTr.rot, y->cutId, x->cutId));
        }
        return ans;
    }
}; // namespace CutTree

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        ll a = read(), b = read();
        add_edge(a, b);
        add_edge(b, a);
    }
    for (int i = 1; i <= n; i++)
        orgnV[i] = read();
    CutTree::Build();
    q = read();
    while (q--)
    {
        ll x, y;
        char op[10];
        scanf("%s%lld%lld", op, &x, &y);
        if (op[1] == 'H')
            CutTree::UpdDot(x, y);
        if (op[1] == 'M')
            printf("%lld\n", CutTree::QryMax(x, y));
        if (op[1] == 'S')
            printf("%lld\n", CutTree::QrySum(x, y));
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}