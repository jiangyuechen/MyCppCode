#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=105;
int n,m;
ll a[N][2*N],p;
ll f(ll b,ll k)
{ 
   ll s=1;
    while(k!=0)
	{
        if(k%2==1) s=s*b%p;
        b=b*b%p;
	    k/=2;
    }
    return s;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout); 
    scanf("%d%lld",&n,&p);
	m=2*n;
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
        a[i][n+i]=1;
    }
    for(int i=1;i<=n;i++)
	{ 
        int t=i;
   	    while(a[t][i]==0) t++;
   	    for(int j=1;j<=m;j++) swap(a[i][j],a[t][j]);
		ll kk=f(a[i][i],p-2);  
        for(int j=1;j<=m;j++) a[i][j]=a[i][j]*kk%p;
        for(int j=1;j<=n;j++) 
          if(j!=i)
		  {
            kk=a[j][i];
            for(int k=1;k<=m;k++) 
			  a[j][k]=(a[j][k]-kk*a[i][k]%p+p)%p;
          }
    }
    for(int i=1;i<=n;i++)
    {
   	   for(int j=n+1;j<=m;j++) printf("%lld ",a[i][j]);
   	   cout<<endl;
    } 
    
    fclose(stdin);fclose(stdout);
 return 0;
}
