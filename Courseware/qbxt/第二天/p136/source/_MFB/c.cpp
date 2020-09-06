#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long f[100000000],n;
int a,b;
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld%d%d",&n,&a,&b);
	f[0]=0;
	f[1]=1;
	for(int i=2; i<=n; ++i)
		f[i]=a*f[i-1]+b*f[i-2];
	printf("%lld",f[f[n]]%1000007);
	return 0;
}
