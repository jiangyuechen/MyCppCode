#include<cstdio>
#include<algorithm>
typedef long long lnt;
using namespace std;

#define mod 1000000009

lnt N,M;
lnt n[50],m[50];
lnt cntn[50],cntm[50];
lnt maxh[50][50];

lnt pow(lnt a,lnt b){
  lnt ans=1;
  for(;b;b>>=1){
    if(b&1)ans=(ans*a)%mod;
    a=(a*a)%mod;
  }
  return ans;
}

int main(){
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);
  scanf("%lld",&N);
  for(lnt i=0;i<N;i++)scanf("%lld",n+i);
  scanf("%lld",&M);
  for(lnt i=0;i<M;i++)scanf("%lld",m+i);

  for(lnt i=0;i<N;i++)
    for(lnt j=0;j<M;j++)
      maxh[i][j]=min(n[i],m[j]);
  
  for(lnt i=0;i<N;i++){
    lnt h=0;
    for(lnt j=0;j<M;j++){
      h=max(h,maxh[i][j]);
      if(maxh[i][j]==n[i])
        cntn[i]++;
    }
    if(h!=n[i]){
      printf("0\n");
      fclose(stdin);
      fclose(stdout);
      return 0;
    }
  }
  for(lnt j=0;j<M;j++){
    lnt h=0;
    for(lnt i=0;i<N;i++){
      h=max(h,maxh[i][j]);
      if(maxh[i][j]==m[j])
        cntm[j]++;
    }
    if(h!=m[j]){
      printf("0\n");
      fclose(stdin);
      fclose(stdout);
      return 0;
    }
  }

  lnt ans=1;
  for(lnt i=0;i<N;i++)
    for(lnt j=0;j<M;j++)
      ans*=(maxh[i][j]+1);
  for(lnt i=0;i<N;i++)
    ans=(ans*pow((n[i]+1),mod-2))%mod;
  for(lnt i=0;i<M;i++)
    ans=(ans*pow((m[i]+1),mod-2))%mod;

  printf("%lld",ans);

  fclose(stdin);
  fclose(stdout);
}