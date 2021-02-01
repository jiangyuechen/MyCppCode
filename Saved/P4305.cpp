#include <bits/stdc++.h>
const int MAXN = 50004;
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
int T, n;
int main()
{
    T = read();
    while (T--)
    {
        n = read();
        std::set<int> s;
        while (n--)
        {
            int x = read();
            if (s.find(x) == s.end())
            {
                printf("%d ", x);
                s.insert(x);
            }
        }
        puts("");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}