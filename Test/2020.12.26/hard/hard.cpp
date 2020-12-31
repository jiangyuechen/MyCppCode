#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
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

multiset<int> m;
int n, lastans = 0;
using iter = multiset<int>::iterator;
int tag;

int main()
{
    freopen("hard.in", "r", stdin);
    freopen("hard.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int opt = read();
        opt ^= lastans;
        // printf("opt:%d\n", opt);
        if (opt == 1)
        {
            int x = read();
            m.insert(x);
        }
        else if (opt == 2)
        {
            int x = read();
            x += tag;
            iter s = m.find(x);
            if (s != m.end())
                m.erase(s);
        }
        else if (opt == 3)
        {
            if (m.empty())
            {
                printf("zay\n");
            }
            else
            {
                int ans = *(--m.end());
                printf("%d\n", ans);
                lastans = ans;
            }
        }
        else if (opt == 4)
        {
            if (m.empty())
            {
                printf("zay\n");
            }
            else
            {
                int ans = *m.begin();
                printf("%d\n", ans);
                lastans = ans;
            }
        }
        // 4 6 8
        //
        else if (opt == 5)
        {
            int x = read();
            iter ans = m.lower_bound(x);
            if ((ans == m.end()) || (ans == m.begin() && *ans == x))
            {
                printf("cuc\n");
            }
            else if (*ans == x)
            {
                printf("%d\n", lastans = *(--ans));
            }
            else
            {
                printf("%d\n", lastans = *ans);
            }
        }
        else if (opt == 6)
        {
            int x = read();
            iter ans = m.lower_bound(x);
            if ((ans == m.end()) || (ans == --m.end() && *ans == x))
            {
                printf("cyc\n");
            }
            else if (*ans == x)
            {
                printf("%d\n", lastans = *(++ans));
            }
            else
            {
                printf("%d\n", lastans = *ans);
            }
        }
        else if (opt == 7)
        {
            int x = read();
            multiset<int> temp;
            for (iter i = m.begin(); i != m.end(); i++)
            {
                temp.insert(*i + x);
            }
            swap(m, temp);
        }
        // else
        // printf("JYCNB\n");
    }
    // system("pause");
}