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

int n,m;
ll C[M];

void change(int x,int d)
{
	for(int i=x;i<=n;i+=lowbit(i))
		C[i]+=d;
}

ll query(int x)
{
	if(x==0)return 0;
	ll ret=0;
	for(int i=x;i;i-=lowbit(i))
		ret+=C[i];
	return ret;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		change(i,read());
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		if(a==1)change(b,c);
		else
			printf("%lld\n",query(c)-query(b-1));
	}
	return 0;
}
