#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = 1e6+7;

#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
#define clr(a) memset(a,0,sizeof(a)) 

struct matrix{
	ll a[3][3];
};

matrix operator *(matrix a,matrix b){
	matrix c;
	rep(i,1,2)rep(j,1,2){
		c.a[i][j] = 0;
		rep(k,1,2)c.a[i][j] += a.a[i][k]*b.a[k][j];
		c.a[i][j]%=mod;
	}
	return c;
}

matrix pow(matrix a,int b){
	matrix ans;
	rep(i,1,2)rep(j,1,2)ans.a[i][j] = (i==j)?1:0;
	while(b){
		if(b&1)ans = ans*a;
		a = a*a;
		b>>=1;
	}
	return ans;
}

ll n;
matrix a,b;

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	a.a[1][1] = 0,a.a[1][2] = 1;
	cin >> n >> a.a[2][2] >> a.a[2][1];
	n = pow(a,n).a[1][2];
	
//	rep(i,1,2){
//		rep(j,1,2)cout << a.a[i][j] << ' ';
//		cout << endl;
//	}
	
	printf("%lld",pow(a,n).a[1][2]);	
return 0;
}
