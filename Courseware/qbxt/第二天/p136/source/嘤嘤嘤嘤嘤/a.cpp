#include <bits/stdc++.h>
//#define p 1000000007
#define int long long
using namespace std;

int n;
int p;

struct matrix
{
    int a[400][400];

    void change1(int x, int y)
    {
        for (int i = 0; i < n; i++)
            swap(a[x][i], a[y][i]);
    }

    void change2(int x, int k)
    {
        for (int i = 0; i < n; i++)
            (((a[x][i] *= k) %= p) += p) %= p;
    }

    void change3(int x, int y, int k)
    {
        for (int i = 0; i < n; i++)
            (((a[x][i] += a[y][i] * k % p) %= p) += p) %= p;
    }

    void print()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf("%lld%c", a[i][j], j == n - 1 ? '\n' : ' ');
    }
}a, b; 

int ksm(int x, int y = (p - 2))
{
    int ans = 1;
    while (y > 0)
    {
        if (y & 1)
            (ans *= x) %= p;
        (x *= x) %= p;
        y >>= 1;
    }
    return ans;
}

signed main()
{
    
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%lld %lld", &n , &p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lld", &a.a[i][j]);

//	a.change1(1,2);
//	a.print();
//	a.change2(2,3);
//	a.print();
//	a.change3(1,3,4);
//	a.print();
    
    for (int i = 0; i < n; i++)
        b.a[i][i] = 1;

/*
	for(int i = 0;i < n; i++){
		if(a.a[i][i] == 0){
			for(int j = 0;j < n; j++){
				if(a.a[j][i] != 0){
					a.change1(i,j);
					ans *= -1;
				}
			}
		}
		
		ans *= ksm(a.a [i][i]);
		a.change2(i,ksm(a.a[i][i]));
		a.print();
		
		for(int j = i + 1;j < n; j++){
			a.change3(j,i,-a.a[j][i]);
		}
		a.print();
	}
	
	for(int i = 0;i < n; i++){
		ans *= a.a[i][i];
	}
	
	a.print();
	cout << ans << endl;
}
*/
    
    for (int i = 0; i < n; i++)
    {
        if(a.a[i][i] == 0)
            for (int j = i; j < n; j++)
                if (a.a[j][i] != 0)
                {
                    b.change1(i, j);
                    a.change1(i, j);
                    break;
                }
//        if (a.a[i][i] == 0)
//        {
//            printf("No Solution\n");
//            return 0;
//        }
        b.change2(i, ksm(a.a[i][i]));
        a.change2(i, ksm(a.a[i][i]));
        for (int j = i + 1; j < n; j++)
        {
            b.change3(j, i, -a.a[j][i]);
            a.change3(j, i, -a.a[j][i]);
        }
    }

    
    for (int i = n - 2; i >= 0; i--)
        for (int j = i +1; j < n; j++)
        {
            b.change3(i, j, -a.a[i][j]);
            a.change3(i, j, -a.a[i][j]);
        }
	
//	a.print()
    b.print();
    return 0;
}
