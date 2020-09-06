#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 110
#define DEBUG printf("%d %s\n",__LINE__,__FUNCTION__)
#define APART puts("---------------")
#define int long long
using namespace std;

inline int read(){
	char c=getchar();int num=0;bool b=0;
	for(;c<'0'||c>'9';b|=(c=='-'),c=getchar());
	for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+(c^'0'),c=getchar());
	return b?-num:num;
}

int n,p;

struct M{
	int m[inf][inf];
	inline void swapLine(int x,int y){
		for(int i=1;i<=n;i++)
			swap(m[x][i],m[y][i]);
		return;
	}
	inline void mulLine(int x,int k){
		for(int i=1;i<=n;i++)
			m[x][i]=(m[x][i]*k%p+p)%p;
		return;
	}
	inline void addLine(int x,int y,int k){
		for(int i=1;i<=n;i++)
			m[x][i]=((m[x][i]+(m[y][i]*k%p))%p+p)%p;
		return;
	}
};

M a;
M b;

inline int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}

signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();
	p=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a.m[i][j]=read();
	for(int i=1;i<=n;i++)
		b.m[i][i]=1;
	for(int i=1;i<=n;i++){
		if(a.m[i][i]==0){
			for(int j=i+1;j<=n;j++){
				if(a.m[j][i]){
					a.swapLine(i,j);
					b.swapLine(i,j);
					break;
				}
			}
		}
		b.mulLine(i,ksm(a.m[i][i],p-2));
		a.mulLine(i,ksm(a.m[i][i],p-2));
		for(int j=i+1;j<=n;j++){
			b.addLine(j,i,-a.m[j][i]);
			a.addLine(j,i,-a.m[j][i]);
		}
	}
	for(int i=n-1;i;i--){
		for(int j=i+1;j<=n;j++){
			b.addLine(i,j,-a.m[i][j]);
			a.addLine(i,j,-a.m[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%lld ",b.m[i][j]);
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
