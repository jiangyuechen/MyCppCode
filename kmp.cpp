#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;

namespace KMP
{
    char s[MAXN] /*被匹配串*/, t[MAXN] /*匹配串（模式串）*/;
    int slen, tlen;
    int nxt[MAXN];
    void Setup()
    {
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        slen = strlen(s + 1);
        tlen = strlen(t + 1);
        memset(nxt, 0, sizeof(nxt));
        printf("Setup OK.\n");
    }
    /**
     * 如果 nxt[j-1] 已知，求 nxt[j] 的值。
     * 方法:
     * 1.设 nxt[j-1] = k, 那么判断是否有 t[k] == t[j].
     * -> 如果是，那么 nxt[j] = k + 1.
     * -> 如果不是，那么 设 nxt[k] = k' ，继续如此判断。
     * -> 直到 k = 0。此时 nxt[j] = 1.
    */
    void Prework()
    {
        nxt[1] = 0;
        for (int j = 2; j <= tlen; j++)
        {
            nxt[j] = 1; // 最坏情况下的默认值。
            int k = nxt[j - 1];
            while (k != 0)
            {
                if (t[k] == t[j])
                {
                    nxt[j] = k + 1;
                    // printf("broken.");
                    break;
                }
                else
                    k = nxt[k];
            }
        }
    }
    void Debug()
    {
        printf("s:%s\n", s);
        printf("t:%s\n", t);
        for (int i = 1; i <= tlen; i++)
            printf("%d ", nxt[i]);
    }
} // namespace KMP

int main()
{
    KMP::Setup();
    KMP::Prework();
    KMP::Debug();

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}