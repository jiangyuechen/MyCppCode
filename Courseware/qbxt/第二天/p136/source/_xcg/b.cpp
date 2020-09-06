#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("b.in", "r", stdin);
     freopen("b.out", "w", stdout);
	int n,k
	cin>>n>>k;
	if(k==1) {cout<<"1 1";return 0;}
	if(n==k) {cout<<k<<" 1";return 0;}
	if(k==2) {cout<<k<<" "<<n;}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
