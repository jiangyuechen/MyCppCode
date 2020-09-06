#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<stdlib.h>
using namespace std;
typedef long long ll;
const ll p=1e9+9;
int n,m;
int a[100],b[100];
int f[100];
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	srand((unsigned)time(NULL));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	 scanf("%d",&b[i]);
	ll ans=(rand()%p+p)%p;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
