#include<iostream>
#include<cstdio>
#include<cctype>
#include<iomanip>
#include<cstring> 
#include<algorithm>
#define LL long long
#define ld long double
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,a,b) for(int i=a;i>=b;++i)
using namespace std;
const int N=110;
LL mod;
int n,m;
LL f[N][N<<1];
LL r,ret;
LL ksm(LL u,LL v)
{  
    ret=1;
    while(v)
	{
        if(v&1)ret=ret*u%mod;
        u=u*u%mod;v>>=1;
    }
    return ret;
}
int main()
{
    freopen("a.in","r",stdin); 
	freopen("a.out","w",stdout); 
	scanf("%d %d",&n,&mod);m=n*2;
    for(int i=1;i<=n;++i)
	{
        for(int j=1;j<=n;j++)scanf("%lld",&f[i][j]);
        f[i][n+i]=1;  
    }
    for(int i=1;i<=n;++i)
	{  
        for(int j=i;j<=n;j++)
        if(f[j][i])
		{
            for(int k=1;k<=m;k++)
            swap(f[i][k],f[j][k]);  
            break;
        }
        r=ksm(f[i][i],mod-2);  
        for(int j=i;j<=m;++j)  
        f[i][j]=f[i][j]*r%mod;
        for(int j=1;j<=n;++j)  
        if(j!=i)
		{
            r=f[j][i];
            for(int k=i;k<=m;++k)
            f[j][k]=(f[j][k]-r*f[i][k]%mod+mod)%mod;
        }
    }
    for(int i=1;i<=n;++i,puts(""))
    for(int j=n+1;j<=m;++j)printf("%lld ",f[i][j]);
}
