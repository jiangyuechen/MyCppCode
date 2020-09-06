#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
/*
*  @brief 大体思路：
*  	@param 1.由于二维坐标直接连边比较困难（当然不排除许多巨佬直接二维连边爆切此题），所以可以转化成一维。
*		以下注释称转化成一维的坐标为“真实数字”。
*  	@param 2.以含有人最多的铁轨为“Tmax”，将人数不足Tmax的铁轨后面补上一些C=0的人。形成优美的矩形结构（具体见图）。
*  	@param 3.计算前缀和（基于真实数字），方便之后使用。
*  	@param 4.通过转化后的点来连边。为了计算两个相邻岔道的端点之间C的总值（即边权），使用前缀和。
*		一条铁轨的第一个岔道端点向起点连边，最后一个岔道端点向终点连边。
*  	@param 5.使用SPFA跑最长路。
*  @brief 时间复杂度（以下的N为总人数（但题目中表示铁轨数，可以理解为题目中的T*N）,M为岔道数）：
*   @param 1.计算前缀和：O(N)；
*   @param 2.连边（最坏情况，假设每个人的正后方都有铁轨）：O(N+M)；
*	@param 3.跑最长路：O(K(N+M))(数据均随机，K约等于2)。
*/
#pragma region PREPARATION
using namespace std;
const int MAXEDGE = 5000001;															  //最大边数。如果每个人之间都有岔路，那么它的最大值就是sum(T[i]).
const int MAXPOINT = 5000001;															  //最大点数（即最大人数，显然是sum(T[i])）
const int MAXPATH = 1001;																  //最大岔道数
const int _ST_TO_FN = 0 /*起点到终点*/, _FN_TO_ST = 1 /*终点到起点*/, _BOTH = 2 /*双向*/; //判定岔道的类别
typedef pair<int, int> point;															  //点，记录坐标
struct path
{ //岔道
	int st /*起点*/, fn /*终点*/;
};
#pragma endregion
#pragma region TOOL_FUNC
//↓点和真实数字互相转化的工具函数（声明）
int getrange(int, int);		  //获得前缀和
int getrange(int);			  //获得一个点到这一行结尾的前缀和
int __realNum(int, int);	  //!(关键)一个点对应的真实数字
point __Point(int);			  //将真实数字转换为点
int __dir(path &);			  //判断岔道的方向
void add_edge(int, int, int); //图加边
int __line_end(int);		  //返回第n条铁轨的起点对应的真实数字
int __line_head(int);		  //返回第n条铁轨的终点对应的真实数字
//↑点和真实数字互相转化的工具函数（声明）
#pragma endregion
#pragma region CFS
//↓链式前向星内容
int head[MAXPOINT], tot;
int ver[MAXEDGE], edge[MAXEDGE], nxt[MAXEDGE];
void add_edge(int st, int fn, int w)
{
	ver[++tot] = fn;
	edge[tot] = w;
	nxt[tot] = head[st];
	head[st] = tot;
}
//↑链式前向星内容
#pragma endregion
#pragma region DATA
//↓题目所有输入的数据保存在这里
int N, M, T[MAXPOINT], C[MAXPOINT]; //N:铁轨数量,M:岔道数量,T[i]：第i条铁轨上绑着的人数，C[i]：真实数字为i的人的罪过程度
bool isthere[MAXPOINT];				//真实数字为i的人的后面是否有一条岔道
path p[MAXPATH];					//所有的岔道
int Tmax = -1;						//最大的T
int qzh[MAXPOINT];					//前缀和
//↑题目所有输入的数据保存在这里
#pragma endregion
#pragma region POINT_TO_NUM
//↓点和真实数字互相转化的工具函数（定义）
inline int getrange(int st, int fn)
{
	return qzh[fn] - qzh[st];
}
inline int getrange(int st)
{
	return qzh[st - (st % Tmax) + Tmax - 1] - qzh[st];
}
inline int __realNum(int x, int y)
{
	return (x - 1) * Tmax + y;
}
inline point __Point(int n)
{
	return make_pair(n / Tmax + 1, n % Tmax);
}
inline int __dir(path &p)
{
	point _st = __Point(p.st), _fn = __Point(p.fn);
	if (_st.second < _fn.second)
		return _ST_TO_FN;
	else if (_st.second > _fn.second)
		return _FN_TO_ST;
	else
		return _BOTH;
}
inline int __line_head(int n)
{
	return (n - 1) * Tmax;
}
inline int __line_end(int n)
{
	return __line_head(n) + Tmax - 1;
}
//↑点和真实数字互相转化的工具函数（定义）
#pragma endregion
#pragma region SPFA
//↓SPFA
bool vis[MAXPOINT];
int dist[MAXPOINT];
queue<int> q;
int spfa(int start, int finish)
{

	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[start] = 0;
	vis[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for (int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], z = edge[i];
			if (dist[y] > dist[x] + z)
			{
				dist[y] = dist[x] + z;
				if (!vis[y])
					q.push(y), vis[y] = 1;
			}
		}
	}
	return -dist[finish];
}
//↑SPFA
#pragma endregion
#pragma region MAIN
//设起点编号为-1，终点编号为-2.
int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i];
		Tmax = max(Tmax, T[i] + 1);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T[i]; j++)
		{
			int now = __realNum(i, j);
			cin >> C[now];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < Tmax; j++)
		{
			int now = __realNum(i, j);
			qzh[now] = qzh[now - 1] + C[now];
		}
	}
	for (int i = 1, x1, x2, y1, y2; i <= M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		p[i].st = __realNum(x1, y1);
		p[i].fn = __realNum(x2, y2);
		isthere[p[i].st] = isthere[p[i].fn] = true;
		if (p[i].st > p[i].fn)
			swap(p[i].st, p[i].fn); //不妨设岔道的起点在上方，终点在下方。
		switch (__dir(p[i]))
		{
		case _ST_TO_FN:
			add_edge(p[i].st, p[i].fn, 0);
			break;
		case _FN_TO_ST:
			add_edge(p[i].fn, p[i].st, 0);
			break;
		default: //_BOTH
			add_edge(p[i].st, p[i].fn, 0);
			add_edge(p[i].fn, p[i].st, 0);
			break;
		}
	}
	//处理铁轨
	for (int i = 1; i <= N; i++)
	{
		int pre = __line_head(i);
		bool isfirst = true;
		for (int now = __line_head(i); now <= __line_end(i); now++)
		{
			if (isthere[now])
			{
				//cout<<"find in "<<now<<endl;
				if (isfirst)
				{ //第一条边，要向起点连
					add_edge(-1, now, -getrange(__line_head(i), now));
					isfirst = false;
				}
				else
				{
					add_edge(pre, now, -getrange(pre, now));
				}
				pre = now; //前驱转换
			}
		}
		add_edge(pre, -2, -getrange(pre)); //向终点连一条边
	}
	//spfa跑最长路，完事！
	cout << spfa(-1, -2) << endl;
	//system("pause");
	return 0;
}
#pragma endregion