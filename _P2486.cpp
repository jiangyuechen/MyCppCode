#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int a[MAXN], n, q;

struct Node
{
    Node *ls, *rs;
    int l, r, cnt, lcolor, rcolor, tag;
    void PsUp()
    {
        cnt = ls->cnt + rs->cnt;
        if (ls->rcolor == rs->lcolor)
            cnt--;
        lcolor = ls->lcolor;
        rcolor = rs->rcolor;
    }
    void MakeTag(int C)
    {
        cnt = 1;
        lcolor = rcolor = C;
        tag = C;
    }
    void Debug()
    {
        printf("[%d,%d]: cnt=%d lcolor=%d rcolor=%d tag=%d\n", l, r, cnt, lcolor, rcolor, tag);
        if (ls)
            ls->Debug();
        if (rs)
            rs->Debug();
    }
    void PsDw()
    {
        if (tag)
        {
            if (ls)
                ls->MakeTag(tag);
            if (rs)
                rs->MakeTag(tag);
            tag = 0;
        }
    }
    bool inrange(int L, int R) { return L <= l && r <= R; }
    // bool outrange(int L, int R) { return R < l || r < L; }

    Node(int L, int R)
    {
        l = L;
        r = R;
        tag = 0;
        if (L == R)
        {
            ls = rs = nullptr;
            cnt = 1;
            lcolor = rcolor = a[L];
        }
        else
        {
            int M = (L + R) >> 1;
            ls = new Node(L, M);
            rs = new Node(M + 1, R);
            PsUp();
        }
    }
    void Upd(int L, int R, int C)
    {
        printf("[%d,%d] changed.\n", l, r);
        if (inrange(L, R))
        {
            MakeTag(C);
            return;
        }
        PsDw();
        int M = (l + r) >> 1;
        if (L <= M)
            ls->Upd(L, R, C);
        if (R > M)
            rs->Upd(L, R, C);
        PsUp();
    }
    int Qry(int L, int R)
    {
        if (inrange(L, R))
            return cnt;
        PsDw();
        int M = (l + r) >> 1;
        if (R <= M)
            return ls->Qry(L, R);
        if (L > M)
            return rs->Qry(L, R);
        int ans = ls->Qry(L, R) + rs->Qry(L, R);
        if (ls->rcolor == rs->lcolor)
            ans--;
        return ans;
    }
};
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Node *rot = new Node(1, n);
    while (q--)
    {
        char op;
        int x, y, z;
        cin >> op;
        if (op == 'C')
        {
            cin >> x >> y >> z;
            rot->Upd(x, y, z);
        }
        else
        {
            cin >> x >> y;
            rot->Debug();
            printf("%d\n", rot->Qry(x, y));
        }
    }
    system("pause");
}