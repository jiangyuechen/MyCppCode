#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,n,c,ans=0;
long long q[1000000];
int main()
{
	freopen("c.in", "r", stdin);
     freopen("c.out", "w", stdout);
	scanf("%ld%ld%ld",&n,&a,&b);
	q[0]=0;q[1]=1;
	for(int i=2;i<=n;i++)
	{
		q[i]=a*q[i-1]+b*q[i-2];
	}
	for(int i=n+1;i<=q[n];i++)
	{
		q[i]=a*q[i-1]+b*q[i-2];
	}
	cout<<q[q[n]]%1000007;
	 fclose(stdin);
     fclose(stdout);
	return 0;
}
