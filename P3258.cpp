#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600005, MAXM = 600005;
int n, r;
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
struct Edge
{
    Edge *nxt;
    int to;
} * head[MAXM];
void add_edge(int a, int b)
{
    Edge *e = new Edge{head[a], b};
    head[a] = e;
}
class SgnTree
{
private:
    struct Node
    {
        Node *ls, *rs;
        int l, r;
        int v, tag;
        Node() : ls(nullptr), rs(nullptr), l(0), r(0), v(0), tag(0) {}
    };
    void MkTag(Node *x, int t)
    {
        x->tag += t;
        x->v += (x->r - x->l + 1) * t;
    }
    void PsUp(Node *x)
    {
        x->v = x->ls->v + x->rs->v;
    }
    void PsDw(Node *x)
    {
        if (x->tag == 0)
            return;
        MkTag(x->ls, x->tag);
        MkTag(x->rs, x->tag);
        x->tag = 0;
    }
    bool InRng(Node *x, int L, int R) { return L <= x->l && x->r <= R; }
    bool OutRng(Node *x, int L, int R) { return x->r < L || R < x->l; }

public:
    Node *rot;
    SgnTree() { rot = new Node(); }
    void Build(Node *x, int L, int R)
    {
        x->l = L;
        x->r = R;
        x->tag = x->v = 0;
        if (L == R)
        {
            x->ls = x->rs = nullptr;
            return;
        }
        int M = (L + R) >> 1;
        Build(x->ls = new Node(), L, M);
        Build(x->rs = new Node(), M + 1, R);
        PsUp(x);
    }
    void Upd(Node *x, int L, int R, int K)
    {
        if (InRng(x, L, R))
            MkTag(x, K);
        else if (!OutRng(x, L, R))
        {
            PsDw(x);
            Upd(x->ls, L, R, K);
            Upd(x->rs, L, R, K);
            PsUp(x);
        }
    }
    int Qry(Node *x, int L, int R)
    {
        if (InRng(x, L, R))
            return x->v;
        else if (OutRng(x, L, R))
            return 0;
        else
        {
            PsDw(x);
            return Qry(x->ls, L, R) + Qry(x->rs, L, R);
        }
    }
};

namespace CutTree
{
    struct Node
    {
        Node *fa /*父亲结点*/, *hvySon /*重儿子*/, *lnkTp /*链顶端结点*/;
        int dep /*深度*/, realId /*对应的图中编号*/, siz /*子树大小*/, cutId /*结点剖分后的新编号*/;
        Node() : fa(nullptr), hvySon(nullptr), lnkTp(nullptr), dep(0), realId(0), siz(0), cutId(0) {}
    } * rot;
    static Node *toNode[MAXN]; //toNode[i] : 图中编号 i 对应的结点。
    int cutCnt;                //产生连续的dfs序列
    SgnTree SgnTr;             //用来维护的线段树
    /**
     * 第一次搜索。
     * 处理父亲、真实编号、深度、子树大小、重儿子。
     * 开始：Dfs_1(rot, nul, 1, r)
     * @param x 当前结点指针。
     * @param fa 当前结点的父节点。
     * @param dep 当前深度。
     * @param realId 当前结点对应的真实编号。
    */
    void Dfs_1(Node *x, Node *fa, int dep, int realId)
    {
        x->fa = fa;
        x->dep = dep;
        x->siz = 1;
        x->realId = realId;
        toNode[x->realId] = x;
        for (Edge *e = head[realId]; e != nullptr; e = e->nxt)
        {
            int v = e->to;
            if (fa != nullptr && fa->realId == v)
            {
                continue;
            }
            Node *y = new Node();
            Dfs_1(y, x, dep + 1, v);
            x->siz += y->siz;
            if (y->siz > (x->hvySon == nullptr ? 0 : x->hvySon->siz))
                x->hvySon = y;
        }
    }
    /**
     * 第二次搜索。
     * 处理链的顶端、dfs序、结点剖分后的新编号。
     * @param x 当前结点。
     * @param tp 重链顶端。
    */
    void Dfs_2(Node *x, Node *tp)
    {
        x->lnkTp = tp;
        x->cutId = ++cutCnt;
        if (x->hvySon == nullptr)
            return;
        Dfs_2(x->hvySon, tp);

        int realId = x->realId;
        for (Edge *e = head[realId]; e != nullptr; e = e->nxt)
        {
            Node *v = toNode[e->to];
            if (v == x->fa || v == x->hvySon)
                continue;
            Dfs_2(v, v);
        }
    }
    /**
     * 建立树。
     * @e 注意在边输入完之后调用此函数。
    */
    void Build()
    {
        rot = new Node();
        Dfs_1(rot, nullptr, 1, r);
        Dfs_2(rot, rot);
        SgnTr.Build(SgnTr.rot, 1, n);
    }
    /**
     * 修改一条链上的点权。
     * @param _x 链的头结点编号。
     * @param _y 链的尾结点编号。
     * @param k 给链上的每一个点加上的值。
     * 要把 _x, _y 转换成它们对应的结点，即使用数组 @e toNode[_x],toNode[_y] 。
    */
    void UpdLne(int _x, int _y, int k)
    {
        Node *x = toNode[_x], *y = toNode[_y];
        while (x->lnkTp->realId != y->lnkTp->realId)
        {
            if (x->lnkTp->dep >= y->lnkTp->dep)
            {
                SgnTr.Upd(SgnTr.rot, x->lnkTp->cutId, x->cutId, k);
                x = x->lnkTp->fa;
            }
            else
            {
                SgnTr.Upd(SgnTr.rot, y->lnkTp->cutId, y->cutId, k);
                y = y->lnkTp->fa;
            }
        }
        if (x->dep <= y->dep)
            SgnTr.Upd(SgnTr.rot, x->cutId, y->cutId, k);
        else
            SgnTr.Upd(SgnTr.rot, y->cutId, x->cutId, k);
    }
    /**
     * 查询一条链上的点权和。
     * @param _x 链的头结点编号。
     * @param _y 链的尾结点编号。
     * @return 这条链的点权和。
    */
    int QryLne(int _x, int _y)
    {
        int ans = 0;
        Node *x = toNode[_x], *y = toNode[_y];
        while (x->lnkTp->realId != y->lnkTp->realId)
        {
            // 一个重链一个重链地跳
            if (x->lnkTp->dep >= y->lnkTp->dep)
            {
                ans += SgnTr.Qry(SgnTr.rot, x->lnkTp->cutId, x->cutId);
                x = x->lnkTp->fa;
            }
            else
            {
                ans += SgnTr.Qry(SgnTr.rot, y->lnkTp->cutId, y->cutId);
                y = y->lnkTp->fa;
            }
        }
        if (x->dep <= y->dep)
            ans += SgnTr.Qry(SgnTr.rot, x->cutId, y->cutId);
        else
            ans += SgnTr.Qry(SgnTr.rot, y->cutId, x->cutId);
        return ans;
    }
}; // namespace CutTree
int path[MAXN];
int main()
{
    n = read();
    r = 1;
    for (int i = 1; i <= n; i++)
        path[i] = read();
    for (int i = 1, a, b; i < n; i++)
    {
        a = read(), b = read();
        add_edge(a, b);
        add_edge(b, a);
    }
    CutTree::Build();
    CutTree::UpdLne(path[1], path[2], 1);
    for (int i = 2; i < n; i++)
    {
        CutTree::UpdLne(path[i], path[i + 1], 1);
        CutTree::UpdLne(path[i], path[i], -1);
    }
    CutTree::UpdLne(path[n], path[n], -1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", CutTree::QryLne(i, i));
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}