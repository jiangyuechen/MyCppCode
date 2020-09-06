#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 10001;
#define LOWBIT(x) ((x) & -(x))
int a[MAXN], c[MAXN], n;
void upd_range(int x, int d)
{
    for (int i = x; i; i -= LOWBIT(i))
    {
        c[i] += d;
    }
}
void upd_single(int x, int k) //change a[x] to k
{
    upd_range(x, k);
    upd_range(x - 1, -k);
}
int qry_range(int x) //return sum of [1,x]
{
    if (!x)
        return 0;
    int ret = 0;
    for (int i = x; i; i -= LOWBIT(i))
    {
        ret += c[i];
    }
    return ret;
}
int qry_single(int x) //return a[x]
{
    if (!x)
        return 0;
    int ret = 0;
    for (int i = x; i <= n; i += LOWBIT(i))
    {
        ret += c[i];
    }
    return a[x] + ret;
}
int main()
{

    END_PROGRAM
}