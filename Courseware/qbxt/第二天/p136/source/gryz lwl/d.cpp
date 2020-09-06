#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	for(; !isdigit(ch); ch=getchar())
		if(ch=='-')
			f=-1;
	for(; isdigit(ch); ch=getchar())
		x=x*10+ch-'0';
	return x*f;
}
int n,m;
int a[55],b[55];
long long ans;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
		ans+=a[i];
	}
	m=read();
	for(int i=1; i<=m; i++)
	{
		b[i]=read();
		ans+=b[i];
	}
	cout<<ans+n+m-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
1 1
2
1 1
*/
