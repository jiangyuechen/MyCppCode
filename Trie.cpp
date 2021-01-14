#include <bits/stdc++.h>
using namespace std;

class Trie
{
private:
    struct Node
    {
        char ch;
        Node *son, *bro;
        Node() : ch(' '), son(nullptr), bro(nullptr) {}
        Node(char _ch) : ch(_ch), son(nullptr), bro(nullptr) {}
    };

public:
    Node *rot;
    Trie() { rot = new Node(); }
    void Insert(char str[], bool dbg_msg = false)
    {
        Node *now = rot;
        int len = strlen(str + 1);
        for (int i = 1; i <= len; i++)
        {
            char ch = str[i];
            if (now->son == nullptr)
            {
                now->son = new Node(ch);
                now = now->son;
            }
            else
            {
                Node *gs = now->son;
                while (gs->bro != nullptr && gs->ch != ch)
                    gs = gs->bro;
                if (gs->ch != ch) // 儿子们没有一样的
                {
                    gs->bro = new Node(ch);
                    gs = gs->bro;
                }
                now = gs;
            }
        }
        if (dbg_msg)
            printf("Insert %s ok.\n", str + 1);
    }
    void Show_Structure(Node *x, int floor = 1)
    {
        while (x != nullptr)
        {
            printf("|--%c\n", x->ch);
            if (x->son != nullptr)
                Show_Structure(x->son, floor + 1);
            x = x->bro;
        }
    }
};

int main()
{
    freopen("Trie.in", "r", stdin);
    freopen("Trie.out", "w", stdout);
    int n;
    Trie tr;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char s[101];
        scanf("%s", s + 1);
        tr.Insert(s, true);
    }
    tr.Show_Structure(tr.rot);
    return 0;
}