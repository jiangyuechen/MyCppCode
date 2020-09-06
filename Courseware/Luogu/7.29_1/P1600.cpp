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

struct tree2
{
	tree2 *lson,*rson;
	tree2()
	{
		lson=rson=NULL;
	}
	int x;
}

void merge(tree2 *tree0,tree2 *tree1,int l,int r)
{
	if(tree1==NULL)
	{
		*tree1=*tree0;
		return ;
	}
	if(tree0==NULL)return ;
	if(l==r)
	{
		tree1->x+=tree0->x;
		return ;
	}
	int mid=(l+r)>>1;
	merge(tree0->lson,tree1->lson,l,mid);
	merge(tree0->rson,tree1->rson,mid+1,r);
	//tree1->x=0;
	//if(tree1->lson!=NULL)tree1->x+=tree1->lson->x;
	//if(tree1->rson!=NULL)tree1->x+=tree1->rson->x;
}

int main()
{

	return 0;
}
