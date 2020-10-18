#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 10001;

int n;
struct stick
{
    int l, w;
};
stick a[MAXN];
bool cmp1(stick &x, stick &y)
{
    if (x.l == y.l)
        return x.w > y.w;
    return x.l > y.l;
}
bool cmp2(stick &x, stick &y)
{
    if (x.w == y.w)
    {
        return x.l > y.l;
    }
    return x.w > y.w;
}
int ans1 = 1, ans2 = 1;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].l, &a[i].w);
    }
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i++)
    {
        printf("%d:%d,%d\n", i, a[i].l, a[i].w);
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i].l < a[i + 1].l || a[i].w < a[i + 1].w)
            ans1++;
    }
    sort(a + 1, a + n + 1, cmp2);
    for (int i = 1; i <= n; i++)
    {
        printf("%d:%d,%d\n", i, a[i].l, a[i].w);
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i].l < a[i + 1].l || a[i].w < a[i + 1].w)
            ans2++;
    }

    printf("%d\n", (ans1 < ans2) ? ans1 : ans2);
    END_PROGRAM
}