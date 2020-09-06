#pragma region STANDARD
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXM = 2005, MAXN = 2005;
#pragma endregion
int n, m;
struct Graph_no_length
{
    int ver[MAXM], nxt[MAXM], head[MAXN], tot;
    int indgr[MAXN], outdgr[MAXN];

    Graph_no_length()
    {
        memset(ver, 0, sizeof(ver));
        memset(nxt, 0, sizeof(nxt));
        memset(head, 0, sizeof(head));
        memset(indgr, 0, sizeof(indgr));
        memset(outdgr, 0, sizeof(outdgr));
        tot = 0;
    }
    void add_edge(int from, int to)
    {
        outdgr[from]++;
        indgr[to]++;
        ver[++tot] = to;
        nxt[tot] = head[from];
        head[from] = tot;
    }
};
struct String_Graph
{
    int ver[MAXM], nxt[MAXM], head[MAXN], tot;
    int indgr[MAXN], outdgr[MAXN];
    string edge[MAXM];

    String_Graph()
    {
        memset(ver, 0, sizeof(ver));
        memset(nxt, 0, sizeof(nxt));
        memset(head, 0, sizeof(head));
        memset(indgr, 0, sizeof(indgr));
        memset(outdgr, 0, sizeof(outdgr));
        tot = 0;
    }
    void add_edge(int from, int to, string str)
    {
        outdgr[from]++;
        indgr[to]++;
        ver[++tot] = to;
        edge[tot] = str;
        nxt[tot] = head[from];
        head[from] = tot;
    }
};
string str[MAXN];
bool exist[MAXN];
stack<string> stk;

bool visited[MAXN];

void dfs(Graph_no_length &G, int v)
{
    visited[v] = true;
    for (int i = G.head[v]; i; i = G.nxt[i])
    {
        int w = G.ver[i];
        if (!visited[w])
        {
            dfs(G, w);
        }
    }
}

bool judge(Graph_no_length &G)
{
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= 26; i++)
    {
        if (!visited[i])
            dfs(G, i);
    }
    for (int i = 1; i <= 26; i++)
    {
        if ((exist[i]) && (!visited[i]))
            return false;
    }
    return true;
}

void euler(int now)
{
    for (int i = 1; i <= n; i++)
    {
        if (str[i][0] - 'a' + 1 == now && !visited[i])
        {
            visited[i] = 1;
            euler(str[i][str[i].length() - 1] - 'a' + 1);
            stk.push(str[i]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    Graph_no_length G;
    String_Graph S;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
    }
    sort(str + 1, str + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int p = str[i][0] - 'a' + 1, q = str[i][str[i].length() - 1] - 'a' + 1;
        if (!exist[p])
        {
            exist[p] = true;
        }
        if (!exist[q])
        {
            exist[q] = true;
        }
        G.add_edge(p, q);
        G.add_edge(q, p);
        S.add_edge(p, q, str[i]);
    }
    if (!judge(G))
    {
        printf("***\n");
        END_PROGRAM
    }
    int cnt = 0, start = -1;
    for (int i = 1; i <= 26; i++)
    {
        if (!exist[i])
            continue;
        if (abs(S.indgr[i] - S.outdgr[i]) >= 1)
        {
            cnt++;
            if (abs(S.outdgr[i] - S.indgr[i]) > 1)
            {
                printf("***\n");
                END_PROGRAM
            }
            else if (S.outdgr[i] - S.indgr[i] == 1 && start == -1)
            {
                start = i;
            }
        }
    }
    if (cnt != 0 && cnt != 2)
    {
        printf("***\n");
        END_PROGRAM
    }
    memset(visited, 0, sizeof(visited));
    if (cnt == 2)
    {
        euler(start);
    }
    else
    {
        for (int i = 1; i <= 26; i++)
        {
            if (exist[i])
                euler(i);
        }
    }
    bool first = true;
    if (stk.top()[0] == 'o')
    {
        cout << "***" << endl;
        END_PROGRAM
    }
    while (!stk.empty())
    {
        if (!first)
        {
            cout << ".";
        }
        else
            first = false;
        cout << stk.top();
        stk.pop();
    }
    cout << endl;
    END_PROGRAM
}