#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define int64 long long
using namespace std;
int64 a[410][410];
int n,m,is[410],js[410];
void exgcd(int a,int b,int &x,int &y){
    if(!b)return x=1,y=0,void();
    exgcd(b,a%b,y,x);y-=x*(a/b);
}
int inv(int p){
    int x,y;exgcd(p,m,x,y);
    return (x+m)%m;
}
void inv(){
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++) 
            for(int j=k;j<=n;j++)if(a[i][j]){
                is[k]=i,js[k]=j;break;
            }
        for(int i=1;i<=n;i++) 
            swap(a[k][i],a[is[k]][i]);
        for(int i=1;i<=n;i++)
            swap(a[i][k],a[i][js[k]]);
        if(!a[k][k]){
            puts("No Solution");
            exit(0);
        }
        a[k][k]=inv(a[k][k]); 
        for(int j=1;j<=n;j++)if(j!=k) 
            (a[k][j]*=a[k][k])%=m;
        for(int i=1;i<=n;i++)if(i!=k) 
            for(int j=1;j<=n;j++)if(j!=k)
                (a[i][j]+=m-a[i][k]*a[k][j]%m)%=m;
        for(int i=1;i<=n;i++)if(i!=k) 
            a[i][k]=(m-a[i][k]*a[k][k]%m)%m;
    }
    for(int k=n;k;k--){ 
        for(int i=1;i<=n;i++)
            swap(a[js[k]][i],a[k][i]);
        for(int i=1;i<=n;i++)
            swap(a[i][is[k]],a[i][k]);
    }
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",a[i]+j);
    inv();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            printf("%lld%c",a[i][j],j==n?'\n':' ');
    return 0;
}
