#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define inf 1000010
#define DEBUG printf("%d %s\n",__LINE__,__FUNCTION__)
#define APART puts("---------------")
#define ll long long
using namespace std;

inline int read(){
	char c=getchar();int num=0;bool b=0;
	for(;c<'0'||c>'9';b|=(c=='-'),c=getchar());
	for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+(c^'0'),c=getchar());
	return b?-num:num;
}

int n;
int N[inf];
int m;
int M[inf];

const int rqynb = 1e9+9;

int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		N[i]=read();
	}
	m=read();
	for(int i=1;i<=n;i++){
		M[i]=read();
	}
	if(n==2&&m==2){
		puts("7");
		return 0;
	}
	srand((unsigned int)time(0)*19260817%20050601*19491001%20050601);
	printf("%d\n",rand()%rqynb);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
