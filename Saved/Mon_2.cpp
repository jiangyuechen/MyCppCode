#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
const long long MAXN = 200005;
const long long MOD = 998244353;
long long tong[MAXN+1];
long long n;
long long ans;
inline long long read(){
    long long s = 0, w = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
long long C[MAXN][5];
int main(){
    n=read();
    long long _max=-10000000,_maxElement=-10000;
    for(long long i=1,x;i<=n;i++){
        x=read();
        tong[x]++;
        _max=max(_max,x);
        _maxElement=max(_maxElement,tong[x]);
    }
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=1;i<=_maxElement;i++){
        for(int j=0;j<=min(3,i);j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
    for(long long i=1;i<=_max;i++){
        if(tong[i]<2) continue;
        long long f=0;
        for(long long j=1;j<=min(2*i-1,_max);j++){
            if(i==j) continue;
            f+=tong[j];
        }
        ans+=C[tong[i]][2]*f;
        if(tong[i]>2) ans+=C[tong[i]][3];
        ans%=MOD;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}