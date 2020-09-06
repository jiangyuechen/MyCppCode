#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
long long n,a,b;
int f[1000000];
int mo=1000007;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
    cin>>n>>a>>b;
    
	f[0]=0;
	f[1]=1;
    if(a==1&&b==1)
    {
    	for(long long i=2;i<=n*n;i++)
    	f[i]=f[i-1]%mo+f[i-2]%mo;
    	cout<<f[f[n]]%mo;
    	return 0;
	}
	
	for(long long i=2;i<=n*n;i++)
	  f[i]=a%mo*f[i-1]%mo+b%mo*f[i-2]%mo;
	cout<<f[f[n]]%mo;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
