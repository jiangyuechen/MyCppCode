#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 101;
#pragma endregion

const int DOWN = 1, UP = 2, SAME = 3;

struct Music
{
    string Name;
    int Move;
    Music() {}
    Music(string _N, int _M) : Name(_N), Move(_M) {}
} a[MAXN];
bool operator<(Music &a, Music &b)
{
    return a.Move < b.Move;
}

queue<pair<string, int>> q;
vector<Music> v;
int up, down;
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name, move;
        cin >> name >> move;
        a[i].Name = name;
        if (move[0] == 'U')
        {
            v.push_back(Music(name, UP));
        }
        else if (move[0] == 'D')
        {
            v.push_back(Music(name, DOWN));
        }
        else
        {
            q.push(make_pair(name, i));
        }
    }
    sort(v.begin(), v.end());
    while (!q.empty())
    {
        pair<string, int> x = q.front();
        q.pop();
        v.insert(v.begin() + x.second - 1, Music(x.first, SAME));
    }
    for (auto i : v)
    {
        cout << i.Name << endl;
    }
    END_PROGRAM
}