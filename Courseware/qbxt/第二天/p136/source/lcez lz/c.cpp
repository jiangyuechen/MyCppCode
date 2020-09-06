#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,c,b;
long long mo=1e6+7;
struct amazing{
	int a[2][2];
};
amazing operator *(amazing a,amazing b){
	amazing c;
	for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++){
	  	c.a[i][j]=0;
	  	  for(int k=0;k<=1;k++)
	  	  c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mo;
	  }
	  return c;
}
int pf(int n){
	int d=n-1;
	amazing a;
	a.a[0][0]=c;a.a[1][0]=b;
	a.a[0][1]=1;a.a[1][1]=0;
	amazing ans;
	ans.a[0][0]=1;ans.a[1][0]=0;
	ans.a[0][1]=0;ans.a[1][1]=1;
	while(d){
		if(d&1)ans=ans*a;
		a=a*a;
		d/=2;
}
	return ans.a[0][0];
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d%d",&n,&c,&b);
	long long fn=pf(n);
	long long ffn=pf(fn)%mo;
	/*int b=n-1;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b/=2;
	}
	cout<<ans.a[0][0]<<endl;
	long long ffn=ans.a[0][0]%mo;*/
	printf("%lld",ffn);
	return 0;
}
