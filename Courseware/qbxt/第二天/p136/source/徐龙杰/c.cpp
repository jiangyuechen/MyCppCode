#include<bits/stdc++.h> 
using namespace std;
#define p 1000007
struct matrix{
	long long a[4][4];
};
matrix mul(matrix x,matrix y){
	matrix d;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			d.a[i][j]=0;
			for(int k=0;k<=1;k++){
				d.a[i][j]=d.a[i][j]+(x.a[i][k]%p*y.a[k][j]%p)%p;
			}
		}
	}
	return d;
}
matrix pow(matrix a,long long b){
	matrix tmp=a,final;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			final.a[i][j]=0;
			if(i==j){
				final.a[i][j]=1;
			}
		}
	}
	
	while(b){
		if(b&1!=0)final=mul(final,tmp);
		tmp=mul(tmp,tmp);
		b/=2;
	}
	return final;
}
matrix I,E,ans1,ans2;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	long long n;
	scanf("%lld%lld%lld",&n,&I.a[1][1],&I.a[1][0]);
	I.a[0][0]=0;
	I.a[0][1]=1;
	E.a[0][0]=0;
	E.a[1][0]=1;
	matrix f=pow(I,n-1);
	for(int i=0;i<=1;i++){
		int j=0;
		ans1.a[i][j]=0;
		for(int k=0;k<=1;k++){
			ans1.a[i][j]=ans1.a[i][j]+f.a[i][k]*E.a[k][j];
		}
	}
	f=pow(I,ans1.a[1][0]-1);
	for(int i=0;i<=1;i++){
		int j=0;
		ans2.a[i][j]=0;
		for(int k=0;k<=1;k++){
			ans2.a[i][j]=ans2.a[i][j]+f.a[i][k]*E.a[k][j];
		}
	}
	printf("%lld",ans2.a[1][0]);
	return 0;
}
