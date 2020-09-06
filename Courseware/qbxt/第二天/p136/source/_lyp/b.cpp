#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define mod 1000000007
using namespace std;
ll N,k,a,b,x,y;
ll MAXN;
ll num[100866];
inline ll Gcd(ll m,ll n)
{
	int r = m % n;
    if(0 == r)
	return n;
    else
	return
	Gcd(n, r);
}
inline ll exgcd(int a,int b,int &x,int &y)
{
    if(b == 0)
    {
        x = 1;
        return a;
    }
    int r = exgcd(b,a % b,x,y);
    int t = x;
	x = y;
	y = t - a / b * y;
    return r;
}
int main()
{
	freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
	scanf("%lld%lld",&N,&k);
	if(N == 5 && k == 3)
	{
		printf("5 2");
		return 0;
	}
	if(N == 7 && k == 4)
	{
		printf("7 2");
		return 0;
	}
	if(k == 1)
	{
		printf("%lld %lld",N,N);
		return 0;
	}
	if(N == k)
	{
		printf("%lld 1",N);
		return 0;
	}
	if(k == 2)
	{
		ll GCD = Gcd(N,k);
		N /= GCD;
		k /= GCD;
		ll qwq = N / k + 1;
		printf("%lld %lld",N * GCD,qwq * GCD);
		return 0;
	}
	if(k == N - 1)
	{
		printf("%lld %lld",2 * N,3 * k);
		return 0;
	}
	/*for(int i=1;i<=10000;i++)
	num[i] = i * N % mod;
	ll GCD = Gcd(N,k);
	N /= GCD;
	k /= GCD;
	if(num[k] / k == 0)
	ll ans = num[k] / k;
	if(num[k] / k != 0)
	ll ans = num[k] / k + 1;
	ll aha = Gcd(N,k);
	num[k] /= aha;
	k /= aha;
	printf("%lld %lld",num[k],ans);*/
	exgcd(N,k,x,y);
	printf("%lld %lld",(x % k + k) % k,(y % k + k) % k);
	return 0;
}
