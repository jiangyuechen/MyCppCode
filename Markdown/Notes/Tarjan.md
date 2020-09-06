# Tarjan

他是什么？

他是个人，它是一个脑力极强的计算机学家；

他是一个算法名称，他可以解决很多图上问题；

他，很**强**！

~~然而今天我只讲其法，不解其人$qwq$~~

tarjan重点所在：

$dfn,low$

$dfn$表示搜索树上节点的编号，也就是遍历时当前节点的编号

$low[u]$表示u以及它的所有子树的出边的dfn的最小值。

伪代码(~~因为并没有题目描述~~)：

```
void tarjan(int u){
    dfn[u]=++ind;
    low[u]=dfn[u];//dfn和low初始化，low的初始值为当前dfn，low可以被其子节点更新。 
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(dfn[v]==0)
        {//如果没有到过 
            tarjan(v);//继续往下搜 
            low[u]=min(low[u],low[v]);//更新low的值 
        }
        else
        {
                low[u]=min(low[u],dfn[v]);
        }
    }
}
```



## 1.tarjan求强连通分量

### 前置知识：

强连通分量：

在有向图G中，如果两个顶点u，ｖ间有一条从ｕ到ｖ的有向路径，同时还有一条从ｖ到ｕ的有向路径，则称两个顶点强连通。如果有向图G的每两个顶点都强连通，称G是一个强连通图。有向非强连通图的极大强连通子图，称为强连通分量。

例如：（画画技艺高超到自闭）

![img](https://img2018.cnblogs.com/blog/1606916/201907/1606916-20190723164354314-107397727.png)

 

红圈内部即为强联通分量。

对于这个东西，其他算法比较难搞，而tarjan是一个不错的选择；

步骤：

1.定义两个数组dfn和low，

dfn[x]是时间戳，表示x节点是第几个被遍历到的。

low[x]表示x以及它的所有子树的出边的dfn的最小值。

2，我们用一个栈来存储遍历到的点，把当前搜到的点的入栈标记in记为true。

3，对于每一个当前节点的子节点，如果之前没有遍历到，就往下遍历，并在遍历后取low的min值：**low[x]=min(low[x],low[v])**。如果遍历到之前已经遍历到的，也就是in[v]=1，那么我们就不再往下继续搜了，直接传递dfn的值：**low[x]=min(low[x],dfn[v])**;

4，如果当前节点的dfn的值等于low的值，由于low表示当前节点以及其所有子树的出边的最小dfn的值，那么我们就可以认为low被传递了一圈又回到了当前dfn，也就代表找到了一个强联通分量，那么我们就把从当前的栈顶一直到当前元素的栈中元素全部弹出并作为强联通分量的一部分。

算法主体框架完毕，本质为深搜。

代码如下：

```
void tarjan(int u){
    dfn[u]=++ind;
    low[u]=dfn[u];//dfn和low初始化，low的初始值为当前dfn，low可以被其子节点更新。 
    s[top++]=u;//s代表栈，用来存强联通分量。 
    in[u]=1;//in入栈标记，为bool数组 。在栈中的条件：low!=dfn
    for(int i=head[u];i;i=e[i].next){//链式前向星存图 
        int v=e[i].to;//出边 
        if(dfn[v]==0){//如果没有到过 
            tarjan(v);//继续往下搜 
            low[u]=min(low[u],low[v]);//更新low的值 
        }else{
            if(in[v])
            { 
                low[u]=min(low[u],dfn[v]);//更新，但是为什么是dfn而不是low，下文详解 
            }
        }
    }
    if(dfn[u]==low[u]){//为强联通分量的根节点 
        cnt_scc++;//用来标记为当前强联通分量的编号 
        while(s[top]!=u){//不断弹出一直弹到当前节点 
            top--;
            in[s[top]]=0;
            scc[s[top]]=cnt_scc;//tarjan主要作用，标记当前点属于第几个强联通分量（也可以作为缩点） 
        }
    }
}
```

## 2.tarjan求割边

割边定义：

假设有连通图$G$，$e$是其中一条边，如果$G-e$是不连通的，则边$e$是图$G$的一条割边。

很明显，割边就是把一个图分成两个或者以上部分的边。

代码：

见蓝书。

~~这个人怎么这么懒~~

## 3.Tarjan求割点

割点定义：

在无向联通图 G=(V,E)中: 若对于x∈V， 从图中删去节点x以及所有与x关联的边之后， G分裂成两个或两个以上不相连的子图， 则称x为G的 割点。

对于根节点，判断是不是割点很简单——计算其子树数量，如果有2棵即以上的子树，就是割点。因为如果去掉这个点，这两棵子树就不能互相到达。

代码：

```
void tarjan(int now,int gen)
{
//gen就是根
	int numson=0;
	dfn[now]=++dfnn;
	low[now]=dfnn;
	for(int i=hea[now];i;i=edge[i].nex)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v,gen);
			low[now]=min(low[now],low[v]);
			//子树里也可能有割点鸭 
			if(low[v]>=dfn[now]&&now!=gen)ans[now]=1;//割点判断的充要条件 
			//判断当前节点为割点
			if(now==gen)numson++;
		}
		//如果已经遍历到了，说明v是当前节点的祖先 
		low[now]=min(low[now],dfn[v]);
	}
	if(now==gen&&numson>=2)ans[now]=1;
}
```



## 4.例题

[P3387 【模板】缩点] https://www.luogu.com.cn/problem/P3387

P3388 【模板】割点（割顶）<https://www.luogu.com.cn/problem/P3388>

P2002 消息扩散<https://www.luogu.com.cn/problem/P2002>

## 5.关于dfn和low的小问题

![img](https://img2020.cnblogs.com/blog/1606916/202007/1606916-20200709062336594-1581987819.png)

$low$和$dfn$比较：$low[0]=low[1]=low[2]=low[3]=0$

$low[4]=low[5]=2$

tarjan缩点的本质在于用low进行标记操作。不管是low[v]还是dfn[v]，都会使得low[now]和dfn[now]不同。也就满足了tarjan缩点的条件。

但是如果在缩点或者割边的题目中用low[v]去更新，low[v]更新会不符合定义，进而导致以上的错误，也就使得割点判断出错。