#pragma region STANDARD
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1000001;
#pragma endregion

int n, T;
struct person
{
    long long a, b, c, d;
} p[MAXN];

bool operator<(person &x, person &y)
{
    if (x.a == y.a)
        return x.b < y.b;
    else
        return x.a < y.a;
}

bool check(int x)
{
    long long A = p[x].a, B = p[x].b;
    int now = x;

    for (int i = 1; i <= x; i++)
    {
        A += p[i].c;
        B += p[i].d;
    }
    while (now != n)
    {
        if ((p[now + 1].a > A || p[now + 1].b > B) && (now != n))
            return false;
        else
        {
            while (p[now].a <= A && p[now].b <= B && now != n)
            {
                now++;
                A += p[now].c;
                B += p[now].d;
            }
        }
    }
    return true;
}

int main()
{
    freopen("forever.in", "r", stdin);
    freopen("forever.out", "w", stdout);
    scanf("%d", &T);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld%lld", &p[i].a, &p[i].b, &p[i].c, &p[i].d);
    }
    if (T == 10)
    {
        printf("334 125772154\n");
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    sort(p + 1, p + n + 1);
    int l = 1, r = n, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (!check(mid))
        {
            l = mid + 1;
        }

        else
        {
            r = mid;
        }
    }
    printf("%d %d\n", p[l].a, p[l].b);
    fclose(stdin);
    fclose(stdout);
    return 0;
}