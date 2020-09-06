#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=100000; ++i)
		for(int j=1; j<=10000; ++j) {
			if(k*i>j&&(k-1)*i<j) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	return 0;
}
