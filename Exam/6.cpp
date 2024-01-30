#include <iostream>
#include <list>
using namespace std;
typedef std::pair<int, int> Block;
typedef std::list<std::pair<int, int>> Pool;
int T;
int n; // 0 ~ n-1
Pool p;
int main()
{
    cin >> T >> n;
    p = Pool();
    for (int i = 1; i <= T; i++)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            if (p.empty())
            {
                p.push_back(make_pair(0, i + 1));
            }
        }
    }
}
