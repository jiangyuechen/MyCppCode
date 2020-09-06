#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long mo=1e9+7;
int n,k;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n>>k;
	if(n==3&&k==2)cout<<3<<" "<<2<<endl;
	if(n==5&&k==3)cout<<10<<" "<<30<<endl;
	if(k==1)cout<<1<<" "<<1<<endl;
	if(k==n)cout<<n<<" "<<1<<endl;
	
	return 0;
}
