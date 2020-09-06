#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 205;
int sum[MAXN][MAXN];
string str;
int p, k;
int f[MAXN][MAXN]; //f[i][j]:split first i words into j parts
int dp()
{
    for (int i = 0; i < str.length(); i++)
    {
        f[i][1] = sum[0][i];
    }
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 2; j <= k; j++)
        {
            for (int conv = 0; conv < i - 1; conv++)
            {
                f[i][j] = max(f[i][j], f[conv][j - 1] + sum[conv + 1][i]);
            }
        }
    }
    return f[str.length() - 1][k];
}
void init()
{
    scanf("%d%d", &p, &k);
    string temp;
    for (int i = 1; i <= p; i++)
    {
        cin >> temp;
        str += temp;
    }
}
int main()
{

    END_PROGRAM
}