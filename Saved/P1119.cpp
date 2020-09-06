#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 205, MAXQ = 50005;
int a[MAXN][MAXN];
int n, m, q;
int x[MAXQ], y[MAXQ], t[MAXQ];
int repair[MAXN];
bool made[MAXN];
//思路借鉴：@秋日私语
int main() {
    memset(a, 0x3f, sizeof(a));
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;i++) {
        a[i][i]=0;
        scanf("%d", &repair[i]);
    }
    for (int i=1;i<=m;i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        a[x][y]=a[y][x]=w;
    }
    scanf("%d", &q);
    for (int i=1;i<=q;i++) {
        scanf("%d%d%d", &x[i], &y[i], &t[i]);
    }
    for (int p=1;p<=q;p++) {
        for (int k=0;k<n;k++) {
            if (t[p]>=repair[k] && !made[k]) {
                made[k]=true;
                for (int i=0;i<n;i++) {
                    for (int j=0;j<n;j++) {
                        if (a[i][j]>a[i][k]+a[k][j]&&i!=k&&i!=j&&k!=j) {
                            a[i][j]=a[i][k]+a[k][j];
                        }
                    }
                }
            }
        }
        if (t[p]>=repair[x[p]] && t[p]>=repair[y[p]] && a[x[p]][y[p]]!=0x3f3f3f3f) {
            printf("%d\n", a[x[p]][y[p]]);
        }
        else {
            printf("-1\n");
        }
    }
    system("pause");
    return 0;
}