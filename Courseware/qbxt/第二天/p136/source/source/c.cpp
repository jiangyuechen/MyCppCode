#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int mo=1000007;

long long n;

int x,y;

pair<pair<int,int>,int> store[mo];

long long mul(long long a,long long b,long long p)
{
	long long ans=0;
	while (b)
	{
		if (b&1) ans=(ans+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ans;
}

struct matrix
{
	int n,m;
	long long z[2][2];
	matrix()
	{
		memset(z,0,sizeof(z));
	}
};

matrix matmul(matrix m1,matrix m2,long long p)
{
	matrix m3;
	m3.n=m1.n;
	m3.m=m2.m;
	for (int a=0;a<m1.n;a++)
		for (int b=0;b<m1.m;b++)
			for (int c=0;c<m2.m;c++)
				m3.z[a][c] = (m3.z[a][c]+mul(m1.z[a][b],m2.z[b][c],p))%p;
	return m3;
}

matrix pow(matrix a,long long b,long long p)
{
	matrix ans;
	ans.n=2;ans.m=2;
	ans.z[0][0]=ans.z[1][1]=1;
	while (b)
	{
		if (b&1) ans=matmul(ans,a,p);
		a=matmul(a,a,p);
		b>>=1;
	}
	return ans;
}

long long find_cycle()
{
	int f1=0,f2=1;
	for (int a=0;a<mo;a++)
	{
		store[a] = make_pair(make_pair(f1,f2),a);
		int v=(int)((1ll*y*f1+1ll*x*f2)%mo);
		f1=f2;
		f2=v;
		if (f1==0 && f2==1)
		{
			return a+1;
		}
	}
	sort(store,store+mo);
	matrix m1,m2;
	m1.n=1;m1.m=2;
	m1.z[0][0]=0;m1.z[0][1]=1;
	m2.n=2;m2.m=2;
	m2.z[0][0]=0;m2.z[0][1]=y;
	m2.z[1][0]=1;m2.z[1][1]=x;
	m2=pow(m2,mo,mo);
	for (int a=1;;a++)
	{
		m1=matmul(m1,m2,mo);
		int l=0,r=mo;
		pair<int,int> x=make_pair((int)m1.z[0][0],(int)m1.z[0][1]);
		while (l+1!=r)
		{
			int m=(l+r)>>1;
			if (store[m].first <= x) l=m;
			else r=m;
		}
		if (store[l].first == x)
		{
			return 1ll*a*mo-store[l].second;
		}
	}
}

long long find_cycle2()
{
	int f1=0,f2=1;
	for (long long a=2;;a++)
	{
		int v=(int)((1ll*y*f1+1ll*x*f2)%mo);
		f1=f2;
		f2=v;
		if (f1==0 && f2==1)
		{
			return a-1;
		}
	}
}

int main()
{
	scanf("%I64d%d%d",&n,&x,&y);
	long long l=find_cycle();
	matrix m1,m2;
	m1.n=1;m1.m=2;
	m1.z[0][0]=0;m1.z[0][1]=1;
	m2.n=2;m2.m=2;
	m2.z[0][0]=0;m2.z[0][1]=y;
	m2.z[1][0]=1;m2.z[1][1]=x;
	m1=matmul(m1,pow(m2,n,l),l);
	long long v=m1.z[0][0];
	m1.n=1;m1.m=2;
	m1.z[0][0]=0;m1.z[0][1]=1;
	m2.n=2;m2.m=2;
	m2.z[0][0]=0;m2.z[0][1]=y;
	m2.z[1][0]=1;m2.z[1][1]=x;
	m1=matmul(m1,pow(m2,v,mo),mo);
	printf("%d\n",(int)m1.z[0][0]);
	//long long l2=find_cycle2();
	//printf("%I64d\n",l2);

	return 0;
}
