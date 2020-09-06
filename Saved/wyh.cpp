#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 100001;
int ver[MAXN],nxt[MAXN],head[MAXN],tot;
void add_edge(int u,int v){
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}
//tarjan
int n,m,s,num,cnt,top,ins[MAXN],c[MAXN],dfn[MAXN],low[MAXN];
bool ishouse[MAXN];
bool scchouse[MAXN];
stack<int> st;
vector<int> scc[MAXN];
void tarjan(int x){
    dfn[x]=low[x]=++num;
    st.push(x);
    ins[x]=1;
    for(int i=head[x];i;i=nxt[i]){
        int y=ver[i];
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(ins[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x]){
        cnt++;
        scchouse[cnt] = ishouse[x];
        while(!st.empty()){
            int now=st.top();
            st.pop();
            ins[now]=0;
            c[now]=cnt;
            scc[cnt].push_back(now);
        }
    }
}
//tarjan
int sccver[MAXN],sccnxt[MAXN],scchead[MAXN],scctot;
void scc_add_edge(int x,int y){
    sccver[++scctot] = y;
    sccnxt[scctot]=scchead[x];
    scchead[x] = scctot;
}
//
//Hungary Algorithm
bool visit[MAXN];
int match[MAXN];
bool dfs(int x){
    for (int i = scchead[x]; i;i=sccnxt[i]){
        int y = sccver[i];
        if(!visit[y]){
            visit[y] = true;
            if(!match[y]||dfs(match[y])){
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
//
int main(){
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m;i++){
        int x;
        scanf("%d", &x);
        ishouse[x] = true;
    }
    for (int i = 1; i <= n;i++){
        int x;
        scanf("%d", &x);
        ishouse[x] = false;
    }
    for (int i = 1; i <= s;i++){
        int x,y;
        scanf("%d%d", &x, &y);
        add_edge(x, y);
    }
    for (int i = 1; i <= n + m;i++){
        if(!dfn[i])
            tarjan(i);
    }
    for (int x = 1; x <= n + m;x++){
        for (int i = head[x]; i;i=nxt[i]){
            int y=ver[i];
            if(c[x]==c[y]||scchouse[c[x]]==scchouse[c[y]])
                continue;
            scc_add_edge(c[x], c[y]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= scctot;i++){
        memset(visit, 0, sizeof(visit));
        if(dfs(i))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}