#include <bits/stdc++.h>
using namespace std;
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
const int MAXN = 100001;
int C0;      // C0 : 成本
int V0;      // V0 : 成本时的销售量
int W[MAXN]; // W[i] : 价位为 i 时的销售量
int Cexp;    //Cexp : 政府的预期价格

int main()
{
    Cexp = read();
    C0 = read();
    V0 = read();
    int tx, ty;
    tx = read();
    ty = read();
    while (!(tx == -1 && ty == -1))
    {
        W[tx] = ty;
        tx = read();
        ty = read();
    }
}