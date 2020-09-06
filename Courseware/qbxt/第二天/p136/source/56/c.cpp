#include <iostream>
#include <cstdio>
using namespace std;
int n;
unsigned long long f[1000],a,b;
const unsigned long long MOD=1e6+7;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>a>>b;
	f[1]=1;
	for(int i=2;i<=n;i++)
	  f[i]=a*f[i-1]+b*f[i-2];
	for(int i=n+1;i<=f[n];i++)
	  f[i]=a*f[i-1]+b*f[i-2];
	cout<<f[f[n]]%MOD;
	return 0;
}
