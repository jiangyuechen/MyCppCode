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
const int MAXN = 5000005;
int a[MAXN];
int n,k;
int main(){
    n=read();k=read();
    for(int i=0;i<n;i++) a[i]=read();
    nth_element(a,a+k,a+n);
    printf("%d\n",a[k]);
    //system("pause");
    return 0;
}