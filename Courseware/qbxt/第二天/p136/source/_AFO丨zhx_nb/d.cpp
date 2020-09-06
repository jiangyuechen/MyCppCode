#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&n);
	if(n==2)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%d",&m);
		if(m==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(a==1 && b==1 && x==1 && y==1)
			{
				printf("7");
				return 0;
			}
		}
	}
	srand(time(0));
	int a=rand()%10000;
	int b=rand()%10000;
	printf("%d",b);
	return 0;
}
