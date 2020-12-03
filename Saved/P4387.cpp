#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;

int q, n, pushed[MAXN], poped[MAXN];
stack<int> stk;
int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        int nxt = 1;
        memset(pushed, 0, sizeof(pushed));
        memset(poped, 0, sizeof(poped));
        while (!stk.empty())
            stk.pop();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", pushed + i);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", poped + i);
        }
        for (int i = 1; i <= n; i++)
        {
            stk.push(pushed[i]);
            while (stk.top() == poped[nxt])
            {
                stk.pop();
                nxt++;
                if (stk.empty())
                    break;
            }
        }
        printf(stk.empty() ? "Yes\n" : "No\n");
    }
}