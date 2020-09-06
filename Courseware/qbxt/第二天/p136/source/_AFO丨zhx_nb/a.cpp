#include <cstdio>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

inline long long read()
{
    long long x=0,f=1;
    char c;
    while(!isdigit(c=getchar()))
    if(c=='-') f=-1;
    while(isdigit(c))
    x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return x*f; 
}

const int maxn = 1926;

int n,m,mod;

long long f[maxn][maxn<<1],inv;

long long quickpower(long long a,long long b) 
{
    long long ans =  1;
    while(b)
	{
        if(b & 1) ans=ans*a%mod;
        
		a = a*a%mod;
		
		b >>= 1;
    }
    return ans;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
    scanf("%d%d",&n,&mod);
    
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
			f[i][j]=read();
        
		f[i][n+i]=1;
    }
    
    /*for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n*2;j++)
    		printf("%d ",f[i][j]);
    	
    	printf("\n");
	}*/
    			
    for(int i=1;i<=n;i++)
	{
        for(int j=i;j<=n;j++)
        if(f[j][i] && i != j)
		{
			swap(f[i],f[j]);
			break;
		}
        
		inv=quickpower(f[i][i],mod-2);
		
//		printf("inv=%d\n",inv); 
        
		for(int j=i;j<=n*2;j++)
        	f[i][j] = f[i][j]*inv%mod;
        
		for(int j=1;j<=n;j++)
        	if(j!=i)
			{
	            inv=f[j][i];
	            
				for(int k=i;k<=n*2;++k)
	            	f[j][k] = (f[j][k] - inv*f[i][k]%mod + mod)%mod;
        	}
        
        /*printf("------------------------\n");
        
        for(int s=1;s<=n;s++)
	    {
	    	for(int d=1;d<=2*n;d++)
	    	{
	    		if(d==n+1)
	    			printf("          "); 
	    		printf("%lld ",f[s][d]);
			}
	    		
	    	
	    	printf("\n");
		}*/
    }
    
    
//    printf("------------------------\n");
    
	for(int i=1;i<=n;i++)
    {
    	for(int j=n+1;j<=n*2;++j)
			printf("%lld ",f[i][j]);
    	
    	printf("\n");
	}
    
    return 0;
}

/**
  *　　┏┓　　　┏┓+ +
  *　┏┛┻━━━┛┻┓ + +
  *　┃　  _T Y F　　┃
  *　┃　　　━　　　┃ ++ + + +
  *  ████━████+
  *  ◥██◤　◥██◤ +
  *　┃　　　┻　　　┃
  *　┃　　　　　　　┃ + +
  *　┗━┓　　　┏━┛
  *　　　┃　　　┃ + + + +Code is far away from 　
  *　　　┃　　　┃ + bug with the god animal protecting
  *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
  *　　　┃ 　　　　　　 ┣┓
  *　　  ┃ 　　　　　 　┏┛
  *　    ┗┓┓┏━┳┓┏┛ + + + +
  *　　　　┃┫┫　┃┫┫
  *　　　　┗┻┛　┗┻┛+ + + +
  */ 
