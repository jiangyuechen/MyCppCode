#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN = 100001;
int sx, sy, fx, fy;
struct circle{
    int x, y;
    int r;
};
inline double dist(int x1,int y1,int x2,int y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
bool judge(circle& c){
    double sn = dist(sx, sy, c.x, c.y);
    double fn = dist(fx, fy, c.x, c.y);
    if(sn>(double)c.r&&fn>(double)c.r)
        return false;
    else if(sn<(double)c.r&&fn<(double)c.r)
        return false;
    else return true;
}
int n;
circle cir[MAXN];
int ans = 0;
int main(){
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n;i++) scanf("%d", &cir[i].x);
    for(int i=1;i<=n;i++) scanf("%d",&cir[i].y);
    for(int i=1;i<=n;i++) scanf("%d",&cir[i].r);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    for (int i = 1; i <= n;i++){
        if(judge(cir[i]))
            ans++;
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}