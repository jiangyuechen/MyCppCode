#include<bits/stdc++.h>
using namespace std;
long long pow(long long a, long long n, long long p) 
{
    long long ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
long long ny(long long a, long long b)
{
    return pow(a, b - 2, b);
}
int n,k;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&k);
	long long a[100005];
	a[1]=1;
	for(int i=2;i<=105;i++)
	{
		a[i] = a[i - 1] * i % 1000000007;
	}
    long long ans1= a[n] * ny(a[k], 1000000007) % 1000000007 * ny(a[n - k], 1000000007) % 1000000007;

cout<<ans1;
ans1*=((n-k+1))%1000000007;
ans1/=n;
ans1%=1000000007;
cout<<" "<<ans1;
return 0;
}
