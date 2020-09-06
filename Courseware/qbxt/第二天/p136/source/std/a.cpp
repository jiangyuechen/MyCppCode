#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m,p;
long long f[N][N<<1];
long long r,back;
long long ni(long long u,long long v)
{
    back=1;
    while (v)
	{
        if (v&1)
		{
			back=back*u%p;
        }
		u=u*u%p;
		v>>=1;
    }
	return back;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    scanf("%d%d",&n,&p);
	m=n*2;
    for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			scanf("%lld",&f[i][j]);
        	f[i][n+i]=1;
        }
    }
    for (int i=1;i<=n;++i)
	{
        for(int j=i;j<=n;++j)
        {
			if(f[j][i])
			{
				for (int k=1;k<=m;k++)
				{
					swap(f[i][k],f[j][k]);
            	}
				break;
			}
		} 
		r=ni(f[i][i],p-2); 
		for (int j=i;j<=m;++j)
		{
			f[i][j]=f[i][j]*r%p;
        }
		for (int j=1;j<=n;++j)
        {
        	if (j!=i)
			{
            	r=f[j][i];
            	for (int k=i;k<=m;++k)
				{
					f[j][k]=(f[j][k]-r*f[i][k]%p+p)%p;
				}
			}
        }
    }
    for (int i=1;i<=n;++i)
	{
		for (int j=n+1;j<=m;++j)
		{
			printf("%lld ",f[i][j]);
		}
		cout<<endl;
	}
	fclose(stdin);fclose(stdout);
    return 0;
}
