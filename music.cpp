#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;

using namespace std;
constexpr int MAXN = 100001;
template <typename T>
inline void _read(T &x)
{
    char ch = getchar();
    bool sign = true;
    while (!isdigit(ch))
    {
        if (ch == '-')
            sign = false;
        ch = getchar();
    }
    for (x = 0; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    if (!sign)
        x = -x;
}

int T, n, x, y;
int a[100005];
void rev(int l, int r)
{ //a[l]..a[r]
    int i, lim = (l + r) / 2;
    for (i = l; i <= lim; i++)
        swap(a[i], a[r + l - i]);
}
const char *FileIn(int i)
{
    string f = "C:/Users/J_Ignite/Desktop/Code/Test/T1/Input/data_";
    f += (char)i + '0';
    f += ".in";
    return f.c_str();
}

const char *FileOut(int i)
{
    string f = "C:/Users/J_Ignite/Desktop/Code/Test/T1/Output/data_";
    f += (char)i + '0';
    f += ".out";
    return f.c_str();
}
void RealMain()
{
    memset(a, 0, sizeof(a));
    T = n = x = y = 0;
    int i, j, k;
    scanf("%d%d%d", &n, &x, &y);
    if (1ll * x * y < n || x + y > n + 1)
    {
        puts("NO");
        return;
    }
    for (i = 1; i <= n; i++)
        a[i] = i;
    rev(n - y + 1, n);
    int temp = n - y + 1 - x, pos = n - y;
    while (temp)
    {
        if (temp < y)
        {
            rev(pos - temp, pos);
            break;
        }
        else
        {
            rev(pos - y + 1, pos);
            temp -= (y - 1);
            pos -= y;
        }
    }
    puts("YES");
    for (i = 1; i <= n; i++)
    {
        if (i < n)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
}
int main()
{
    //freopen(FileIn(p), "r", stdin);
    //freopen(FileOut(p), "w", stdout);
    RealMain();

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}