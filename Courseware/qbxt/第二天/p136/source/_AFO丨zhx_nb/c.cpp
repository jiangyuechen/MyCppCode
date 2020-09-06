#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

const int mod = 1e6+7;

long long n,a,b;

struct Matrix{
    long long m[205][205];
}ret,res,zhxak,zhx,zhx2,zhxak2;

Matrix Mul(Matrix A,Matrix B)//% de 
{
    Matrix temp;
    memset(temp.m,0,sizeof(temp.m));
//	//printf("temp Matrix:\n");
//    for(register int i=1;i<=2;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",temp.m[i][j]);
//        
//		printf("\n");
//	}
//	
//	printf("A Matrix:\n");
//    for(register int i=1;i<=2;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",A.m[i][j]);
//        
//		printf("\n");
//	}
//	
//	printf("B Matrix:\n");
//    for(register int i=1;i<=2;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",B.m[i][j]);
//        
//		printf("\n");
//	}
//    
	for(register int i=1;i<=2;i++)
       for(register int j=1;j<=2;j++)
          for(register int k=1;k<=2;k++)
              temp.m[i][j]=(temp.m[i][j]%mod+(A.m[i][k]%mod*B.m[k][j])%mod)%mod;
    return temp;
}

//Matrix Mul2(Matrix A,Matrix B)/ % de 
//{
//    Matrix temp;
//    memset(temp.m,0,sizeof(temp.m));
//    for(register int i=1;i<=2;i++)
//       for(register int j=1;j<=2;j++)
//          for(register int k=1;k<=2;k++)
//              temp.m[i][j]=(temp.m[i][j]+(A.m[i][k]*B.m[k][j]));
//    return temp;
//}

//Matrix mul(Matrix A,Matrix B)
//{
//    Matrix temp;
//    memset(temp.m,0,sizeof(temp.m));
//       for(register int j=1;j<=2;j++)
//          for(register int k=1;k<=2;k++)
//              temp.m[1][j]=(temp.m[1][j]+(A.m[1][k]*B.m[k][j]));
//    return temp;
//}

//Matrix quickpower2(Matrix q,long long w)/ % de 
//{
//    Matrix ans;
//    for(register int i=1;i<=n;i++) ans.m[i][i]=1;
//    while(w)
//    {
//        if(w & 1)
//          ans = Mul2(ans,q);
//          q = Mul2(q,q);
//          w >>= 1;
//    }
//    return ans;
//}

Matrix quickpower(Matrix z,long long x)//% de 
{
    Matrix sum;
    memset(sum.m,0,sizeof(sum.m));
    sum.m[1][1]=1;sum.m[2][2]=1;
    while(x)
    {
        if(x & 1)
          sum = Mul(sum,z);
          z = Mul(z,z);
          x >>= 1;
    }
    
//    printf("sum Matrix:\n");
//    for(register int i=1;i<=2;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",sum.m[i][j]);
//        
//		printf("\n");
//	}
//	
    return sum;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
    scanf("%lld%lld%lld",&n,&a,&b);
    
    res.m[1][1] = a;
	res.m[1][2] = b;
	res.m[2][1] = 1;
	res.m[2][2] = 0;
	
////	printf("res Matrix:\n");
////    for(register int i=1;i<=2;i++)
////    {
////        for(register int j=1;j<=2;j++)
////            printf("%lld ",res.m[i][j]);
////        
////		printf("\n");
////	}
////	
////	
//	printf("n-1 = %d\n",n-1);
	
    zhx = quickpower(res,n-1);
    
//    printf("zhx Matrix:\n");
//    for(register int i=1;i<=2;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",zhx.m[i][j]);
//        
//		printf("\n");
//    }
//    
    ret.m[1][1] = 1;
	ret.m[1][2] = 0;
	
    zhxak = Mul(ret,zhx);
    
//    for(register int i=1;i<=1;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",zhxak.m[i][j]);
//        
//		printf("\n");
//	}
	
    int zhxakioi = zhxak.m[1][1];
    
//    printf("zhxakioi-1 = %lld\n",zhxakioi-1);
    
    zhx2 = quickpower(res,zhxakioi-1);
    
//    printf("res Matrix:\n");
//    for(register int i=1;i<=2;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",res.m[i][j]);
//        
//		printf("\n");
//	}
//    
//    
//    printf("zhx2 Matrix:\n");
//    for(register int i=1;i<=2;i++)
//    {
//        for(register int j=1;j<=2;j++)
//            printf("%lld ",zhx2.m[i][j]);
//        
//		printf("\n");
//	}
//    
    zhxak2 = Mul(ret,zhx2);
    
    zhxakioi = zhxak2.m[1][1];
    
    printf("%lld",zhxakioi);
    
    return 0;
}

