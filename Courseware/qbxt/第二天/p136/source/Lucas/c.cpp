#include<cstdio>
#include<iostream>
#include<cstring>
#define re register
#define ll long long
#define mod 100007
using namespace std;
ll n,a,b,ans,MAXN=2;
struct mat
{
	int m[105][105];
}m1,m2;
mat mul(mat a,mat b)
{
    mat event;
    memset(event.m,0,sizeof(event.m));
    for(register int i=1;i<=MAXN;i++)
       for(register int j=1;j<=MAXN;j++)
          for(register int k=1;k<=MAXN;k++)
              event.m[i][j]=(event.m[i][j]%mod+(a.m[i][k]%mod*b.m[k][j])%mod)%mod;
    return event;
}
mat quickPower(mat a,ll cs)
{
    mat ans;
    memset(ans.m,0,sizeof(ans.m));
    for(register int i=1;i<=MAXN;i++) ans.m[i][i]=1;
    while(cs>0)
    {
        if(cs&1)
          ans=mul(ans,a);
          a=mul(a,a);
          cs>>=1;
    }
    return ans;
}
void work(int k)
{
	mat cover;
	memset(cover.m,0,sizeof(cover.m));
	if(k==0)
	{
		ans=0;
		return ;
	}
	if(k==1)
	{
		ans=1;
		return;
	}
	cover=quickPower(m1,k-1);
	cover=mul(cover,m2);
	ans=cover.m[1][1]%mod;
	return;
}
int main()
{
	freopen("c.in","r",stdin); 
	freopen("c.out","w",stdout); 
	cin>>n>>a>>b;
	m1.m[1][1]=a; m1.m[1][2]=b;
	m1.m[2][1]=1; m1.m[2][2]=0;
	m2.m[1][1]=1;
	m2.m[2][1]=0;
    work(n);
    work(ans);
    cout<<ans;
	return 0;
} 

