#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+10;
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
int n,k;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read(),k=read();
	if(n==k)
	{
		cout<<n<<" "<<1;
		return 0;
	}
	if(k==1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	if(k==2)
	{
		cout<<n<<" "<<n-1;
		return 0;
	}
	if(n-1==k)
	{
		cout<<n<<" "<<2;
		return 0;
	}
	cout<<n<<" "<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
