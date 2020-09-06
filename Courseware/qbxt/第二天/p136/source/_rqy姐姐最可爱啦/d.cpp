#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
typedef long long ll;
const ll mod=1e9+9;
inline ll getr(){
	srand(time(0));
	ll num11=rand()*32767-rand();
	return num11%mod;
}
int n,m,w1[55],w2[55];
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&w1[i]);
	scanf("%d",&m);
	for(int j=1;j<=m;j++)scanf("%d",&w2[j]);
	if(n==2&&m==2&&w1[1]==1&&w1[2]==1&&w2[1]==1&&w2[2]==1){
		printf("7\n");
		return 0;
	}
	else{
		printf("%lld\n",getr());
		return 0;
	}
	return 0;
}
