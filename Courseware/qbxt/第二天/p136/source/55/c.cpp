#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
int modd=1e6+7;
struct node
{
	ll mp[5][5];
}c,d,e;
ll n,a,b;
ll read()
{
	ll sum=0;int fg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') fg=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*fg;
}
node ff(node p,node q)
{
	node z;
	for(int i=1;i<=2;i++)
	  for(int j=1;j<=2;j++) z.mp[i][j]=0;
    for(int i=1;i<=2;i++)
      for(int j=1;j<=2;j++)
        for(int k=1;k<=2;k++)
          z.mp[i][j]=(z.mp[i][j]+p.mp[i][k]*q.mp[k][j]%modd)%modd;
    return z;
}
node f(node x,ll p)
{
	node s=e; 
	while(p!=0)
	{
		if(p%2==1) s=ff(s,x);
		x=ff(x,x);
		p/=2;
	}
	return s;
}
int main()
{
   freopen("c.in","r",stdin);
   freopen("c.out","w",stdout); 
   n=read(),a=read(),b=read();
   e.mp[1][1]=e.mp[2][2]=1;
   c.mp[1][2]=1,c.mp[2][1]=b,c.mp[2][2]=a;
   d.mp[1][1]=0,d.mp[2][1]=1;
   node y=f(c,n); y=ff(y,d);
   int x=y.mp[1][1];
   y=f(c,x); y=ff(y,d);
   printf("%d",y.mp[1][1]);

   fclose(stdin);fclose(stdout);	
 return 0;
}
