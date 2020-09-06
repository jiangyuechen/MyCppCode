#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 500005
#define lowbit(x) (x&(-x))

int n,m,a[M];
ll C[M];

void change(int x,int d)
{
	for(int i=x;i;i-=lowbit(i))
		C[i]+=d;
}

ll query(int x)
{
	if(x==0)return 0;
	ll ret=0;
	for(int i=x;i<=n;i+=lowbit(i))
		ret+=C[i];
	return ret;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
	{
		int mode=read();
		if(mode==1)
		{
			int a=read(),b=read(),c=read();
			change(b,c);change(a-1,-c);
		}
		else
		{
			int b=read(); 
			printf("%lld\n",query(b)+a[b]);
		}			
	}
	return 0;
}
