#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
typedef long long ll;

const int MAXN = 5005;

typedef pair<ll, ll> point;

ll getDistance(point& a, point& b) {
    return (a.second-b.second)*(a.second-b.second)+(a.first-b.first)*(a.first-b.first);
}

point p[MAXN];

ll dist[MAXN];
bool vis[MAXN];
int n;
double ans;

void prim() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, false, sizeof vis);
    dist[1]=0;
    for (int i=1;i<=n;i++) {
        int x=0;
        for (int j=1;j<=n;j++) {
            if (!vis[j]&&(x==0||dist[j]<dist[x])) x=j;
        }
        vis[x]=true;
        for (int y=1;y<=n;y++) {
            if (!vis[y]) dist[y]=min(dist[y], getDistance(p[x], p[y]));
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%lld%lld", &p[i].first, &p[i].second);
    }
    prim();
    for (int i=2;i<=n;i++) ans+=sqrt(dist[i]);
    printf("%.2lf\n", ans);
    system("pause");
    return 0;
}