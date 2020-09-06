#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
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
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 100005;
struct traveller
{
    int t;
    int nat;
    traveller() : t(0), nat(0) {}
    traveller(int _t, int _nat) : t(_t), nat(_nat) {}
};
queue<traveller> q;
int arrive[MAXN];
int n, ans;
int main()
{
    n = read();
    for (int i = 1, t, k; i <= n; i++)
    {
        t = read();
        k = read();
        for (int i = 1; i <= k; i++)
        {
            int nat = read();
            q.push(traveller(t, nat));
            if (!arrive[nat])
                ans++;
            arrive[nat]++;
        }
        while (q.size() && t - q.front().t >= 86400)
        {
            traveller lost = q.front();
            q.pop();
            arrive[lost.nat]--;
            if (!arrive[lost.nat])
                ans--;
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}