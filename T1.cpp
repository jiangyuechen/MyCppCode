#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
char str[MAXN];
int t,n,c0,c1,h;
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>c0>>c1>>h;
		cin>>str+1;
		int cnt_1=0,cnt_0=0;
		for(int i=1; i<=n; i++) {
			if(str[i]=='0') cnt_0++;
			else cnt_1++;
		}
		int ans = min(cnt_0*c0 + cnt_1 * c1, cnt_1 * h + n * c0);
		ans = min(ans,cnt_0*h+n*c1);
		printf("%d\n",ans);
	}
}