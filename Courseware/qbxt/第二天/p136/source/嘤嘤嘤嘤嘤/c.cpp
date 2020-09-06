#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cstring"
#include "string"
#include "cmath"
#define int long long
using namespace std;

const int p = 1e6+7;
int n,a,b;

struct matrix{
	int a[4][4] = {};
	void print(){
		for(int i = 0;i < 2; i++){
			for(int j = 0;j < 2; j++){
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
	} 
}in,e;

matrix operator *(matrix &a,matrix &b){
		matrix c;
		for(int i = 0;i < 2; i++){
			for(int j = 0;j < 2; j++){
				for(int k = 0;k < 2; k++){
					(c.a[i][j] += a.a[i][k] * b.a[k][j] %p) %=p;
				}
			}
		}
		return c;
}

matrix mul(matrix a,matrix b){
	matrix c;
//	int p = 1e6+7;
	for(int i = 0;i < 2; i++){
		for(int j = 0;j < 2; j++){
				for(int k = 0;k < 2; k++){
				(c.a[i][j] += a.a[i][k] * b.a[k][j] %p) %=p;
			}
		}
	}
	return c;
}

matrix Pow(matrix a,int x){
	matrix tot = e;
	while(x){
		if(x & 1) tot = a * tot;
		a = a * a;
		x >>= 1;
	}
	return tot;
}

matrix Pow2(matrix a,int x){
	matrix tot = e;
//	int mod = 1e6+7;
	while(x){
		if(x & 1) tot = mul(a,tot);//a * tot;
		a = mul(a,a);
		x >>= 1;
	}
	return tot;
}

signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	cin >> n >> a >> b; 
	
	e.a[0][0] = 0;
	e.a[1][0] = 0;
	e.a[0][1] = 1;
	
	in.a[0][0] = 0; in.a[0][1] = b;
	in.a[1][0] = 1; in.a[1][1] = a;
	
//	in.print();
//	e.print();

	matrix qwq = Pow(in,n);
//	qwq.print();//到这里就求出了第一层的f(x)
	int x = qwq.a[1][1];
//	cout << x << endl;
	
	qwq = Pow(in,x);
//	qwq.print();
	cout << qwq.a[1][1] << endl;
	return 0;
}
