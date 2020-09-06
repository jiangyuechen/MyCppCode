#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=500;
LL a[N][N],n,p,s[N][N];
LL read(){
	LL f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
LL quick_pow(LL a,LL b,LL mod){
	LL ret=1;
	while(b){
		if(b%2) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();p=read();
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	   a[i][j]=read();
	for(int i=1;i<=n;i++) s[i][i]=1;
	for(int i=1;i<=n;i++){
		int t=i;
		while(a[t][i]==0&&t<=n) t++;
		for(int j=1;j<=n;j++){
			swap(a[t][j],a[i][j]);
			swap(s[t][j],s[i][j]);
		}
		LL mm=quick_pow(a[i][i],p-2,p);
		for(int j=1;j<=n;j++){
		   a[i][j]=a[i][j]*mm%p;
		   s[i][j]=s[i][j]*mm%p;
		}
		for(int j=1;j<=n;j++){
			if(i!=j){
				LL mm=a[j][i];
				for(int k=1;k<=n;k++){
					a[j][k]=((a[j][k]-mm*a[i][k])%p+p)%p;
					s[j][k]=((s[j][k]-mm*s[i][k])%p+p)%p;
				}
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",s[i][j]);
		}
		printf("\n");
	} 
	fclose(stdin);fclose(stdout); 
	return 0;
}
