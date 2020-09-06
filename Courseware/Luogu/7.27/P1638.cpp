#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 1000005

int n,m,s,ans,al=1,ar;
int a[M],b[M];

int main()
{
	n=ans=ar=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int l=1,r=0;
	while(r<=n)
	{
		if(s!=m)
		{
			r++;
			if(!b[a[r]])s++;
			b[a[r]]++;
		}
		else
		{
			if(r-l+1<ans)al=l,ar=r,ans=r-l+1;
			if(b[a[l]]==1)s--;
			b[a[l]]--;
			l++;
		}
	}
	printf("%d %d\n",al,ar);
	return 0;
}
