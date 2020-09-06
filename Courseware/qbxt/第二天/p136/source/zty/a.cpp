#include<cstdio>
typedef long long lnt;
using namespace std;

lnt N,p;
lnt pow(lnt,lnt);

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  scanf("%lld%lld",&N,&p);
  if(N==1){
    lnt a;
    scanf("%lld",&a);
    printf("%lld",pow(a,p-2));
  }
  fclose(stdin);
  fclose(stdout);
}

lnt pow(lnt a,lnt b){
  lnt res=1;
  for(;b;b>>=1){
    if(b&1)res=(res*a)%p;
    a=(a*a)%p;
  }
  return res;
}