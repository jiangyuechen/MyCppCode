#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

ll n,a,b;
const ll pp=1e6+7;
struct matrix1 {
	ll c[2][1];
};
struct matrix2{
	ll c[2][2];
};
matrix2 operator *(matrix2 a, matrix2 b) {
	matrix2 c;
	for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++) {
	  	c.c[i][j]=0;
	  	for(int k=0;k<=1;k++)
	  	  c.c[i][j]+=a.c[i][k]%pp*b.c[k][j]%pp;
	  }
	return c;
}
int f(ll x) {
	matrix2 ans;
	matrix2 chg;
	matrix1 pr,lst;
	pr.c[0][0]=0;pr.c[1][0]=1;
	ans.c[0][0]=1;ans.c[0][1]=0;
	ans.c[1][0]=0;ans.c[1][1]=1;
	chg.c[0][0]=0;chg.c[0][1]=1;
	chg.c[1][0]=b;chg.c[1][1]=a;
	while(x!=0) {
		if(x%2==1) ans=ans*chg;
		chg=chg*chg;
		x/=2;
	}
	lst.c[0][0]=0;lst.c[1][0]=0;
	for(int i=0;i<=1;i++)
	  for(int j=0;j<=1;j++) {
	  	lst.c[i][0]+=ans.c[i][j]%pp*pr.c[j][0]%pp;
	  }
	return lst.c[0][0];
}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>a>>b;
	ll nw=f(n);
	nw=f(nw);
	cout<<nw;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
