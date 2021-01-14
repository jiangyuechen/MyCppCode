#include <bits/stdc++.h>
using namespace std;
const int OK = 0, WRONG = 1, REPEAT = 2;
const int CHARSET_SIZE = 26;
#define TONUM(ch) ((ch) - 'a')
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
    void Insert(char str[])
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
    }
};
class _Trie
{
private:
    struct Node
    {
        bool vis;
        Node *son[CHARSET_SIZE];
        Node() : vis(false), son({nullptr}) {}
    };

public:
    Node *rot;
    _Trie() { rot = new Node(); }
    void Insert(char str[])
    {
        Node *now = rot;
        int len = strlen(str + 1);
        for (int i = 1; i <= len; i++)
        {
            int ch = TONUM(str[i]);
            if (now->son[ch] == nullptr)
                now->son[ch] = new Node();
            now = now->son[ch];
        }
    }
    int Find(char str[])
    {
        Node *now = rot;
        int len = strlen(str + 1);
        for (int i = 1; i <= len; i++)
        {
            int ch = TONUM(str[i]);
            if (now->son[ch] == nullptr)
                return WRONG;
            now = now->son[ch];
        }
        if (now->vis == false)
        {
            now->vis = true;
            return OK;
        }
        else
            return REPEAT;
    }
};
int n, m;
int main()
{
    _Trie Tr;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char str[55];
        scanf("%s", str + 1);
        Tr.Insert(str);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        char str[55];
        scanf("%s", str + 1);
        int res = Tr.Find(str + 1);
        switch (res)
        {
        case OK:
            printf("OK\n");
            break;
        case REPEAT:
            printf("REPEAT\n");
            break;
        case WRONG:
            printf("WRONG\n");
            break;
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}