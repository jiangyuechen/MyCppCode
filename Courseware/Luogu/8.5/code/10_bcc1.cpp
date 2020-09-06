int bcnt;
int bnum[MAXN];
int dfscnt, dfn[MAXN], low[MAXN];
int s[MAXN], stop = 0;

inline void tarjan(int now, int fa) {
    dfn[now] = low[now] = ++dfscnt;
    s[stop++] = now;
    bool flag = false;
    for (int i = he[now]; i; i = ne[i]) {
        Edge &e = ed[i];
        if (e.to == fa && !flag) {
            flag = true;
            continue;
        }
        if (!dfn[e.to]) {
            tarjan(e.to, now);
            low[now] = min(low[now], low[e.to]);
        } else if (!bnum[e.to]) {
            low[now] = min(low[now], dfn[e.to]);
        }
    }
    
    if (low[now] == dfn[now]) {
        ++bcnt;
        do {
           bnum[s[--stop]] = bcnt;
        } while(s[stop] != now); 
    }
}