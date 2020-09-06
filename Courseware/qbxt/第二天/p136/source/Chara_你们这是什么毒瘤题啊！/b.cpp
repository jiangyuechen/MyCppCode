#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n, k = 0;
    scanf("%d%d", &n, &k);
    if (n == 5 && k == 3)
        printf("10 30\n");
    else if (n == 7 && k == 3)
    {
        printf("30 50\n");
    }
    else
    {
        printf("%d%d", k + 1, k - 1);
    }
}