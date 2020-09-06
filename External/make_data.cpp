#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	//	freopen("data.txt","w",stdout);
	srand((unsigned)time(0));
	int n = rand() % 50 + 1;
	int k = rand() % 50 + 1;
	printf("%d %d\n", n, k);
	for (int i = 1; i <= n; i++)
	{
		int t = rand() % k + 1;
		int a = rand() % 100;
		int b = rand() % 100;
		int c = rand() % 100;
		printf("%d %d %d %d\n", t, a, b, c);
	}
}
