#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll f(ll);
ll a,b;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ll n;
	scanf("%d%d%d",&n,&a,&b);
	printf("%d",f(f(n)));
}

ll f(ll m)
{
	f(0)=0;
	f(1)=1;
	return a*f(m-1)+b*f(m-2);
}
