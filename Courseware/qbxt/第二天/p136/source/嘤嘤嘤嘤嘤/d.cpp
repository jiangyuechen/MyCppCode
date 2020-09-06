#include<iostream>
#include<cstdio>

using namespace std;
int n;
int a[10000],b[1000];
int main(){

      freopen("d.in","r" , stdin);
	  freopen("d.out", "w" , stdout);
	  cin>>n;

      int maxa=0 , maxb=0 ;

      for(int i=1;i<=n;i++){

      cin>>a[i];

      maxa=max (maxa,a[i]);}

      for(int i=1;i<=n;i++){

      cin>>b[i];

      maxb=max (maxb,b[i]);}

      if ( maxa!=maxb)cout << 0 << endl;
	return 0;
}
