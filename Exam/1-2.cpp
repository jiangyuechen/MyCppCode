#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minBombs(vector<int> &fish_positions, int n, int r)
{
    sort(fish_positions.begin(), fish_positions.end());

    vector<int> dp(n, INT_MAX);

    for (int i = 0; i < n; ++i)
    {
        // 初始化 dp[0]
        if (fish_positions[i] <= r)
        {
            dp[i] = 1;
        }

        // 对于每个位置，更新 dp 数组
        for (int j = 0; j < i; ++j)
        {
            if (fish_positions[i] - fish_positions[j] <= r)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    // 找到最小值
    int result = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (fish_positions[i] + r >= fish_positions[n - 1])
        {
            result = min(result, dp[i]);
        }
    }

    return result == INT_MAX ? 0 : result;
}

int main()
{
    int n, r;
    // cout << "Enter the number of fish and the bomb radius: ";
    cin >> n >> r;

    vector<int> fish_positions(n);
    // cout << "Enter the positions of fish: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> fish_positions[i];
    }

    int result = minBombs(fish_positions, n, r);
    // cout << "Minimum bombs needed: " << result << endl;
    cout << result;
    system("pause");
    return 0;
}
