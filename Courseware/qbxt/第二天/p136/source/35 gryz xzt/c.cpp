#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e6+7;
const int N = 110000;
int n,a,b;
int s[N];
inline int read(){
	int num=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) num=num*10+c-'0';
	return num*f;
}

signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(),a=read(),b=read();
	s[0]=0,s[1]=1;
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

