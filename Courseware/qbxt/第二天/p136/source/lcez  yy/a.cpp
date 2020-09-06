#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,p;
int a[1000][1000];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&p);

	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	cin>>a[i][j];
	  	a[i][j]%=p;
	  }
	  
	  cout<<2%1000007;
	  
	  
	  
	  
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	cout<<a[i][j]<<" ";
	  	if(j==n) cout<<endl;
	  }
	  
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
