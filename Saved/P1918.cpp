#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
    int s = 0, w = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
const int MAXN = 100001;
struct Baoling{
    int order;
    int value;
}a[MAXN];
bool cmp(Baoling a,Baoling b){
    return a.value<b.value;
}
int n,t;
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i].value=read();
        a[i].order=i;
    }
    t=read();
    while(t--){
        int x;
        x=read();
        Baoling ans;
        ans.order=0;
        ans.value=x;
        cout<<upper_bound(a+1,a+n+1,ans);
    }
    return 0;
}