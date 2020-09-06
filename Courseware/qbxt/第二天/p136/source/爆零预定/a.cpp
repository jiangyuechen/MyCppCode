#include <cstdio>
#include <algorithm>
#include<bits/stdc++.h>
#include <cctype>
long long  mod;

int n,a[410][410];
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
#define mul(a,b) (1ll*(a)*(b)%mod)
int qp(int d,int k){int f=1;while(k){if(k&1)f=mul(f,d);d=mul(d,d),k>>=1;}return f;}
int read()
{
    int x=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    return x;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    n=read();
    scanf("%d",&mod);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            a[i][j]=read();
        a[i][i+n]=1;
    }
    for(int i=1;i<=n;i++)
    {
        int id=-1;
        for(int j=i;j<=n;j++) if(a[j][i]) {id=j;break;}
        
        std::swap(a[i],a[id]);
        int inv=qp(a[i][i],mod-2);
        for(int j=i;j<=n<<1;j++) a[i][j]=mul(a[i][j],inv);
        for(int j=i+1;j<=n;j++)
            for(int k=n<<1;k>=i;k--)
                a[j][k]=add(a[j][k],mod-mul(a[i][k],a[j][i]));
    }
    for(int i=n;i;i--)
        for(int j=i-1;j;j--)
            for(int k=n<<1;k>=i;k--)
                a[j][k]=add(a[j][k],mod-mul(a[i][k],a[j][i]));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[i][j+n]);
        puts("");
    }
    return 0;
}
