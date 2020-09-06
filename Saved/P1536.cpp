#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x,tot,k;
struct point
{
	int x;
	int y;
	int v;
};
point a[9901];
int fat[101];
int father(int x)
{
	if(fat[x]!=x) fat[x]=father(fat[x]);
	return fat[x];
}
void unite(int x,int y)
{
	int fa=father(x);
	int fb=father(y);
	if(fa!=fb) fat[fa]=fb;
}
int cmp(const point& a,const point& b)
{
	return (a.v<b.v);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			if(x!=0)
			{
				m++;
				a[m].x=i;a[m].y=j;a[m].v=x;
			}
		}
	}
	for(int i=1;i<=n;i++) fat[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(father(a[i].x)!=father(a[i].y))
		{
			unite(a[i].x,a[i].y);
			tot+=a[i].v;
			k++;
		}
		if(k==n-1) break;
	}
	cout<<tot;
	return 0;
}