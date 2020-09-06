#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

const int mod = 1e6+7 ;

long long n,a,b ;

struct MAT {
    long long M[205][205] ;
}F,Ans,G,D,BB,AA ;

MAT Mul(MAT A,MAT B) {
    MAT temp ;
    memset(temp.M,0,sizeof(temp.M)) ;
      for(register int i=1;i<=2;i++)
       for(register int j=1;j<=2;j++)
          for(register int k=1;k<=2;k++)
              temp.M[i][j]=(temp.M[i][j]%mod+(A.M[i][k]%mod*B.M[k][j])%mod)%mod ;
    return temp ;
}
MAT Quick_Pow(MAT z,long long x) {
    MAT sum ;
    memset(sum.M,0,sizeof(sum.M)) ;
    sum.M[1][1]=1;sum.M[2][2]=1 ;
    while(x) {
        if(x & 1)
          sum = Mul(sum,z) ;
          z = Mul(z,z) ;
          x >>= 1 ;
    }return sum ;
}

int main()
{
      freopen("c.in","r",stdin) ;
      freopen("c.out","w",stdout) ;
    scanf("%lld%lld%lld",&n,&a,&b);
    Ans.M[1][1] = a ; Ans.M[1][2] = b ;
      Ans.M[2][1] = 1 ; Ans.M[2][2] = 0 ;
    D = Quick_Pow(Ans,n-1) ;
    F.M[1][1] = 1 ; F.M[1][2] = 0 ;
    
    G = Mul(F,D) ;
    int Z = G.M[1][1] ;
    BB = Quick_Pow(Ans,Z-1) ; AA = Mul(F,BB) ;
    Z = AA.M[1][1] ;
    printf("%lld",Z) ;
    return 0 ;
}

