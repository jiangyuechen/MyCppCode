#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;

namespace KMP
{
    string T, S;
    int m, n;
    int Nxt[MAXN], Mch[MAXN];
    void _Work()
    {
        m = T.length();
        n = T.length();
        memset(Nxt, -1, sizeof(Nxt));
        Nxt[0] = Nxt[1] = 0;
        for (int i = 2, j = 0; i <= m; i++)
        { //构建 Next
            while (j && T[j + 1] != T[i])
                j = Nxt[j];
            if (T[j + 1] == T[i])
                ++j;
            Nxt[i] = j;
        }
        for (int i = 1, j = 0; i <= n; i++)
        { //匹配
            while (j && T[j + 1] != S[i])
                j = Nxt[j];
            if (T[j + 1] == S[i])
                ++j;
            if (j == m)
                Mch[i] = 1, j = Nxt[j]; //匹配成功
        }
    }
} // namespace KMP

int main()
{
    cin >> KMP::S >> KMP::T;
    KMP::_Work();
    for (int i = 0; i <= std::max(KMP::m, KMP::n); i++)
    {
        cout << KMP::Mch[i];
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}