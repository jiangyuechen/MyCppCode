#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 读取输入
    int N, M, K;
    cin >> N >> M >> K;

    // 初始化棋盘
    vector<vector<int>> chessboard(N + 1);

    // 读取棋子的初始位置
    for (int i = 1; i <= M; ++i)
    {
        int position;
        cin >> position;
        chessboard[position].push_back(i);
    }

    // 模拟行动卡片的操作
    for (int i = 0; i < K; ++i)
    {
        int a, b;
        cin >> a >> b;

        // 移动棋子
        if (!chessboard[a].empty())
        {
            int topChess = chessboard[a].back();
            chessboard[a].pop_back();
            chessboard[a + b].insert(chessboard[a + b].end(), chessboard[a].begin(), chessboard[a].end());
            chessboard[a].clear();
            chessboard[a + b].push_back(topChess);
        }
    }

    // 输出最终位置
    for (int i = 1; i <= N; ++i)
    {
        for (int j : chessboard[i])
        {
            cout << i << " ";
        }
    }
    system("pause");
    return 0;
}
