#include<iostream>
#include<cstdio>
#define ll long long
#define Mod 1000007
using namespace std;
struct jgt{
	ll m[5][5];
}a,b;
jgt mul(jgt x,jgt y){
	jgt c;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			c.m[i][j]=0;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				c.m[i][j]=(c.m[i][j]+x.m[i][k]%Mod*y.m[k][j]%Mod)%Mod;
	return c; 
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	a.m[1][1]=0;a.m[2][1]=1;
	b.m[1][1]=0;b.m[1][2]=1;b.m[2][1]=y;b.m[2][2]=x;
	int p=n-1;
	while(p){
		if(p&1)a=mul(b,a);
		b=mul(b,b);
		p>>=1;
	}
	p=a.m[2][1]-1;//f(n)
	a.m[1][1]=0;a.m[2][1]=1;
	b.m[1][1]=0;b.m[1][2]=1;b.m[2][1]=y;b.m[2][2]=x;
	while(p){
		if(p&1)a=mul(b,a);
		b=mul(b,b);
		p>>=1;
	}
	cout<<a.m[2][1]%Mod;
} 
