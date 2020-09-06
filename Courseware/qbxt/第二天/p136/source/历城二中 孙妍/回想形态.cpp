#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,a,b,mo=1000007;
struct jjjz{
	long long jz[2][2];
} c;
jjjz operator *(jjjz a,jjjz b)
{jjjz an;
  for(int i=0;i<=1;i++)
  {for(int j=0;j<=1;j++)
     {an.jz[i][j]=0;
     for(int k=0;k<=1;k++)
      an.jz[i][j]=(an.jz[i][j]+a.jz[i][k]*b.jz[k][j])%mo;
	 }
  }
  return an;
}
int main()
{  scanf("%lld%lld%lld",&n,&a,&b);
   c.jz[0][0]=0;c.jz[0][1]=1;c.jz[1][0]=b;c.jz[1][1]=a;
   jjjz an,a=c;
   an.jz[0][0]=1;an.jz[0][1]=0;
   an.jz[1][1]=0;an.jz[1][1]=1;
   long long k=n-1;
   while(k)
   {if(k&1)an=an*a;
     a=a*a;
     k/=2;}
    for(int i=0;i<=1;i++)for(int j=0;j<=1;j++)cout<<an.jz[i][j]<<endl;
   long long mi=an.jz[1][1];
   an.jz[0][0]=1;an.jz[0][1]=0;
   an.jz[1][1]=0;an.jz[1][1]=1;
   k=mi-1;
   a=c;
   while(k)
   {if(k&1)an=an*a;
    a=a*a;
    k/=2;}
   long long f=an.jz[1][1];
   printf("%lld",f);
}
