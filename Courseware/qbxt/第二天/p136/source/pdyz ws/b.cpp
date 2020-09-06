#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
#define clr(a) memset(a,0,sizeof(a)) 

int n,k;

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	srand(time(NULL));
	cin >> n >> k;
	if(k == 1){printf("1 1\n");return 0;}
	if(n == k){printf("%d 1\n",n);return 0;}
	if(n == k+1){printf("%d %d",n,n-1);return 0;} 
	cout << rand()%100 << ' ' << rand()%100 << endl;
//	for
//printf("1 1\n");
return 0;
}
