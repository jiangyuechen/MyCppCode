#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int N,k;
	scanf("%d%d",&N,&k);
	if(N==k)  printf("%d %d",N,1);
	if(k==N-1) printf("%d %d",N,2);
	else printf("1 1");
	return 0;
}
