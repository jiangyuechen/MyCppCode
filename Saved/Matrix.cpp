#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000;
template <int N>
struct Matrix
{
    ll a[N][N];
    void reset(bool isUnit = false)
    {
        memset(a, 0, sizeof(a));
        if (isUnit)
        {
            for (int i = 0; i < N; i++)
            {
                a[i][i] = 1;
            }
        }
    }
    Matrix(bool isUnit = false)
    {
        reset(isUnit);
    }
    Matrix(ll v[N][N])
    {
        reset();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = v[i][j];
    }
    void output()
    {
        for (int i = 0; i < N; i++)
        {
            cout << "|";
            for (int j = 0; j < N; j++)
            {
                cout << a[i][j];
                if (j != N - 1)
                    cout << " ";
            }
            cout << "|\n";
        }
    }
    ll *operator[](int s)
    {
        return this->a[s];
    }
    Matrix<N> operator*(Matrix<N> y)
    {
        Matrix<N> x = *this;
        Matrix<N> ans{};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    ans[i][j] = (ans[i][j] + x[i][k] * y[k][j]) % mod;
        return ans;
    }
    Matrix<N> operator^(ll b) // this ^ s
    {
        Matrix<N> ans = Matrix<N>(/*default-arg*/ true);
        Matrix<N> base = *this;
        while (b)
        {
            if (b & 1ll)
            {
                ans = ans * base;
            }
            base = base * base;
            b >>= 1ll;
        }
        return ans;
    }
};
using Mat = Matrix<2>;
namespace BASE
{
    ll a[2][2] = {{1, 1}, {0, 0}};
    ll b[2][2] = {{1, 1}, {1, 0}};
} // namespace BASE
int main()
{
    Mat A(BASE::a);
    Mat B(BASE::b);
    Mat Ans = A * (B ^ 1ll);
    Ans.output();
    system("pause");
    return 0;
}