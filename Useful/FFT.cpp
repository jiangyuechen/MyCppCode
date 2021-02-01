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

struct cp
{
    double real, imag;
    cp() : real(0), imag(0) {}
    cp(double _r, double _i) : real(_r), imag(_i) {}
    cp operator+(cp o) { return cp(this->real + o.real, this->imag + o.imag); }
    cp operator-(cp o) { return cp(this->real - o.real, this->imag - o.imag); }
    cp operator*(cp o) { return cp(this->real * o.real - this->imag * o.imag, this->real * o.imag + this->imag * o.real); }
};
const int MAXN = 10000001;
const double Pi = acos(-1.00);
cp A[MAXN], B[MAXN];
int rev[MAXN], N, M, lim = 1, limpow;
/*
[][][][][][][][] [][][][][][][][]
       ^mid
               ^R
^j-------------->^j'
^j+k   |^j+k+mid
(l)    |(r)
*/
void FFT(cp *a, int inv)
{
    for (int i = 0; i < lim; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int mid = 1; mid < lim; mid = mid << 1) // 区间中点
    {
        cp id = cp(cos(Pi / mid), inv * sin(Pi / mid)); // 单位元
        int rgt = mid << 1;                             // 区间右端点
        for (int i = 0; i < lim; i += rgt)
        {
            cp w = cp(1, 0);
            for (int k = 0; k < mid; k++, w = w * id)
            {
                int l = i + k, r = i + mid + k; // 枚举左右边的虚数做运算
                cp x = a[l], y = w * a[r];
                a[l] = x + y;
                a[r] = x - y;
            }
        }
    }
}
int main()
{
    N = read();
    M = read();
    for (int i = 0; i <= N; i++)
        A[i].real = read();
    for (int i = 0; i <= M; i++)
        B[i].real = read();
    while (lim <= N + M)
        lim <<= 1, limpow++;
    for (int i = 0; i < lim; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (limpow - 1));
    FFT(A, 1);
    FFT(B, 1);
    for (int i = 0; i <= lim; i++)
        A[i] = A[i] * B[i];
    FFT(A, -1);
    for (int i = 0; i <= N + M; i++)
        printf("%d ", int(A[i].real / lim + 0.5));
#ifndef ONLINE_JUDGE
    system("pause");
#endif
}