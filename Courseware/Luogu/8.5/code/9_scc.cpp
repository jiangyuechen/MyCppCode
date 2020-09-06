int s[MAXN], stop;
int dfn[MAXN], low[MAXN];
int scccnt, sccnum[MAXN];
int dfscnt;

inline void tarjan(int now){
    dfn[now] = low[now] = ++dfscnt;
    s[stop++] = now;
    for (int i = he[now]; i != 0 ; i = ne[i]){
        if (!dfn[ed[i]]) {
            tarjan(ed[i]);
            low[now] = min(low[now], low[ed[i]]);
        } else if(!sccnum[ed[i]]) {
            low[now] = min(low[now], dfn[ed[i]]);
        }
    }

    if (dfn[now] == low[now]) {
        scccnt++;
        do {
            sccnum[s[--stop]] = scccnt;
        } while(s[stop] != now);
    }
}
