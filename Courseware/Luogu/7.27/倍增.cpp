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

int fitst[M],nxt[M],to[M];
int fa[18][M],d[M];

void addedge(){}

void dfs(int x)
{
	for(int i=first[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[0][x])continue;
		d[v]=d[x]+1;
		fa[0][v]=x;
		dfs(v);
	}
}

void build()
{
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++)
		{
			f[j][i]=f[j-1][f[j-1][i]];
		}
}

int query(int u,int v)
{
	if(d[u]>d[v])
		swap(u,v);
	int temp=d[v]-d[u];
	for(int i=17;i>=0;i--)
		if(temp>=(1<<i))v=fa[i][v],temp-=(1<<i);
	for(int i=17;i>=0;i--)
	{
		if(fa[i][v]!=fa[i][u])
			u=fa[i][u],v=fa[i][v];
	}
	return fa[0][v];
}

int main()
{
	n=read(),m=read();
	//...
	dfs(1);
	fa[0][1]=1;
	build();
	return 0;
}
