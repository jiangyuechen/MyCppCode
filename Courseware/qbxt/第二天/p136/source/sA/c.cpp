#include<cstdio>
#include<iostream>
#include<cstring>
#define re register
#define ll long long
#define mod 1000007
using namespace std;
ll n,a,b,e_ans,N=2;
struct Matrix{
	int m[105][105];
}res,ss;
Matrix Mul(Matrix A,Matrix B)
{
    Matrix temp;
    memset(temp.m,0,sizeof(temp.m));
    for(register int i=1;i<=N;i++)
       for(register int j=1;j<=N;j++)
          for(register int k=1;k<=N;k++)
              temp.m[i][j]=(temp.m[i][j]%mod+(A.m[i][k]%mod*B.m[k][j])%mod)%mod;
    return temp;
}
Matrix quickPower(Matrix a,ll T)
{
    Matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(register int i=1;i<=N;i++) ans.m[i][i]=1;
    while(T>0)
    {
    
        if(T&1)
          ans=Mul(ans,a);
          a=Mul(a,a);
          T>>=1;
    }
    return ans;
}
void solve(int k)
{
	Matrix IOI;
	memset(IOI.m,0,sizeof(IOI.m));
	if(k==0)
	{
		e_ans=0;
		return ;
	}
	if(k==1)
	{
		e_ans=1;
		return;
	}
	
	IOI=quickPower(res,k-1);
	IOI=Mul(IOI,ss);
	e_ans=IOI.m[1][1]%mod;

	return;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld%lld%lld",&n,&a,&b);
	res.m[1][1]=a; res.m[1][2]=b;
	res.m[2][1]=1; res.m[2][2]=0;
	ss.m[1][1]=1;
	ss.m[2][1]=0;
    solve(n);
    solve(e_ans);
    printf("%lld\n",e_ans);
	return 0;
} 
