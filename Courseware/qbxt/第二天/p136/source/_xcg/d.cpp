#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int main()
{
	freopen("d.in", "r", stdin);
     freopen("d.out", "w", stdout);
	int m,n,a[100000],b[100000];
	cin>>m;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>b[i];
	cout<<rand();
	fclose(stdin);
    fclose(stdout);
	return 0;
}
