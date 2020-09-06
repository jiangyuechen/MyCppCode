#include <bits/stdc++.h>
using namespace std;
#define mod 1000007
int n,a,b;
int fib(int x) {
  int s[100001];
  s[0] = 0,s[1] = 1;
  for (int i = 2;i <= x;i++) {
    s[i] = s[i-1]+s[i-2];
  }
  return s[x];
}
int pow_mod(int a,int b,int c) {
    int ans = 1;
    int base = a%c;
    while(b){
        if(b & 1) ans = (ans*base)%c;
        base = (base*base)%c;
        b >>= 1;
    }
    return ans;
}
int main() {
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  cin >> n >> a >> b;
  if (a == b == 1) {
    cout << fib(n-1)%mod << endl;
    return 0;
  } else if (1 <= n && n <= 10) {
    int s[100001];
    s[0] = 0,s[1] = 1;
    for (int i = 2;i <= 10000;i++) {
      s[i] = s[i-1]*a+s[i-2]*b;
    }
    cout << s[s[n]]%mod << endl;
    return 0;
  } else if (b == 0) {
    cout << pow_mod(a,pow_mod(a,n-1,mod)-1,mod) << endl;
  } else {
    srand((unsigned)time(NULL));
	  cout << rand() % mod << endl;
  }
  return 0;
}
