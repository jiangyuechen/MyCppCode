#include<bits/stdc++.h>
using namespace std;
const int mod=1000007;
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    long long last1=0,last2=1;
    int fn;
    if(n==0)
    {
    	fn=0;
	}
	if(n==1)
	{
		fn=1;
	}
	if(n>1)
	{
		for(int i=2;i<=n;i++)
		{
			  int x=(a*last2+b*last1)%mod;
			  last1=last2;
			  last2=x;
        }
        fn=last2;
	}
	int fnn;
	last1=0,last2=1;
	if(fn==0)
    {
    	fnn=0;
	}
	if(fn==1)
	{
		fnn=1;
	}
	if(fn>1)
	{
		for(int i=2;i<=fn;i++)
		{
			  int x=(a*last2+b*last1)%mod;
			  last1=last2;
			  last2=x;
        }
        fnn=last2;
	}
	printf("%d",fnn);
	return 0;
}

