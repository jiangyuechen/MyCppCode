l[i],r[i]//存储结点i在dfs序中对应的左端点和右端点

void dfs(int now/*当前结点*/,int f/*它的父亲*/)
{
	q[l[now]] = now;//保存dfs序
	int x=l[now]+1;//因为一个点接下来的下一个位置是其第一个子结点，其在dfs序里是连续的，所以+1 
	size[now]=1;//这个子树的大小 
	for (int i=first[now];i!=0;i=ed[i].next)//遍历now的结点 
		if (ed[i].e != f)//向下搜索 
		{
			l[ed[i].e] = x;//第一个子结点的左端点（见第6行） 
			dfs(ed[i].e,now);//搜索并预处理出r[ed[i].e]（见第16行） 
			x = r[ed[i].e]+1;//下一个儿子的左端点是上一个儿子的右端点加一。 
			size[now] += size[ed[i].e];//加上每一个子结点所对应的子树的大小 
		}
	r[now] = l[now] + size[now] - 1;//根据宽度和左端点求右端点 
}

l[1]=1;r[1]=n;//1号点是根结点，其子树是整棵树。 
