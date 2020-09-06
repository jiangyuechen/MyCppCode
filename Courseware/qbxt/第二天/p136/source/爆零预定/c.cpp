#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int f[110],ff;
int mo=1e6+7;

int qp(int l, int x, int m)
{
    long long ans = 1;
    while(x){
        if(x&1){
            ans = (ans * l) % m;
        }
        l = (l* l) % m;
        x >>= 1;
    }
    return ans;
}


int main()
{
	f[1]=1;
	
	cin>>n>>a>>b;
	
	
	
	for(int i=2;i<=n;i++)
	{
		f[i]=(a*f[i-1]+b*f[i-2])%mo;
	}
	if(f[n]<=n)
	{
		cout<<f[f[n]];
	}
	else
	{
		for(int i=n;i<=f[n];i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%mo;
		}
		cout<<f[f[n]];
	}
	return 0;
}
