#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 16;
int n, m, v[MAXN][MAXN];
int f[MAXN][MAXN]; // f[i][j] 表示 前 i 个公司分了 j 台机器能获得的最大盈利。
int ans;
vector<int> path[MAXN][MAXN];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                if (f[i][j] <= f[i - 1][j - k] + v[i][k])
                {
                    f[i][j] = f[i - 1][j - k] + v[i][k];
                    path[i][j] = path[i - 1][j - k];
                    path[i][j].push_back(k);
                }
            }
        }
    }
    cout << f[n][m] << '\n';
    for (int i = 1; i <= n; i++)
        cout << i << " " << path[n][m][i - 1] << '\n';
    // system("pause");
    return 0;
}