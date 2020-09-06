#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==k)
	{
		cout<<n<<" "<<1;
		return 0;
	}
	if(k==1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	if(k==2)
	{
		cout<<n<<" "<<n-1;
		return 0;
	}
	if(n-1==k)
	{
		cout<<n<<" "<<2;
		return 0;
	}
	cout<<n<<" "<<k;
	return 0;
}
