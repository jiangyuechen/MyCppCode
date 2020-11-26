/***********
 * @algorithm
 * 1.断环为链
 * 2.f[l][r][duan],g[l][r][duan] 分别表示将子区间 [l,r] 分为 duan 段，
 *  所能获得的最大值和最小值。
 * 3.枚举断点 k，则有状态转移方程:
 *      f[l][r][duan] = max{f[l][k][duan-1] * getRange(k+1,r) | l + duan - 2 <= k < r}
 *      g[l][r][duan] = min{g[l][k][duan-1] * getRange(k+1,r) | l + duan - 2 <= k < r}
 *  这表示，寻找一个比 [l,r] 小的区间 [l,k], 获取其分成 duan-1 段的最大值和最小值。
 *  那么 这个值新乘上[k+1,r]这新的一段,就转移为了 f,g[l][r][duan] 的值。
 *  所有的可能情况取 max,min 即可。
 * @attention
 * 1.注意枚举顺序。duan是阶段（因为f[l][r][duan]依赖f[l][r][duan-1]的值），所以放在最外侧循环。
 * 2.往内依次是 l,r,k(断点)。
*/
#define I return
#define AK 0
#define IOI ;

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
const int MAXN = 105, MAXM = 10;
using namespace std;
int a[MAXN];

int f[MAXN][MAXN][MAXM];
int g[MAXN][MAXN][MAXM];

int qzh[MAXN];
int n, m;
/**
 * @brief 前缀和，获得数列 a 的子区间 [l,r] 的和对 10 取模后的值。
 * @param l 区间左端点。
 * @param r 区间右端点。
 * @attention ( a % p + p ) % p 可以解决 a 为负数的情况。
*/
inline int getRange(int l, int r)
{
    return ((qzh[r] - qzh[l - 1]) % 10 + 10) % 10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        qzh[i] = qzh[i - 1] + a[i];
    }
    // 初始化，区间 [l,r] 分成 1 段（即不分段），其 f,g 值是区间和本身。
    for (int l = 1; l <= 2 * n; l++)
    {
        for (int r = l; r <= 2 * n; r++)
        {
            f[l][r][1] = g[l][r][1] = getRange(l, r);
        }
    }
    for (int duan = 2; duan <= m; duan++) // 赋初值，小的赋值无限大，大的赋值无限小。
    {
        for (int l = 1; l <= 2 * n; l++)
        {
            for (int r = l + duan - 1; r <= 2 * n; r++)
            {
                g[l][r][duan] = 0x3f3f3f3f;
                f[l][r][duan] = -0x3f3f3f3f;
            }
        }
    }
    for (int duan = 2; duan <= m; duan++) // 阶段：分成的段落数
    {
        for (int l = 1; l <= 2 * n; l++) // 状态 1 : 左端点 （因为 f[l][r] 是由 f[l][k] 决定的，所以先固定左端点。
        {
            for (int r = l + duan - 1; r <= 2 * n; r++) // 状态 2 : 右端点
            {
                for (int k = l + duan - 2; k < r; k++) // 决策 : 断点
                {
                    f[l][r][duan] = max(f[l][r][duan], f[l][k][duan - 1] * getRange(k + 1, r));
                    g[l][r][duan] = min(g[l][r][duan], g[l][k][duan - 1] * getRange(k + 1, r));
                }
            }
        }
    }
    int ansmax = -0x3f3f3f3f, ansmin = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) // 获取每一个可能区间的最大最小值。
    {
        ansmax = max(ansmax, f[i][i + n - 1][m]);
        ansmin = min(ansmin, g[i][i + n - 1][m]);
    }
    cout << ansmin << endl
         << ansmax << endl;
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    I AK IOI
}