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

#define M 5005

struct tree2
{
	tree2 *lson,*rson;
	int mx;
}dizhi[M<<1],*root=&dizhi[0];

int t,n,m,last;

void bulid(tree2 *tree,int l,int r)
{
	if(l==r)
	{
		tree->mx=0;
		return ;
	}
	int mid=(l+r)>>1;
	tree->lson=&dizhi[++t];
	tree->rson=&dizhi[++t];
	bulid(tree->lson,l,mid);
	bulid(tree->rson,mid+1,r);
	tree->mx=0;
}

void change(tree2 *tree,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree->mx=y;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid)change(tree->lson,l,mid,x,y);
	else change(tree->rson,mid+1,r,x,y);
	tree->mx=max(tree->lson->mx,tree->rson->mx);
}

struct scan
{
	int x,h,n;
}a[M<<1];

bool com(scan a,scan b)
{
	return a.x<b.x;
}

int main()
{
	int l,h,r;
	while(scanf("%d%d%d",&l,&h,&r)!=EOF)
	{
		n++;
		a[++m].x=l,a[m].h=h,a[m].n=n;
		a[++m].x=r,a[m].h=-h,a[m].n=n;
	}
	sort(a+1,a+m+1,com);
	bulid(root,1,n);
	for(int i=1;i<=m;i++)
	{
		if(a[i].h>0)change(root,1,n,a[i].n,a[i].h);
		else change(root,1,n,a[i].n,0);
		if(a[i+1].x!=a[i].x)
		{
			if(last!=root->mx)printf("%d %d ",a[i].x,root->mx);
			last=root->mx;
		}
	}
	return 0;
}
