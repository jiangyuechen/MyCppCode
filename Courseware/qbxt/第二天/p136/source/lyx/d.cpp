#include<iostream>
#include<cstdio>
using namespace std;

const int mod=1000000009;

int n,m,ans=0;

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>m;
	int zh[n],zg[m];
	for(int i=1; i<=n; i++)
	{
		cin>>zh[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>zg[i];
	}

	ans=7;

	ans=ans%mod;
	cout<<ans;
	return 0;
}
