#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

typedef unsigned long long ll;

ll n, q, mod = 1000001;
ll a[maxn];
inline ll read()
{
    ll s = 0ll;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
    {
        last = ch;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10ll + ch - '0';
        ch = getchar();
    }
    return s;
}

// struct Node
// {
//     ll tag_times, tag_plus, v;
//     ll l, r;
//     Node *ls, *rs;

//     inline void pushup()
//     {
//         v = (ls->v + rs->v) % mod;
//     }
//     inline ll len() { return r - l + 1; }
//     inline void pushdown()
//     {

//         ls->v = (ls->v * tag_times + tag_plus * ls->len()) % mod;
//         rs->v = (rs->v * tag_times + tag_plus * rs->len()) % mod;

//         ls->tag_times = (ls->tag_times * tag_times) % mod;
//         rs->tag_times = (rs->tag_times * tag_times) % mod;

//         ls->tag_plus = (ls->tag_plus * tag_times + tag_plus) % mod;
//         rs->tag_plus = (rs->tag_plus * tag_times + tag_plus) % mod;

//         tag_plus = 0;
//         tag_times = 1;
//     }
//     inline void maketag_plus(ll k)
//     {
//         tag_plus = (tag_plus + k) % mod;
//         v = (v + k * (r - l + 1)) % mod;
//     }
//     inline void maketag_times(ll k)
//     {
//         v = v * k % mod;
//         tag_times = (tag_times * k) % mod;
//         tag_plus = (tag_plus * k) % mod;
//     }
//     Node(const ll L, const ll R)
//     {
//         l = L;
//         r = R;
//         tag_plus = 0;
//         tag_times = 1;
//         if (l == r)
//         {
//             v = a[l] % mod;
//             ls = rs = NULL;
//         }
//         else
//         {
//             ll M = (L + R) >> 1;
//             ls = new Node(L, M);
//             rs = new Node(M + 1, R);
//             pushup();
//         }
//     }

//     this l, r
//     inline bool InRange(const ll L, const ll R)
//     {
//         return (L <= l) && (r <= R);
//     }
//     inline bool OutofRange(const ll L, const ll R)
//     {
//         return (l > R) || (r < L);
//     }

//     void add(ll L, ll R, ll k)
//     {
//         if (OutofRange(L, R))
//             return;
//         else if (InRange(L, R))
//         {
//             maketag_plus(k);
//             return;
//         }
//         pushdown();
//         ls->add(L, R, k);
//         rs->add(L, R, k);
//         pushup();
//     }
//     void mul(ll L, ll R, ll k)
//     {
//         if (OutofRange(L, R))
//             return;
//         else if (InRange(L, R))
//         {
//             maketag_times(k);
//         }
//         else
//         {
//             pushdown();
//             ls->mul(L, R, k);
//             rs->mul(L, R, k);
//             pushup();
//         }
//     }
//     ll qry(const ll L, const ll R)
//     {
//         if (InRange(L, R))
//             return v;
//         if (OutofRange(L, R))
//             return 0;
//         pushdown();
//         return (ls->qry(L, R) + rs->qry(L, R)) % mod;
//     }
// };

// int main()
// {
//     scanf("%lld%lld%lld", &n, &q, &mod);
//     for (ll i = 1; i <= n; ++i)
//         scanf("%lld", a + i);
//     Node *rot = new Node(1, n);
//     for (ll o, x, y, z; q; --q)
//     {
//         scanf("%lld%lld%lld", &o, &x, &y);
//         if (o == 1)
//         {
//             scanf("%lld", &z);
//             rot->mul(x, y, z);
//         }
//         else if (o == 2)
//         {
//             scanf("%lld", &z);
//             rot->add(x, y, z);
//         }
//         else if (o == 3)
//         {
//             printf("%lld\n", rot->qry(x, y));
//         }
//     }
//     return 0;
// }

int main()
{
    n = read();
    q = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        int x = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] < a[i])
                x++;
        }
        printf("%d ", x);
    }
    puts("");
    while (q--)
    {
        ll op = read(), l = read(), r = read(), x = read();
        if (op == 1)
        {
            for (int i = l; i <= r; i++)
                a[i] += x;
        }
        else
        {
            for (int i = l; i <= r; i++)
                a[i] *= x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] < a[i])
                x++;
        }
        printf("%d ", x);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}