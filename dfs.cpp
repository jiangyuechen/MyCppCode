#include <bits/stdc++.h>
using namespace std;

struct Splay
{
    struct Node
    {
        Node *ls, *rs, *fa;
    };
    /**
     * 旋转操作。
     * 1.X 变到原来Y的位置
     * 2.Y 变成了 X 原来在 Y 的 相对的那个儿子
     * 3.Y的非X的儿子不变 X的 X原来在Y的 那个儿子不变
     * 4.X的 X原来在Y的 相对的 那个儿子 变成了 Y原来是X的那个儿子
    */
    void Rotate(Node *x)
    {
        Node *y = x->fa;
        Node *z = y->fa;
        Node *k = y->rs == x ? y->ls : y->rs;
        Node *revk = y->rs == x ? x->rs : x->ls;

        (z->rs == y ? z->rs : z->ls) = x;
        x->fa = z;

        k = revk;
        revk->fa = y;

        revk = y;
        y->fa = x;
    }
};
int main()
{
}