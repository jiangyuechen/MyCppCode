#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 5005;
int n, m, x, y;
char opt;
int fa[MAXN];
bool enemy[MAXN][MAXN];
/*
    solution:
    1.是朋友：并查集直接合并
    2.是敌人：如果x,y是敌人，y,z是敌人，那么x,z是朋友。
    出现敌人(x,y)时扫描所有人z即可。
*/
inline void UFS_prework()
{
    for (int i=1;i<=n;i++) fa[i]=i;
}
inline int UFS_get(int x)
{
    if (x==fa[x]) return x;
    else return fa[x]=UFS_get(fa[x]);
}
inline void UFS_merge(int x, int y)
{
    fa[UFS_get(x)]=UFS_get(y);
}
int ans;
int main()
{
    cin>>n>>m;
    memset(enemy, 0, sizeof(enemy));
    UFS_prework();
    for (int i=1;i<=m;i++) {
        cin>>opt>>x>>y;
        if (opt=='F') UFS_merge(x, y);
        else {
            enemy[x][y]=enemy[y][x]=true;
            for (int i=1;i<=n;i++) {
                if (enemy[x][i]) UFS_merge(y, i);
                if (enemy[y][i]) UFS_merge(x, i);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (fa[i]==i) ans++;
    }
    cout<<ans<<endl;
    END_PROGRAM
}