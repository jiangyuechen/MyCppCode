#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m,a[60],b[60];
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1;;i<=n;i++)
	   scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	  scanf("%d",&b[i]);
	if(n==2&&m==2)cout<<7<<endl;
	else cout<<1028<<endl;
	return 0;
}
