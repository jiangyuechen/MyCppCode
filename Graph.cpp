#include <cstring>
#include <map>
#define __TEMP
template <int vertexNum, int edgeNum>
class Graph_no_length
{
private:
    int ver[edgeNum], nxt[edgeNum], head[vertexNum], tot;

public:
    Graph_no_length()
    {
        memset(ver, 0, sizeof(ver));
        memset(nxt, 0, sizeof(nxt));
        memset(head, 0, sizeof(head));
        tot = 0;
    }
    void add_edge(int from, int to)
    {
        ver[++tot] = to;
        nxt[tot] = head[from];
        head[from] = tot;
    }
};
