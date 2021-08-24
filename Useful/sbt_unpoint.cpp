#include <cstdio>
#include <iostream>
using namespace std;
#define _WRITABLE
#define _READONLY
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
const int MAXN = 100001;
int n;
namespace SBT {
    int key[MAXN], siz[MAXN], ls[MAXN], rs[MAXN];
    int rot, top;
    void Rgt_Rotate(int &x) _WRITABLE {
        int k = ls[x];
        ls[x] = rs[k];
        rs[k] = x;
        siz[k] = siz[x];
        siz[x] = siz[ls[x]] + siz[rs[x]] + 1;
        x = k;
    }
    void Lft_Rotate(int &x) _WRITABLE {
        int k = rs[x];
        rs[x] = ls[k];
        ls[k] = x;
        siz[k] = siz[x];
        siz[x] = siz[ls[x]] + siz[rs[x]] + 1;
        x = k;
    }
    void Maintain(int &x, bool flag) _WRITABLE {
        if (!flag) {
            if (siz[ls[ls[x]]] > siz[rs[x]])
                Rgt_Rotate(x);
            else if (siz[rs[ls[x]]] > siz[rs[x]]) {
                Lft_Rotate(ls[x]);
                Rgt_Rotate(x);
            } else
                return;
        } else {
            if (siz[rs[rs[x]]] > siz[ls[x]])
                Lft_Rotate(x);
            else if (siz[ls[rs[x]]] > siz[ls[x]]) {
                Rgt_Rotate(rs[x]);
                Lft_Rotate(x);
            } else
                return;
        }
        Maintain(ls[x], false);
        Maintain(rs[x], true);
        Maintain(x, false);
        Maintain(x, true);
    }
    int New(int v) _WRITABLE {
        ++top;
        siz[top] = 1;
        key[top] = v;
        return top;
    }
    void __Insert(int &x, int val) _WRITABLE {
        if (x == 0)
            x = New(val);
        else {
            siz[x]++;
            if (val < key[x])
                __Insert(ls[x], val);
            else
                __Insert(rs[x], val);
            Maintain(x, val >= key[x]);
        }
    }
    void Insert(int val) _WRITABLE { __Insert(rot, val); }
    int __Delete(int &x, int val) _WRITABLE {
        siz[x]--;
        if (val == key[x] || (val < key[x] && ls[x] == 0) ||
            (val > key[x] && rs[x] == 0)) {
            int del = key[x];
            if (ls[x] == 0 || rs[x] == 0) x = ls[x] + rs[x];
            // This equals to:
            // @ if (ls[x] == 0) x = rs;
            // @ else if (rs[x] == 0) x = ls;
            // which mains that if a node have only one son, get that son.
            else
                key[x] = __Delete(ls[x], key[x] + 1);
            return del;
        } else {
            if (val < key[x])
                return __Delete(ls[x], val);
            else
                return __Delete(rs[x], val);
        }
    }
    void Delete(int val) _WRITABLE { __Delete(rot, val); }
    int __Rank(int &x, int val) _READONLY  // 查询数 val 的排名
    {
        if (x == 0) return 1;
        if (val <= key[x])
            return __Rank(ls[x], val);
        else
            return siz[ls[x]] + 1 + __Rank(rs[x], val);
    }
    int Rank(int val) _READONLY { return __Rank(rot, val); }
    int __Select(int &x, int rnk) _READONLY  // 查询排名为 rnk 的数
    {
        if (rnk == siz[ls[x]] + 1) return key[x];
        if (rnk <= siz[ls[x]])
            return __Select(ls[x], rnk);
        else
            return __Select(rs[x], rnk - 1 - siz[ls[x]]);
    }
    int Select(int rnk) _READONLY { return __Select(rot, rnk); }
    int __Lo_Bound(int &x, int val) _READONLY {
        if (x == 0) return val;
        if (val <= key[x])
            return __Lo_Bound(ls[x], val);
        else {
            int ret = __Lo_Bound(rs[x], val);
            if (ret == val) ret = key[x];
            return ret;
        }
    }

    int __Hi_Bound(int &x, int val) _READONLY {
        if (x == 0) return val;
        if (val >= key[x])
            return __Hi_Bound(rs[x], val);
        else {
            int ret = __Hi_Bound(ls[x], val);
            if (ret == val) ret = key[x];
            return ret;
        }
    }
    int Lo_Bound(int val) _READONLY { return __Lo_Bound(rot, val); }
    int Hi_Bound(int val) _READONLY { return __Hi_Bound(rot, val); }
}  // namespace SBT
int main() {
    n = read();
    while (n--) {
        int opt, x;
        opt = read();
        x = read();
        switch (opt) {
            case 1:
                SBT::Insert(x);
                break;
            case 2:
                SBT::Delete(x);
                break;
            case 3:
                printf("%d\n", SBT::Rank(x));
                break;
            case 4:
                printf("%d\n", SBT::Select(x));
                break;
            case 5:
                printf("%d\n", SBT::Lo_Bound(x));
                break;
            case 6:
                printf("%d\n", SBT::Hi_Bound(x));
                break;
            default:
                break;
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
}
