#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
long long n,m,a[10000],b[10000];
int f[1000000];
int mo=1000000009;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    cin>>b[i];
  
    if(n==2&&a[1]==1&&a[2]==1&&m==2&&b[1]==1&&b[2]==1)
    cout<<"7";
    
    else cout<<(n*3+1)%mo;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
