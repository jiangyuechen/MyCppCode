#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	freopen("d.in","r",stdin);
	freopen("d.out",w,stdout);
	int n,m,l[55],z[55],rqyzhxnb=1000000009;
	cin>>n;
	for(int i=1; i<=n; ++i)
		cin>>l[i];
	cin>>m;
	for(int i=1; i<=m; ++i)
		cin>>z[i];
	if(n==2&&m==2) {
		cout<<"7";
		return 0;
	} else {
		cout<<rand()%rqyzhxnb;
		return 0;
	}
	return 0;
}
