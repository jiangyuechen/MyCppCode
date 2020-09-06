#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 305;
int a[MAXN];
int n;
long long ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int now = n,times=1;
    ans+=a[n]*a[n];
    while(times!=n){
        int pre = now;
        if(times%2!=0) now=n-now+1;
        else now = n-now;
        ans+=(a[pre]-a[now])*(a[pre]-a[now]);
        times++;
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}