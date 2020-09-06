#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const long long MOD = 19260817;
//输入时直接取模，避免使用高精度。
inline long long read() {
    long long s = 0;
    char ch = getchar();
    while ((ch<'0'||ch>'9')&&ch!=EOF) ch=getchar();
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        s%=MOD;
        ch = getchar();
    }
    return s;
}
//(a/b) mod m == a * b^(-1) mod m.
void exgcd(long long a, long long b, long long& x, long long& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    long long q = a / b, r = a % b;
    exgcd(b, r, y, x);
    y -= q * x;
}
//求逆元板子
long long inv(long long a) {
    long long x, y;
    exgcd(a, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}
long long a, b;
int main()
{
    a=read();
    b=read();
    long long s=inv(b);
    printf("%lld\n", 1ll*s*a%MOD);
    END_PROGRAM
}