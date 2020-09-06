#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<cstring>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<map>
#define ll long long
#define rint register int
#define ritn register int
#define ull unsigned long long
#define memser memset
#define ture true
#define itn int
using namespace std;

inline ll read(){
	ll f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}

int n,k,K;
int t[55],a[55],b[55],c[55];
int id[55][55];
int cnt[55];
int Type[55];

ll ans=0;

void dfs(int num,int A,int B,int C)
{
	if(num > K)
	{
		ans=max(ans, 1LL*A*B*C);
		return;
	}
	int type=Type[num];
	for(int i=1;i<=cnt[type];++i)
	{
		int v=id[type][i];
		dfs(num+1,A+a[v],B+b[v],C+c[v]);
	}
}

int main()
{
//	freopen("data.in","r",stdin);
//	freopen("std.txt","w",stdout);
	int type;
	n=read();
	k=read();
	
	for(int i=1;i<=n;++i)
	{
		type=read();
		a[i]=read();
		b[i]=read();
		c[i]=read();
		cnt[type]++;
		id[type][cnt[type]]=i;
	}
	
	for(int i=1;i<=k;++i)
	{
		if(cnt[i]==0) continue;
		K++;
		Type[K]=i;
	}
	
	dfs(1,99,99,99);
	
	cout<<ans<<endl;
	return 0;
}


