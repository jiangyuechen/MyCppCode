#include <bits/stdc++.h>
constexpr int MAXN = 1000001;
int a[MAXN], n;

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    std::sort(a + 1, a + n + 1, [](int a, int b) { return a > b; });
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    system("pause");
    return 0;
}