#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll read(){
	ll a=0;int f=0;char p=getchar();
	while(!isdigit(p)){f|=p=='-';p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=getchar();	}
	return f?-a:a;
}
ll a[101][101];
ll eps=1E-8;
ll n,p,ret; 
ll ny(ll u,ll v){
	ret=1;
	while(v){
		if(v&1)ret=ret*u%p;
		u=u*u%p;
		v>>=1;
	}
	return ret;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout); 
	n=read();p=read();
	int m=n*2;//emm矩阵+单位矩阵 
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=read();
	for(int i=1;i<=n;i++)a[i][n+i]=1;//emmm单位矩阵 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
		 if(a[j][i]){
            for(int k=1;k<=m;k++)
            swap(a[i][k],a[j][k]);  //先交换 
            break;
        }
		if(!a[i][i]){cout<<"No Solution";return 0;}
		
		int r=ny(a[i][i],p-2) ;
		
		for(int j=i;j<=m;j++)a[i][j]=a[i][j]*r%p;
		for(int j=1;j<=n;j++){
			if(i!=j){
				r=a[j][i];
				for(int k=i+1;k<=m;k++)a[j][k]=(a[j][k]-r*a[i][k]%p+p)%p;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n+1;j<=m;j++){
			cout<<a[i][j]<<" ";
		} 
		cout<<endl;
	}
}
