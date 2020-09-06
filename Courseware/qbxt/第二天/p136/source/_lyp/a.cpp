#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m;
ll A[500][2000];
ll r,mod;
ll quickpow(ll base,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res *= base;
            res = res % mod;
        }
        base *= base;
        base %= mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    //scanf("%d",&n);
    //m = n * 2£»
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d%lld",&n,&mod);
    m = n * 2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        scanf("%lld",&A[i][j]);
        A[i][i + n] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        if(A[i][j])
        {
            for(int k=1;k<=m;k++)
            swap(A[i][k],A[j][k]);
            //break;
        }
        if(!A[i][i])
        {
            printf("No Solution");
            return 0;
        }
        r = quickpow(A[i][i],mod - 2);
        for(int j=i;j<=m;j++)
        A[i][j] = A[i][j] * r % mod;
        for(int j=1;j<=n;j++)
        if(j != i)
        {
            r = A[j][i];
            for(int k=i;k<=m;k++)
            A[j][k] = (A[j][k] - r * A[i][k] % mod + mod) % mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n+1;j<=m;j++)
        printf("%lld ",A[i][j]);
        printf("\n");
    }
    return 0;
}
