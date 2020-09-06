#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
int n,m;
LL f[111][222],p;
LL ksm(LL x,LL y)
{
	LL tmp=1;
	while(y){
		if(y%2) tmp=tmp*x%p;
		x=x*x%p;
		y/=2;
	}
	return tmp;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%lld",&n,&p);
	m=n*2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		  scanf("%lld",&f[i][j]);
		f[i][n+i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		  if(f[j][i]){swap(f[j],f[i]);break;}
		LL r=ksm(f[i][i],p-2);
		for(int j=i;j<=m;j++)
		  f[i][j]=f[i][j]*r%p;
		for(int j=1;j<=n;j++){
			if(j!=i){
			r=f[j][i];
			for(int k=i;k<=m;k++)
			  f[j][k]=(f[j][k]-r*f[i][k]%p+p)%p;
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n+1;j<=m;j++)
		  printf("%lld ",f[i][j]%p);
		cout<<"\n";
	}
	return 0;
}
