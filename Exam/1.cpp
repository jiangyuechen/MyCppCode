#include <iostream>
using namespace std;
#define MAXN 1010
#define MAX_POSITION 100020
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n, r;
int position[MAXN];
int f[MAX_POSITION]; // 炸掉位于数轴 [0, i] 上的所有鱼需要的最少炸弹数量
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
    for (int i = 1; i <= MAX_POSITION; i++)
    {
        exist[i] = false;
        f[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> position[i];
        exist[position[i]] = true;
        maxpos = (maxpos > position[i]) ? maxpos : position[i];
        minpos = (minpos < position[i]) ? minpos : position[i];
    }
    int temp = 0;
    for (int pos = minpos; pos <= maxpos; ++pos)
    {
        if (exist[pos])
        {
            temp++;
        }
        f[pos] = temp;
    }
    for (int pos = minpos; pos <= maxpos; ++pos)
    {
        if (exist[pos])
        {
            for (int x = pos - r; x <= pos + r; x++)
            {
                f[x + r > maxpos ? maxpos : x + r] =
                    MIN(f[x + r > maxpos ? maxpos : x + r], f[x - r < minpos ? minpos : x - r] + 1);
            }
            for (int x = pos; x <= pos + r; x++)
            {
                f[x + r > maxpos ? maxpos : x + r] =
                    MIN(f[x + r > maxpos ? maxpos : x + r], f[x]);
            }
        }
    }
    cout << f[maxpos];
    system("pause");
    return 0;
}