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
const int MAXN = 1000005;
const bool EQ = true,NO_EQ = false;
int pool[2*MAXN],top;
int n,t;
struct Connection{
    int x,y;
    bool con;
    bool operator<(Connection& oth){
        return con>oth.con;
    }
}c[MAXN];
//UFS
int fa[MAXN];
void init(){
    memset(fa,0,sizeof(fa));
    fill(c+1,c+n+1,(Connection){0,0,0});
    memset(pool,0,sizeof(pool));
}
inline void UFS_prework(int x){
    for(int i=1;i<=x;i++) fa[i]=i;
}
inline int UFS_get(int x){
    if(x==fa[x]) return x;
    else return fa[x]=UFS_get(fa[x]);
}
inline void UFS_merge(int x,int y){
    fa[UFS_get(x)]=UFS_get(y);
}
//
int main(){
    t=read();
    while(t--){
        init();
        n=read();
        for(int i=1;i<=n;i++){
            c[i].x=read();c[i].y=read();c[i].con=read();
            pool[++top]=c[i].x;
            pool[++top]=c[i].y;
        }
        sort(pool+1,pool+top+1);
        int up=unique(pool+1,pool+top+1)-pool;
        for(int i=1;i<=n;i++){
            c[i].x=lower_bound(pool+1,pool+up+1,c[i].x)-pool;
            c[i].y=lower_bound(pool+1,pool+up+1,c[i].y)-pool;
        }
        UFS_prework(up);
        sort(c+1,c+n+1);
        bool ok=true;
        for(int i=1;i<=n;i++){
            if(c[i].con==EQ){
                UFS_merge(c[i].x,c[i].y);
            }
            else{
                if(UFS_get(c[i].x)==UFS_get(c[i].y)){
                    cout<<"NO"<<endl;
                    ok=false;
                    break;
                }
            }
        }
        if(ok) cout<<"YES"<<endl;
    }
    system("pause");
    return 0;
}