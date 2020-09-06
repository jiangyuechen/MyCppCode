#include<iostream>
using namespace std;
int a,b;
int main(){	
	cin>>a>>b;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	if(a%2) cout<<a<<" "<<b;
	else cout<<b<<" "<<a;
	return 0;
}
