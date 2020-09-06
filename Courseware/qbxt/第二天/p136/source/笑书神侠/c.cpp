#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

long long n,a,b,mod=9e18;
struct F{
	long long e[3][3];
};
F ze;
F operator *(F a,F b)
	{
		F ans=ze;//
		for(int i=1;i<=2;++i)
		{
			for(int j=1;j<=2;++j)
			{
				for(int k=1;k<=2;++k)
				{
					ans.e[i][j]+=a.e[i][k]*b.e[k][j]%mod;
				}
			}
		}
		return ans;
	}
F f,f2,sd,sd2;

F kuaisumi(F a,long long b)
{
	F ret=ze;
	ret.e[1][1]=1;
	ret.e[2][2]=1;
	while(b)
	{
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld %lld %lld",&n,&a,&b);
	n++;
	sd.e[1][1]=a;
	sd.e[1][2]=b;
	sd.e[2][1]=1;
	sd.e[2][2]=0;
	sd2.e[1][1]=a;
	sd2.e[1][2]=b;
	sd2.e[2][1]=1;
	sd2.e[2][2]=0;
	f.e[1][1]=1;
	f.e[2][1]=0;
	f2.e[1][1]=1;
	f2.e[2][1]=0;
	if(n==1)
	{
		printf("0");
		return 0;
	}
	if(n==2)
	{
		printf("1");
		return 0;
	}
	F ans=kuaisumi(sd,n-2);
	F ans1=ans*f;//
	ans1.e[1][1]++;
	mod=1e6+7;
	if(ans1.e[1][1]==1)
	{
		printf("0");
		return 0;
	}
	if(ans1.e[1][1]==2)
	{
		printf("1");
		return 0;
	}
	F ans2=kuaisumi(sd2,ans1.e[1][1]-2);
	F ans3=ans2*f2;
	printf("%lld",ans3.e[1][1]);
	return 0;
}
