#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<stdio.h>
#include<string.h>
#define mod 1000007
using namespace std;
int a,b;
long long n;
int f;
int x[3][3];
int y[3][3];
int h[3][3];
void c(){
	h[1][1]=(x[1][1]*y[1][1]+x[1][2]*y[2][1])%mod;
	h[1][2]=(x[1][1]*y[1][2]+x[1][2]*y[2][2])%mod;
	h[2][1]=(x[2][1]*y[1][1]+x[2][2]*y[2][1])%mod;
	h[2][2]=(x[2][1]*y[1][2]+x[2][2]*y[2][2])%mod;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++) x[i][j]=h[i][j];
	}
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	if(n==1){
		cout<<1;
		return 0;
	}
	a%=mod;
	b%=mod;
	x[1][1]=0;
	x[1][2]=1;
	x[2][1]=b;
	x[2][2]=a;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++) y[i][j]=x[i][j];
	}
	for(int i=3;i<=n;i++) c();
	f=x[2][2];
	x[1][1]=0;
	x[1][2]=1;
	x[2][1]=b;
	x[2][2]=a;
	for(int i=3;i<=f;i++) c();
	cout<<x[2][2];
	return 0;
}
