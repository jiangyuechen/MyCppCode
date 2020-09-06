#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int a,b;
	b=n/k;
	if(n%k!=0){
		b++;
	}
	a=n;
	printf("%d %d",a%1000000007,b%1000000007);
	return 0;
}
