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

#define M 200005

struct tree2 
{
	tree2 *lson,*rson;
	int x;
}dizhi[M<<5],*root[M];

int t,n,m,y[M];

void bulid(tree2 *tree,int l,int r)
{
	if(l==r)
	{
		tree->x=0;
		return ;
	}
	int mid=(l+r)>>1;
	tree->lson=&dizhi[++t];
	tree->rson=&dizhi[++t];
	bulid(tree->lson,l,mid);
	bulid(tree->rson,mid+1,r);
	tree->x=0; 
}

void insert(tree2 *last,tree2 *tree,int l,int r,int x)
{
	if(l==r)
	{
		tree->x=last->x+1;
		return ;
	}
	int mid=(l+r)>>1;
	*tree=*last;
	if(x<=mid)
	{
		tree->lson=&dizhi[++t];
		insert(last->lson,tree->lson,l,mid,x);
	}
	else
	{
		tree->rson=&dizhi[++t];
		insert(last->rson,tree->rson,mid+1,r,x);
	}
	tree->x=tree->lson->x+tree->rson->x;
}

int query(tree2 *ltree,tree2 *rtree,int l,int r,int x)
{
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	int temp=rtree->lson->x-ltree->lson->x;
	if(x<=temp)return query(ltree->lson,rtree->lson,l,mid,x);
	else return query(ltree->rson,rtree->rson,mid+1,r,x-temp);
}

struct dis
{
	int n,a,k;
}a[M];

bool com1(dis a,dis b)
{
	return a.a<b.a;
}

bool com2(dis a,dis b)
{
	return a.n<b.n;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i].a=read(),a[i].n=i;
	sort(a+1,a+n+1,com1);
	int st=0;
	for(int i=1;i<=n;i++)
	{
		a[i].k=++st;
		y[st]=a[i].a;
		while(a[i].a==a[i+1].a)a[++i].k=st;
	}
	sort(a+1,a+n+1,com2);
	for(int i=0;i<=n;i++)root[i]=&dizhi[++t];
	bulid(root[0],1,n);
	for(int i=1;i<=n;i++)
		insert(root[i-1],root[i],1,n,a[i].k);
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read(),k=read();
		int temp=query(root[l-1],root[r],1,n,k);
		printf("%d\n",y[temp]);
	}
	return 0;
}
