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

#define M 100005
#define lowbit(x) (x&(-x))

int n,m,a[M];
ll C[M],D[M];

void change(ll *C,int x,ll d)
{
	for(int i=x;i<=n;i+=lowbit(i))
		C[i]+=d;
}

ll query(ll *C,int x)
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
	{
		a[i]=read();
		change(C,i,a[i]-a[i-1]);
		change(D,i,(ll)(i-1)*(a[i]-a[i-1]));
	}
	for(int i=1;i<=m;i++)
	{
		int mode=read();
		if(mode==1)
		{
			int a=read(),b=read(),c=read();
			change(C,a,c);change(C,b+1,-c);
			change(D,a,(ll)(a-1)*c);change(D,b+1,(ll)-b*c);
		}
		else
		{
			int a=read(),b=read();
			ll t1=query(C,a-1)*(a-1)-query(D,a-1);
			ll t2=query(C,b)*b-query(D,b);
			printf("%lld\n",t2-t1);
		}
	}
	return 0;
}
