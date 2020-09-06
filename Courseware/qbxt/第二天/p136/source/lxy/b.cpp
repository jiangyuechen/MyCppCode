#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll ;
const ll p=1e9+7;
int n,k;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n>>k;
	if(k==1)
	{
		cout<<1<<1;return 0;
	}
	if(n==k)
	{
		cout<<n%p<<1;return 0;
	}
	if(k==2)
	{
		cout<<n%p<<(n-1)%p;return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
