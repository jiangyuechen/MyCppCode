#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    long long n,k;
	long long x;
    scanf("%lld%lld",&n,&k);
	if(k==1)
	{
		printf("1 1");
		return 0;
	}
	if(k==n)
	{
		printf("%lld 1",n);
		return 0;
	}
    x=(n-k+1);
    long long a,b;
    for(a=1;;a++)
    {
		if((a*x)%n==0)
		{
			b=a*x/n;
			if(a>=k+b-1&&b>=k)
			{
	             //printf("%d %d",2*k-1,k);
	             printf("%lld %lld",a,b);
	             return 0;
			}
		}
	}
	return 0;
}

