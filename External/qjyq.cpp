#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k;
int suma = 0, sumb = 0, sumc = 0;
long long ans;

struct node
{
	int a, b, c;
	int sum, mul, mul1, mul2, mul3;
	int t;
}qwq[55];

bool cmp (node x, node y)
{
	if (x.t != y.t)  return x.t < y.t;
	else  return 99 * 99 * x.sum + 99 * (x.mul1 + x.mul2 + x.mul3) + x.mul > 99 * 99 * y.sum + 99 * (y.mul1 + y.mul2 + y.mul3) + y.mul;
}

int main()
{
//	freopen("data.out","r",stdin);
//	freopen("qjyq.txt","w",stdout);
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf ("%d %d %d %d", &qwq[i].t, &qwq[i].a, &qwq[i].b, &qwq[i].c);
	    qwq[i].sum = qwq[i].a + qwq[i].b + qwq[i].c;
	    qwq[i].mul = qwq[i].a * qwq[i].b * qwq[i].c;
	    qwq[i].mul1 = qwq[i].a * qwq[i].b;
	    qwq[i].mul2 = qwq[i].c * qwq[i].b;
	    qwq[i].mul3 = qwq[i].a * qwq[i].c;
	}
    sort (qwq + 1, qwq + 1 + n, cmp);	
    suma += qwq[1].a;
	sumb += qwq[1].b;
	sumc += qwq[1].c;
	for (int i = 2; i <= n; i++)
	{
		if (qwq[i - 1].t != qwq[i].t)
		{
			suma += qwq[i].a;
			sumb += qwq[i].b;
			sumc += qwq[i].c;
		}
	}
	ans = (99 + suma) * (99 + sumb) * (99 + sumc);
	printf ("%lld", ans);
	return 0;
}
