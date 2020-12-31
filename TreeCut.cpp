#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001, MAXM = 10001;
int n, m, r, p;
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
    int to, nxt;
} e[MAXM];
int head[MAXN], top;
void add_edge(int a, int b)
{
    e[++top].to = b;
    e[top].nxt = head[a];
    head[a] = top;
}
int orgnV[MAXN], a[MAXN];
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
    int pooltop;
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
    SgnTree(int Val[], int L, int R)
    {
        rot = new Node();
        Build(rot, L, R);
    }
    void Build(Node *x, int L, int R)
    {
        x->l = L;
        x->r = R;
        x->tag = x->v = 0;
        if (L == R)
        {
            x->ls = x->rs = nullptr;
            x->v = a[L];
            return;
        }
        int M = (L + R) >> 1;
        Build(new Node(), L, M);
        Build(new Node(), M + 1, R);
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
    int pooltop, cutCnt;       //产生连续的dfs序列
    void debug(Node *x)
    {
        if (x->hvySon == nullptr)
            return;
        printf("(realId : %d)->", x->realId);
        debug(x->hvySon);
    }
    SgnTree SgnTr;
    /**
     * 第一次搜索。
     * 处理父亲、深度、子树大小、重儿子。
     * 开始：Dfs_1(rot,nul,1,1)
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
        for (int i = head[realId]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            if (fa != nullptr && fa->realId == v)
                continue;
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
        toNode[cutCnt] = x;
        a[cutCnt] = orgnV[x->realId];
        if (x->hvySon == nullptr)
            return;
        Dfs_2(x->hvySon, tp);

        int realId(x->realId);
        for (int i = realId; i; i = e[i].nxt)
        {
            int v = e[i].to;
            if (v != x->hvySon->realId && v != (x->fa != nullptr ? x->fa->realId : -1)) // 新的重链顶端
                Dfs_2(x, x);
        }
    }

    void Build()
    {
        rot = new Node();
        Dfs_1(rot, nullptr, 1, 1);
        debug(rot);
        Dfs_2(rot, rot);
        SgnTr.Build(SgnTr.rot, 1, n);
    }
    void UpdLne(int _x, int _y, int k)
    {
        Node *x = toNode[_x], *y = toNode[_y];
        Node *fx = x->lnkTp, *fy = y->lnkTp;
        while (fx != fy)
        {
            if (fx->dep >= fy->dep)
            {
                SgnTr.Upd(SgnTr.rot, fx->cutId, x->cutId, k);
                x = fx->fa;
                fx = x->lnkTp;
            }
            else
            {
                SgnTr.Upd(SgnTr.rot, fy->cutId, y->cutId, k);
                y = fy->fa;
                fy = y->lnkTp;
            }
        }
        if (x->cutId <= y->cutId)
            SgnTr.Upd(SgnTr.rot, x->cutId, y->cutId, k);
        else
            SgnTr.Upd(SgnTr.rot, y->cutId, x->cutId, k);
    }
    int QryLne(int _x, int _y)
    {
        int ans = 0;
        Node *x = toNode[_x], *y = toNode[_y];
        Node *fx = x->lnkTp, *fy = y->lnkTp;
        while (fx != fy)
        {
            // 一个重链一个重链地跳
            if (fx->dep >= fy->dep)
            {
                ans += SgnTr.Qry(SgnTr.rot, fx->cutId, x->cutId);
                x = fx->fa;
                fx = x->lnkTp;
            }
            else
            {
                ans += SgnTr.Qry(SgnTr.rot, fy->cutId, y->cutId);
                y = fy->fa;
                fy = y->lnkTp;
            }
        }
        if (x->cutId <= y->cutId)
            ans += SgnTr.Qry(SgnTr.rot, x->cutId, y->cutId);
        else
            ans += SgnTr.Qry(SgnTr.rot, x->cutId, y->cutId);
        return ans;
    }
    int QrySon(int _x)
    {
        Node *x = toNode[_x];
        return SgnTr.Qry(SgnTr.rot, x->cutId, x->cutId + x->siz - 1 /*子树的链的右端点*/);
    }
    void UpdSon(int _x, int k)
    {
        Node *x = toNode[_x];
        SgnTr.Upd(SgnTr.rot, x->cutId, x->cutId + x->siz - 1, k);
    }
}; // namespace CutTree
int main()
{
    n = read(), m = read(), r = read(), p = read();
    for (int i = 1; i <= n; i++)
        orgnV[i] = read();
    for (int i = 1, a, b; i < n; i++)
    {
        a = read(), b = read();
        add_edge(a, b);
        add_edge(b, a);
    }
    CutTree::Build();
    while (m--)
    {
        int op, x, y, z;
        op = read();
        if (op == 1)
        {
            x = read(), y = read(), z = read();
            CutTree::UpdLne(x, y, z);
        }
        else if (op == 2)
        {
            x = read(), y = read();
            printf("%d\n", CutTree::QryLne(x, y));
        }
        else if (op == 3)
        {
            x = read(), z = read();
            CutTree::UpdSon(x, z);
        }
        else if (op == 4)
        {
            x = read();
            printf("%d\n", CutTree::QrySon(x));
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
}