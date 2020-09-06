#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int p=1e6+7;
LL n,a,b;
struct matrix{
	LL s[5][5];
};
matrix operator *(matrix x, matrix y){
	matrix c;
	for(int i=0;i<=1;i++)
	 for(int j=0;j<=1;j++){
	 	c.s[i][j]=0;
	 	for(int k=0;k<=1;k++){
	 		c.s[i][j]=(c.s[i][j]+x.s[i][k]*y.s[k][j]%p)%p;
		 }
	 }
	 return c;
}
matrix cz(matrix x, matrix y){
	matrix c;
	for(int i=0;i<=1;i++)
	 for(int j=0;j<=1;j++){
	 	c.s[i][j]=0;
	 	for(int k=0;k<=1;k++){
	 		c.s[i][j]=(c.s[i][j]+x.s[i][k]*y.s[k][j]%329616)%329616;
		 }
	 }
	 return c;
}
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
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();a=read();b=read();
	matrix x,y,z;
	x.s[0][0]=0; x.s[0][1]=1; x.s[1][0]=a; x.s[1][1]=b;
	for(int i=0;i<=1;i++) y.s[i][i]=1;
	y.s[1][0]=0;y.s[0][1]=0;
	LL t=n-1;
	while(t){
		if(t%2) y=y*x;
		x=x*x;
		t/=2;
	}
	if(n>=1&&n<=10){
		x.s[0][0]=0; x.s[0][1]=1; x.s[1][0]=a; x.s[1][1]=b;
	    for(int i=0;i<=1;i++) z.s[i][i]=1;
	    z.s[1][0]=0;z.s[0][1]=0;
	    t=y.s[1][1]-1;
	    while(t){
		  if(t%2) z=z*x;
		  x=x*x;
		  t/=2;
	   }
	  printf("%lld ",z.s[1][1]);
	  fclose(stdin);fclose(stdout); 
	  return 0;
	  
    }
	if(a==1&&b==1){
	    x.s[0][0]=0; x.s[0][1]=1; x.s[1][0]=a; x.s[1][1]=b;
	    for(int i=0;i<=1;i++) z.s[i][i]=1;
	    z.s[1][0]=0;z.s[0][1]=0;
	    t=n-1;
	    while(t){
	    	if(t%2) z=cz(z,x);
	    	x=cz(x,x);
	    	t/=2;
		}
		t=z.s[1][1]-1;
		x.s[0][0]=0; x.s[0][1]=1; x.s[1][0]=a; x.s[1][1]=b;
	    for(int i=0;i<=1;i++) z.s[i][i]=1;
	    z.s[1][0]=0;z.s[0][1]=0;
	    while(t){
		  if(t%2) z=z*x;
		  x=x*x;
		  t/=2;
	   }
	  printf("%lld ",z.s[1][1]);
	}
	fclose(stdin);fclose(stdout); 
	return 0;
}
