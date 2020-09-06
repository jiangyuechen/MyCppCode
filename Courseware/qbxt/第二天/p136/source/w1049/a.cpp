#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define LL long long
#define R register
using namespace std;
int p;
int tmp,n;
struct Matrix {
	const static int MAXSIZE=100;
	int data[MAXSIZE+1][MAXSIZE+1];
	int* operator[](int x) {
		return data[x];
	}
	Matrix(int opt=0) {
		memset(data,0,sizeof(data));
		if(opt)
			for(R int i=1; i<=n; i++)
				data[i][i]=1;
	}
	//Swap
	void S(int a,int b) {
		swap(data[a],data[b]);
	}
	//Mul and Add
	void M(int a,int b,int val) {
		for(R int i=1; i<=n; i++)
			(data[b][i]+=1ll*data[a][i]*val%p+p)%=p;
	}
	//Mul
	void M(int a,int val) {
		for(R int i=1; i<=n; i++)
			data[a][i]=1ll*data[a][i]*val%p;
	}
};
inline int inv(int a) {
	LL base=a,res=1;
	int b=p-2;
	while(b) {
		if(b&1)res=res*base%p;
		base=base*base%p;
		b>>=1;
	}
	return res;
}
inline void read(int &x) {
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
}
void print(int x) {
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(n),read(p);
	Matrix A(0),B(1);
	for(R int i=1; i<=n; i++)
		for(R int j=1; j<=n; j++)
			read(A[i][j]);
	for(R int i=1; i<=n; i++) {
		int maxl=i;
		for(R int j=i+1; j<=n; j++)
			if(abs(A[j][i])>abs(A[maxl][i]))maxl=j;
		if(maxl!=i)
			A.S(maxl,i),B.S(maxl,i);
		for(R int k=i+1; k<=n; k++) {
			tmp=1ll*A[k][i]*inv(A[i][i])%p;
			A.M(i,k,-tmp);
			B.M(i,k,-tmp);
		}
	}
	for(R int i=n; i>=1; i--) {
		for(R int j=i+1; j<=n; j++) {
			B.M(j,i,-A[i][j]);
			A.M(j,i,-A[i][j]);
		}
		tmp=inv(A[i][i]);
		A.M(i,tmp);
		B.M(i,tmp);
	}
	for(R int i=1; i<=n; i++) {
		for(R int j=1; j<=n; j++)
			print(B[i][j]),putchar(' ');
		putchar('\n');
	}
	return 0;
}
