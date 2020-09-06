#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
struct Node
{
    Node *ls, *rs;
    int minimum;
    int l, r;
    int tag;
    inline void pushup()
    {
        minimum = MIN(ls->minimum, rs->minimum);
    }
    inline void maketag(const int K)
    {
        tag += K;
        minimum -= K;
    }
    inline void pushdown()
    {
        if (!tag)
            return;
        ls->maketag(tag);
        rs->maketag(tag);
        tag = 0;
    }
    inline bool InRange(const int L, const int R)
    {
        return (L <= l && r <= R);
    }
    inline bool OutRange(const int L, const int R)
    {
        return (l > R || r < L);
    }
    Node(const int L, const int R)
    {
        l = L;
        r = R;
        tag = 0;
        if (L == R)
        {
            minimum = a[l];
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
    inline void upd(const int L, const int R, const int K)
    {
        if (InRange(L, R))
        {
            maketag(K);
        }
        else if (!OutRange(L, R))
        {
            pushdown();
            ls->upd(L, R, K);
            rs->upd(L, R, K);
            pushup();
        }
    }
};
int n, m;
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    Node *rot = new Node(1, n);
    for (int i = 1, d, s, j; i <= m; i++)
    {
        d = read();
        s = read();
        j = read();
        rot->upd(s, j, d);
        if (rot->minimum < 0)
        {
            printf("-1\n%d", i);
            END_PROGRAM
        }
    }
    puts("0");
    END_PROGRAM
}