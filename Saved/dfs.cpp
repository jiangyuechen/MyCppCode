#include <bits/stdc++.h>
using namespace std;
namespace Splay
{
    struct Node;
    static Node *rot;
    static int tot;
    struct Node
    {
        Node *son[2], *fa;
        int size, val, same_cnt;
        Node(Node *_fa, int _val) : val(_val), fa(_fa), size(1), same_cnt(1)
        {
            tot++;
        }
        /**
         * 设置儿子。
         * @param s 要设置的儿子。
         * @param o 是 0 则为左儿子，是 1 则为右儿子。
        */
        void Set_son(Node *s, int o)
        {
            this->son[o] = s;
            s->fa = this;
        }
        /**
         * 获得这个点是他爸的第几个儿子。
         * @return 0:左儿子 1:右儿子
        */
        bool Get_which()
        {
            return fa->son[1] == this;
        }
        /**
         * 更新操作。
         * 更新结点的大小。
        */
        void Update()
        {
            this->size = son[0]->size + son[1]->size;
        }
        /**
         * 旋转操作。
         * 1.X 变到 原来Y的位置
         * 2.Y 变成了 X原来在Y的 相对的 那个儿子
         * 3.Y的 非X的儿子 不变 X的 X原来在Y的 那个儿子不变
         * 4.X的 X原来在Y的 相对的 那个儿子 变成了 Y原来是X的那个儿子
        */
        void Rotate()
        {
            Node *x = this;
            Node *y = x->fa;
            if (y == nullptr)
                return;
            Node *z = y->fa;
            if (z == nullptr)
                return;
            int k = (y->son[1] == x), l = (z->son[1] == y);
            z->Set_son(x, l);
            y->Set_son(x->son[k ^ 1], k);
            x->Set_son(y, k ^ 1);

            y->Update();
            x->Update();
        }
        void Splay()
        {
            for (Node *f = this->fa; f != nullptr; this->Rotate())
            {
                if (this->Get_which() == f->Get_which())
                    f->Rotate();
                else
                    this->Rotate();
            }
            rot = this;
        }
        void Insert(int x)
        {
            Node *fa = nullptr, *u = rot;
            while (u != nullptr && x != u->val)
            {
                fa = u;
                u = x > u->val ? u->son[1] : u->son[0];
            }
            if (u != nullptr)
                same_cnt++;
            else
            {
            }
        }
    };
}; // namespace Splay
int main()
{
}
