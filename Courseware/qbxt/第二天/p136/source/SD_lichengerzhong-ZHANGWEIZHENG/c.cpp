#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e6+7;
int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	ll f[10]={0};
	f[0]=0;
	f[1]=1;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		f[i]=a*f[i-1]+b*f[i-2];
	}
	cout<<f[f[n]];
	return 0;
}
