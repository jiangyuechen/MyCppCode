#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
int n,p,a[101][101];
int main()
{freopen("a.in","r",stdin);
 freopen("a.out","w",stdout);
   scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        {scanf("%d",&a[i][j]);
		}
	for(int i=1;i<=n;i++)
	 {for(int j=1;j<=n;j++)
	 {int k=rand()%p;printf("%d",k);
	 }printf("\n");
	 }
  fclose(stdin);
  fclose(stdout);
}
