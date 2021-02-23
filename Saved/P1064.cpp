#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXM = 32010;
int zhu_cost[MAXM], zhu_value[MAXM], zhu_fu_cnt[MAXM];
int fu_cost[MAXM][3], fu_value[MAXM][3];
int f[MAXM];
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int v, p, q;
        scanf("%d%d%d", &v, &p, &q);
        if (q == 0) {
            zhu_cost[i] = v;
            zhu_value[i] = v * p;
        } else {
            zhu_fu_cnt[q]++;
            fu_cost[q][zhu_fu_cnt[q]] = v;
            fu_value[q][zhu_fu_cnt[q]] = v * p;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 0; j--) {
            if (j >= zhu_cost[i])
                f[j] = max(f[j], f[j - zhu_cost[i]] + zhu_value[i]);
            if (j >= zhu_cost[i] + fu_cost[i][1])
                f[j] = max(f[j], f[j - zhu_cost[i] - fu_cost[i][1]] + zhu_value[i] + fu_value[i][1]);
            if (j >= zhu_cost[i] + fu_cost[i][2])
                f[j] = max(f[j], f[j - zhu_cost[i] - fu_cost[i][2]] + zhu_value[i] + fu_value[i][2]);
            if (j >= zhu_cost[i] + fu_cost[i][1] + fu_cost[i][2])
                f[j] = max(f[j], f[j - zhu_cost[i] - fu_cost[i][1] - fu_cost[i][2]] + zhu_value[i] + fu_value[i][1] + fu_value[i][2]);
        }
    }
    printf("%d\n", f[n]);
    // system("pause");
}