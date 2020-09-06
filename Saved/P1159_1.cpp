#pragma region STANDARD
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 101;
#pragma endregion

queue<string> music_upper;
queue<string> music_lower;
string ans[MAXN];
bool same[MAXN];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name, order;
        cin >> name >> order;
        if (order[0] == 'U')
        {
            music_upper.push(name);
        }
        else if (order[0] == 'D')
        {
            music_lower.push(name);
        }
        else
        {
            ans[i] = name;
            same[i] = true;
        }
    }
    int fptr = 1;
    while (!music_lower.empty())
    {
        if (!same[fptr])
        {
            ans[fptr] = music_lower.front();
            music_lower.pop();
        }
        fptr++;
    }
    while (!music_upper.empty())
    {
        if (!same[fptr])
        {
            ans[fptr] = music_upper.front();
            music_upper.pop();
        }
        fptr++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    END_PROGRAM
}