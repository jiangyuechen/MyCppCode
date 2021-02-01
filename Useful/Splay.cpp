#include <bits/stdc++.h>
#define ll long long
const int MAXN = 100005;
using namespace std;

namespace Splay
{
    struct Node;
    static int tot;
    static Node *rot;
    struct Node
    {
        Node *son[2], *fa;
        int size, val, same_cnt;
        /**
         * 默认构造函数。
         * 所有数据为 0 或空指针。
        */
        Node() : val(0), son({nullptr, nullptr}), fa(nullptr), size(0), same_cnt(0) { tot++; }
        /**
         * 构造函数。
         * @param _fa 父亲指针。
         * @param _val 结点值。
         * size = same_cnt = son = 0 / nullptr.
        */
        Node(Node *_fa, int _val) : val(_val), fa(_fa), son({nullptr, nullptr}), size(1), same_cnt(1) { tot++; }
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
            for (Node *f = nullptr; (f = this->fa) != nullptr; this->Rotate())
                if (f->fa != nullptr)
                    (f->Get_which() == this->Get_which() ? f : this)->Rotate();
            rot = this;
        }
        static void Insert(int x)
        {
            if (rot == nullptr)
            {
                rot = new Node(nullptr, x);
                return;
            }
            Node *now = rot, *fa = nullptr;
            while (true)
            {
                if (x == now->val)
                {
                    now->same_cnt++;
                    now->Splay();
                    return;
                }
                fa = now;
                now = now->son[int(x > now->val)];
                if (now == nullptr)
                {
                    fa->son[int(x > fa->val)] = now = new Node(fa, x);
                    now->Splay();
                    return;
                }
            }
        }
        static int Kth(int k)
        {
            Node *now = rot;
            while (true)
            {
                if (now->son[0] != nullptr && k <= now->son[0]->size)
                    now = now->son[0];
                else
                {
                    int lsz = now->son[0]->size + now->same_cnt;
                    if (k <= lsz)
                        return now->val;
                    k -= lsz;
                    now = now->son[1];
                }
            }
        }
        static int Rank(int x)
        {
            Node *now = rot;
            int ans = 0;
            while (1)
            {
                if (now->son[0] != nullptr && x < now->val)
                    now = now->son[0];
                else
                {
                    ans += now->son[0]->size;
                    if (x == now->val)
                    {
                        now->Splay();
                        return ans;
                    }
                    ans += now->same_cnt;
                    now = now->son[1];
                }
            }
        }
        static Node *pre()
        {
            Node *now = rot->son[0];
            while (now->son[1] != nullptr)
                now = now->son[1];
            return now;
        }
        void Delete(int x)
        {
            Rank(x);
            if (rot->same_cnt > 1)
            {
                rot->same_cnt--;
                rot->Update();
                return;
            }
            Node *l = pre(), *old = rot;
            l->Splay();
            l->son[1] = old->son[1];
            l->son[1]->fa = l;
            delete old;
            rot->Update();
        }
    };
}; // namespace Splay
int main()
{

    return 0;
}
