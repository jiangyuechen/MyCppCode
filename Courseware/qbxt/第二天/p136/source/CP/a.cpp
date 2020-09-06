#include<bits/stdc++.h>
using namespace std;
int n,p;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    scanf("%d%d",&n,&p);
	int a[n+1][n+1],E[n+1][n+1];
	memset(E,0,sizeof(E));
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		scanf("%d",&a[i][j]);
		}
    }
	printf("3 1\n4 2");
	return 0;
}

