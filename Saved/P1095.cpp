#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 1000001;
int f[MAXN];
int m, s, t;
//贪心+dp
//一开始，dp一次，能用蓝就用，不行就回蓝
//再dp一次，假设上一秒守望者没有用蓝而是直接走路，
//看看是不是能更新dp值
//最后检验答案
int main()
{
    scanf("%d%d%d", &m, &s, &t);
    f[0] = 0;
    for (int i = 1; i <= t; i++)
    {
        if (m >= 10)
        {
            f[i] = f[i - 1] + 60;
            m -= 10;
        }
        else
        {
            f[i] = f[i - 1];
            m += 4;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        f[i] = max(f[i], f[i - 1] + 17);
        if (f[i] >= s)
        {
            printf("Yes\n%d\n", i);
            END_PROGRAM
        }
    }
    printf("No\n%d\n", f[t]);
    END_PROGRAM
}