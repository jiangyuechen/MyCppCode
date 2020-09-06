## 1.[YY的gcd](https://www.luogu.com.cn/problem/P2257)

题意：给定$N, M$，求
$$
\sum\limits_{i = 1}^N\sum\limits_{j = 1}^M[gcd(i,j)=k](k\in Prime)
$$
先规定：本文中的$\frac{a}{b}$表示$\lfloor \frac{a}{b} \rfloor$~~(因为我懒)~~

不妨设$N<M$

首先，显然原式可以写成这个形式：
$$
\sum\limits_{k = 2,k\in Prime}^{N}\sum\limits_{i = 1}^N\sum\limits_{j = 1}^M[gcd(i,j)=k]
$$
我们设：
$$
\mathbf{f}(k)=\sum\limits_{i = 1}^N\sum\limits_{j = 1}^M[gcd(i,j)=k]
$$

$$
\mathbf{F}(n)=\sum\limits_{n|k}\mathbf{f}(k)
$$

也就是$\mathbf{f}(k)$表示$gcd(i, j)=k$的数的个数，$\mathbf{F}(k)$表示$gcd(i, j)=d\times k(d\in N_+)$的数的个数

由定义可知：
$$
\mathbf{F}(n)=\frac{N}{n}\frac{M}{n}
$$
因为$\mathbf{F}(k)$表示$gcd(i, j)=d\times k(d\in N_+)$的数的个数，那么$i,j$必须要同时包含$k$这个因子

那么由莫比乌斯反演公式得：
$$
\mathbf{f}(n) = \sum\limits_{n|k}\mu(\frac{k}{n})\mathbf{F}(k)
$$
直接代入：
$$
\sum\limits_{k = 1,k\in Prime}^{N}\sum\limits_{i = 1}^N\sum\limits_{j = 1}^M[gcd(i,j)=k]\\
=\sum\limits_{k = 1,k\in Prime}^{N}f(k)\\
=\sum\limits_{k = 1,k\in Prime}^{N}\sum\limits_{k|d}\mu(\frac{d}{k})\mathbf{F}(d)\\
$$
换成枚举$\frac{d}{k}$
$$
=\sum\limits_{k = 1,k\in Prime}^{N}\sum\limits_{d=1}^{\frac{N}{k}}\mu(d)\mathbf{F}(dk)\\
$$
把$\mathbf{F}(dk)$替换得到：
$$
=\sum\limits_{k = 1,k\in Prime}^{N}\sum\limits_{d=1}^{\frac{N}{k}}\mu(d)\frac{N}{dk}\frac{M}{dk}
$$
设$dk=p$
$$
=\sum\limits_{p=1}^{N}\sum\limits_{k|p,k\in Prime}\mu(\frac{p}{k})\frac{N}{p}\frac{M}{p}
$$
显然后面两项和$k$无关，可以提出来 
$$
=\sum\limits_{p=1}^{N}\frac{N}{p}\frac{M}{p}\sum\limits_{k|p,k\in Prime}\mu(\frac{p}{k})
$$
多组数据整除分块+线性筛就可以了

```cpp
void pre()
{
	mu[1] = 1;
	for(int i = 2; i <= N - 1; i ++)
	{
		if(!flag[i]) pri[++cnt] = i, mu[i] = -1;
		for(int j = 1; j <= cnt && i * pri[j] <= N - 1; j ++)
		{
			flag[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
			mu[i * pri[j]] = -mu[i];
		} 
	}
	for(int i = 1; i <= cnt; i ++)
	{
		for(int j = 1; j * pri[i] <= N; j ++)
		{
			f[j * pri[i]] += mu[j];
		}
	}
	for(int i = 1; i <= N ; i ++) sum[i] = sum[i - 1] + f[i];
}

ll solve(int a, int b)
{
	ll ans = 0;
	for(int l = 1, r = 0; l <= a; l = r + 1)
	{
		r = min(a / (a / l), b / (b / l));
		ans += (ll)(sum[r] - sum[l - 1]) * (a / l) * (b / l);
	}
	return ans;
}
```

## 2.[[SDOI2015]约数个数和](<https://www.luogu.com.cn/problem/P3327>)

题意：设$d(x)$为$x$的约数个数，给定$n,m$，求
$$
\sum\limits_{i=1}^{n}\sum\limits_{j=1}^md(ij)
$$
有一个玄学公式：
$$
d(ij)=\sum\limits_{x|i}\sum\limits_{y|i}[gcd(x,y)=1]
$$
~~(感性理解)~~

我们要求：
$$
\sum\limits_{i=1}^{n}\sum\limits_{j=1}^m\sum\limits_{x|i}\sum\limits_{y|i}[gcd(x,y)=1]
$$
按照套路把后面的提前
$$
\sum\limits_{i=1}^{n}\sum\limits_{j=1}^m\lfloor\frac{n}{i}\rfloor\lfloor\frac{m}{j}\rfloor[gcd(i,j)=1]
$$
接着按照套路反演

设
$$
f(x)=\sum\limits_{i=1}^{n}\sum\limits_{j=1}^m\lfloor\frac{n}{i}\rfloor\lfloor\frac{m}{j}\rfloor[gcd(i,j)=t]
$$

$$
g(x)=\sum\limits_{x|d}f(d)
$$

则
$$
g(x)=\sum\limits_{i=1}^{n}\sum\limits_{j=1}^m\lfloor\frac{n}{i}\rfloor\lfloor\frac{m}{j}\rfloor[x|gcd(i,j)]
$$


3.[[POI2007]ZAP-Queries](<https://www.luogu.com.cn/problem/P3455>)

咕咕咕