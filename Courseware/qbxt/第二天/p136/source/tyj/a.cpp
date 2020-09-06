#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define C getchar()-48

inline ll read() {
    ll s = 0,r = 1;
    char c = C;
    for (;c < 0  ||  c > 9;c = C) if (c == -3) r = -1;
    for (;c >= 0  &&  c <= 9;c = C) s = (s<<3)+(s<<1)+c;
    return s*r;
}

const ll N = 410;
int p;
ll n;

struct xin {
    ll a[N][N];
    inline void swap(int x,int y){for(int i=1;i<=n;i++) swap(a[x][i],a[y][i]);}
    inline void mul(int x,int k){for(int i=1;i<=n;i++) a[x][i]=(a[x][i]*k%p+p)%p;}
    inline void add(int x,int y,int k){for(int i=1;i<=n;i++) a[x][i]=((a[x][i]+a[y][i]*k)%p+p)%p;}
    inline void prt() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) printf("%lld ",a[i][j]);
            printf("\n");
        }
    }
}a,b;

inline ll ksm(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b&1) ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}

void gaosi() {
    for(int i=1;i<=n;i++) {
        if(!a.a[i][i]) for(int j=i+1;j<=n;j++) if(a.a[j][i]) {
            a.swap(i,j);b.swap(i,j);
            break;
        }
        if(!a.a[i][i]){printf("No Solution\n");exit(0);}
        b.mul(i,ksm(a.a[i][i],p-2));a.mul(i,ksm(a.a[i][i],p-2));
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            b.add(j,i,-a.a[j][i]);a.add(j,i,-a.a[j][i]);
        }
    }
}

int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    n=read(),p=read();
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      a.a[i][j]=read();
    for(int i=1;i<=n;i++) b.a[i][i]=1;
    gaosi();
    b.prt();
    return 0;
}
