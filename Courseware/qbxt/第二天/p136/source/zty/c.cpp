#include<cstdio>
typedef long long lnt;
using namespace std;

#define mb 100007
#define seg 482776

lnt mod;

struct matrix{
  lnt val[2][2];
  lnt*operator[](lnt pos){return val[pos];}
  matrix operator*(matrix&oth){
    matrix res;
    for(lnt i=0;i<2;i++)
      for(lnt j=0;j<2;j++){
        res[i][j]=0;
        for(lnt k=0;k<2;k++)
          res.val[i][j]=(res.val[i][j]+val[i][k]*oth.val[k][j])%mod;
        }
    return res;
  }
};

lnt pow(lnt,lnt,lnt);
matrix pow(matrix,lnt);
lnt n,a,b;

int main(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  scanf("%lld%lld%lld",&n,&a,&b);
  if(!b){
    n=pow(a,n-1,mod-1);
    printf("%lld\n",pow(a,n-1,mod));
  }else if(a==1&&b==1){
    matrix mult;
    mod=seg;
    mult[0][0]=0;mult[0][1]=1;
    mult[1][0]=1;mult[1][1]=1;
    mult=pow(mult,n-1);
    n=mult[0][1]+mult[0][0];
    mod=mb;
    mult[0][0]=0;mult[0][1]=1;
    mult[1][0]=1;mult[1][1]=1;
    mult=pow(mult,n-1);
    printf("%lld",mult[0][1]+mult[0][0]);
  }else{
    matrix mult;
    mod=(lnt)(1<<31)-1;
    mult[0][0]=0;mult[0][1]=1;
    mult[1][0]=b;mult[1][1]=a;
    mult=pow(mult,n-1);
    n=mult[0][1]+mult[0][0];
    mod=mb;
    mult[0][0]=0;mult[0][1]=1;
    mult[1][0]=b;mult[1][1]=a;
    mult=pow(mult,n-1);
    printf("%lld",mult[0][1]+mult[0][0]);
  }
  fclose(stdin);
  fclose(stdout);
}

lnt pow(lnt a,lnt b,lnt m){
  lnt res=1;
  for(;b;b>>=1){
    if(b&1)res=(res*a)%m;
    a=(a*a)%m;
  }
  return res;
}

matrix pow(matrix a,lnt b){
  matrix res=a;
  b--;
  for(;b;b>>=1){
    if(b&1)res=res*a;
    a=a*a;
  }
  return res;
}