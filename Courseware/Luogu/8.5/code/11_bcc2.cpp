bool iscut[MAXN];
int dfscnt;
int dfn[MAXN], low[MAXN];

inline void tarjan(int now, int rt) {
    dfn[now] = low[now] = ++dfscnt;
    int chcnt = 0;
    for (int i = he[now]; i; i = ne[i]){
        if (!dfn[ed[i]]) {
            tarjan(ed[i], rt);
            low[now] = min(low[now], low[ed[i]]);
            if (now == rt) chcnt++;
            else if (low[ed[i]] >= dfn[now]) iscut[now] = 1;
        } else {
            low[now] = min(low[now], dfn[ed[i]]);
        }
    }
    if (now == rt && chcnt >= 2) iscut[now] = 1;
}