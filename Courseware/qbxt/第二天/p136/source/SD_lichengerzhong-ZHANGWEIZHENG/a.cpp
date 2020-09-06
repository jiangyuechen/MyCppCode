#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=405;
int n,m;
ll f[N][N<<1];
ll r,ret;
ll ksm(ll u,ll v,ll mod)
{
    ret=1;
    while(v)
	{
        if(v&1)
		{
			ret=ret*u%mod;
		}
        u=u*u%mod;
		v>>=1;
    }
    return ret;
}
int main()
{
	ll p;
    cin>>n>>p;
	m=n*2;
    for(int i=1;i<=n;++i)
	{
        for(int j=1;j<=n;j++)
		{
			cin>>f[i][j];
		}
        f[i][n+i]=1;   
    }
    for(int i=1;i<=n;++i)
	{
        for(int j=i;j<=n;j++)
        if(f[j][i])
		{
            for(int k=1;k<=m;k++)
            {
            	swap(f[i][k],f[j][k]);
			}
            break;
    	}
        r=ksm(f[i][i],p-2,p);
        for(int j=i;j<=m;++j)
		{ 
        	f[i][j]=f[i][j]*r%p;
    	}
        for(int j=1;j<=n;++j)
		{
			if(j!=i)
			{
            	r=f[j][i];
            	for(int k=i;k<=m;++k)
            	{
            		f[j][k]=(f[j][k]-r*f[i][k]%p+p)%p;
				}
        	}
		}
    }
    for(int i=1;i<=n;++i,puts(""))
    {
    	for(int j=n+1;j<=m;++j)
		{
			printf("%lld ",f[i][j]);	
		}
	}
	return 0;
}
