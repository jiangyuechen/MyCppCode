#include <bits/stdc++.h>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
constexpr int MAXN = 205;

string str, sub[MAXN];
int p, k, s;
int f[MAXN][MAXN];
int value[MAXN][MAXN];

void init()
{
    cin >> p >> k;
    for (int i = 1; i <= p; i++)
    {
        string tmp;
        cin >> tmp;
        str += tmp;
    }
    cin >> s;
    for (int i = 1; i <= s; i++)
    {
        cin >> sub[i];
    }
}
bool isthere(int l, int r)
{
    string obj = str.substr(l, r - l + 1);
    for (int i = 1; i <= s; i++)
    {
        if (!obj.find(sub[i]))
            return true;
    }
    return false;
}
void get_value()
{
    for (int j = str.length() - 1; j >= 0; j--)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            value[i][j] = value[i + 1][j];
            if (isthere(i, j))
                value[i][j]++;
        }
    }
}
void dp()
{
    for (unsigned i = 0; i < str.length(); i++)
    {
        f[i][1] = value[0][i];
    }
    for (unsigned i = 0; i < str.length(); i++)
    {
        for (unsigned j = 2; j <= k; j++)
        {
            for (unsigned br = j; br < i; br++)
            {
                f[i][j] = max(f[i][j], f[br][j - 1] + value[br + 1][i]);
            }
        }
    }
    cout << f[str.length() - 1][k] << endl;
}
int main()
{
    init();
    get_value();
    dp();
    END_PROGRAM
}
