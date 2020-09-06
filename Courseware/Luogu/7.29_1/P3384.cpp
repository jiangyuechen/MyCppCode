#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define MAXINT 2147482647LL
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

struct tree2
{
	tree2 *lson,*rson;
	int lazy,x;
}dizhi[M<<1],*root=&dizhi[0];

int t,P,n,m,a[M],y[M];

void bulid(tree2 *tree,int l,int r)
{
	if(l==r)
	{
		tree->x=a[y[l]];
		return ;
	}
	int mid=(l+r)>>1;
	tree->lson=&dizhi[++t];
	tree->rson=&dizhi[++t];
	bulid(tree->lson,l,mid);
	bulid(tree->rson,mid+1,r);
	tree->x=((ll)tree->lson->x+tree->rson->x)%P;
}

void pushdown(tree2 *tree,int l,int r)
{
	if(tree->lazy==0)return ;
	int mid=(l+r)>>1;
	tree->lson->x=((ll)tree->lson->x+(ll)(mid-l+1)*tree->lazy)%P;
	tree->rson->x=((ll)tree->rson->x+(ll)(r-mid)*tree->lazy)%P;
	tree->lson->lazy+=tree->lazy;
	tree->rson->lazy+=tree->lazy;
	tree->lazy=0;
}

void change(tree2 *tree,int l,int r,int x,int y,int k)
{
	if(x<=l&&y>=r)
	{
		tree->x=((ll)tree->x+(ll)(r-l+1)*k)%P;
		tree->lazy+=k;
		return ;
	}
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)change(tree->lson,l,mid,x,y,k);
	if(y>mid)change(tree->rson,mid+1,r,x,y,k);
	tree->x=((ll)tree->lson->x+tree->rson->x)%P;
}

int query(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
	{
		return tree->x;
	}
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	int t1=0,t2=0;
	if(x<=mid)t1=query(tree->lson,l,mid,x,y);
	if(y>mid)t2=query(tree->rson,mid+1,r,x,y);
	return ((ll)t1+t2)%P;
}

int first[M],next[M<<1],to[M<<1],fa[M],tt;

void addedge(int s,int v)
{
	next[++tt]=first[s];
	first[s]=tt;
	to[tt]=v;
}

int s[M],w[M],d[M],top[M],l[M],r[M],cnt,R;

void dfs1(int x)
{
	s[x]=1;
	for(int i=first[x];i;i=next[i])
	{
		int v=to[i];
		if(v==fa[x])continue;
		fa[v]=x;
		d[v]=d[x]+1;
		dfs1(v);
		s[x]+=s[v];
		if(s[v]>s[w[x]])w[x]=v;
	}
}

void dfs2(int x,int tp)
{
	top[x]=tp;
	l[x]=++cnt;
	y[cnt]=x;
	if(w[x])dfs2(w[x],tp);
	for(int i=first[x];i;i=next[i])
	{
		int v=to[i];
		if(v==fa[x]||v==w[x])continue;
		dfs2(v,v);
	}
	r[x]=cnt;
}

int change(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])swap(x,y);
		change(root,1,n,l[top[x]],l[x],k);
		x=fa[top[x]];
	}
	if(d[x]<d[y])swap(x,y);
	change(root,1,n,l[y],l[x],k);
}

int query(int x,int y)
{
	int ret=0;
	while(top[x]!=top[y])
	{
		if(d[top[x]]<d[top[y]])swap(x,y);
		ret=((ll)ret+query(root,1,n,l[top[x]],l[x]))%P;
		x=fa[top[x]];
	}
	if(d[x]<d[y])swap(x,y);
	ret=((ll)ret+query(root,1,n,l[y],l[x]))%P;
	return ret;
}

int main()
{
	n=read();m=read();R=read(),P=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		addedge(a,b);addedge(b,a);
	}
	dfs1(R);
	dfs2(R,R);
	bulid(root,1,n);
	for(int i=1;i<=m;i++)
	{
		int c=read();
		if(c==1)
		{
			int x=read(),y=read(),z=read();
			change(x,y,z);
		}
		if(c==2)
		{
			int x=read(),y=read();
			printf("%d\n",query(x,y));
		}
		if(c==3)
		{
			int x=read(),z=read();
			change(root,1,n,l[x],r[x],z);
		}
		if(c==4)
		{
			int x=read();
			printf("%d\n",query(root,1,n,l[x],r[x]));
		}
	}
	return 0;
}
