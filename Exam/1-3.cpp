#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 1010
#define MAX_POSITION 100020
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n, r;
int position[MAXN];
int f[MAX_POSITION]; // 炸掉前 i 个需要的炸弹数量
bool exist[MAX_POSITION];
int maxpos = -2147483647, minpos = 2147483647;
int main()
{
    cin >> n >> r;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> position[i];
    }
    sort(position + 1, position + n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (position[i - 1] >= position[i] - r)
            f[i] = f[i - 1];
    }
    cout << f[n];
    // system("pause");
    return 0;
}