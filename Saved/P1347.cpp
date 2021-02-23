#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int OK = 0, INCONSISTENCY = 1, UNDETERMINED = -1;
const int MAXN = 1005;
int n, m;

struct edge {
    int to, nxt;
} e[MAXN];
int head[MAXN], top;
int real_indgr[MAXN], real_outdgr[MAXN];
bool connected[MAXN][MAXN];
void add_edge(int a, int b) {
    connected[a][b] = true;
    // printf("added: %d -> %d\n", a, b);
    e[++top].to = b;
    e[top].nxt = head[a];
    head[a] = top;
    real_indgr[b]++;
    real_outdgr[a]++;
}

namespace Toposort {
    int f[MAXN];
    int start;
    int temp_indgr[MAXN], temp_outdgr[MAXN];
    void Reset() {
        memset(f, 0, sizeof(f));
        memset(temp_indgr, 0, sizeof(temp_outdgr));
        memset(temp_outdgr, 0, sizeof(temp_outdgr));
        start = 0;
        for (int i = 1; i <= n; i++) {
            temp_indgr[i] = real_indgr[i];
            temp_outdgr[i] = real_outdgr[i];
        }
    }
    int Topo() {
        queue<int> q;
        int sum = 0;
        int zero_indgr_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (temp_indgr[i] == 0) {
                q.push(i);
                start = i;
                zero_indgr_cnt++;
            }
        }
        bool flag = zero_indgr_cnt > 1;
        // if (zero_indgr_cnt > 1) return UNDETERMINED;
        zero_indgr_cnt = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            sum++;
            for (int i = head[x]; i; i = e[i].nxt) {
                int y = e[i].to;
                f[x] = y;
                temp_indgr[y]--;
                if (!temp_indgr[y]) {
                    q.push(y);
                    zero_indgr_cnt++;
                }
            }
            if (zero_indgr_cnt > 1) flag = true;
            zero_indgr_cnt = 0;
        }
        // if (sum != n) return INCONSISTENCY;
        for (int i = 1; i <= n; i++) {
            if (temp_indgr[i]) return INCONSISTENCY;
        }
        if (flag) return UNDETERMINED;
        return OK;
    }
}  // namespace Toposort

signed main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        char opt[5];
        scanf("%s", opt + 1);
        if (connected[opt[1] - 'A' + 1][opt[3] - 'A' + 1]) continue;
        if (opt[1] == opt[3]) {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }
        add_edge(opt[1] - 'A' + 1, opt[3] - 'A' + 1);
        Toposort::Reset();
        int result = Toposort::Topo();
        if (result == UNDETERMINED)
            continue;
        else if (result == INCONSISTENCY) {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        } else {
            printf("Sorted sequence determined after %d relations: ", i);
            int now = Toposort::start;
            while (now != 0) {
                printf("%c", now + 'A' - 1);
                now = Toposort::f[now];
            }
            puts(".");
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}