#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1 << 18;
const int inf = 1 << 30;
int n, W, a[maxn], sum[maxn], dp[maxn], bin[maxn], vol[maxn];
int main()
{
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        bin[1 << i] = i; //bin ä¸ºäº†å¿?é€ŸçŸ¥é�“ä¸€ä¸?å�•ä¸ªç‰©å“�çš„é›†å�ˆä¸­ ç‰©å“�çš„ç¼–å�?
    for (int i = 1; i < (1 << n); i++)
        sum[i] = a[bin[i & -i]] + sum[i ^ (i & -i)];

    for (int i = 1; i < (1 << n); i++)
        dp[i] = inf;
    for (int i = 0; i < (1 << n); i++)
        vol[i] = inf;
    /*for (int i = 1; i < (1 << n); i++)
    for (int j = i; j ; j = j - 1 & i)
    if (sum[j] <= W)
        dp[i] = min(dp[i], dp[i ^ j] + 1);*/

    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
            {
                //æ–°å?žä¸€ä¸?ç»?
                if (dp[i ^ (1 << j)] + 1 < dp[i])
                    dp[i] = dp[i ^ (1 << j)] + 1, vol[i] = a[j];
                else if (dp[i ^ (1 << j)] + 1 == dp[i] && a[j] < vol[i])
                    dp[i] = dp[i ^ (1 << j)] + 1, vol[i] = a[j];

                //åˆ©ç”¨åŽŸæœ‰çš„ç»„
                if (vol[i ^ (1 << j)] + a[j] <= W)
                {
                    if (dp[i ^ (1 << j)] < dp[i])
                        dp[i] = dp[i ^ (1 << j)], vol[i] = vol[i ^ (1 << j)] + a[j];
                    else if (dp[i ^ (1 << j)] == dp[i] && vol[i ^ (1 << j)] + a[j] < vol[i])
                        dp[i] = dp[i ^ (1 << j)], vol[i] = vol[i ^ (1 << j)] + a[j];
                }
            }
    }
    printf("%d", dp[(1 << n) - 1]);
}