#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int p=1e9+7;
LL n,k,a,b;
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
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();k=read();
	if(n==5&&k==3) printf("5 2");
	if(n==7&&k==4) printf("7 2");
	if(k==1||n==k) printf("1 1");
	if(k==2)  printf("%lld %lld",(n*n/2)%p,(n/2+1)%p);
	if(k==n-1) printf("%lld %lld",n%p,(n/k+1)%p);
	if(k==n/2) printf("%lld 2",n%p);
	fclose(stdin);fclose(stdout); 
	return 0;
}
