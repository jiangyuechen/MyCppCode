#include <bits/stdc++.h>
using namespace std;

struct Num
{
    int val, ord;
    Num() : val(0), ord(0) {}
    Num(int v, int o) : val(v), ord(o) {}
};
deque<Num> Min;
vector<int> ans;
int n, m;
void upd(Num n)
{
    while (!Min.empty() && Min.back().val >= n.val)
    {
        Min.pop_back();
    }
    Min.push_back(n);
    while (!Min.empty() && Min.front().ord < n.ord - m + 1)
    {
        Min.pop_front();
    }
    ans.push_back(Min.front().val);
}
Num a[2000005];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].val);
        a[i].ord = i - 1;
    }
    ans.push_back(0);
    for (int i = 1; i < n; i++)
    {
        upd(a[i]);
    }
    for (auto i : ans)
    {
        printf("%d\n", i);
    }
    system("pause");
    return 0;
}