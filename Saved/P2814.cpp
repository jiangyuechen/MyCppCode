#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10001;
int n;
int fa[MAXN];
string name[MAXN];
inline void UFS_prework(){
    for(int i=1;i<=n;i++) fa[i]=i;
}
inline int UFS_get(int x){
    if(x==fa[x]) return x;
    else return fa[x]=UFS_get(fa[x]);
}
inline void UFS_merge(int x,int y){
    fa[UFS_get(x)]=UFS_get(y);
}
int main(){
    UFS_prework();
    char op;
    cin>>op;
    while(op!='$'){
        cin>>
    }
    system("pause");
    return 0;
}