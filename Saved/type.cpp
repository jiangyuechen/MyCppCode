#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
typedef pair<int, char> bracket;
string str;
stack<int> stk;
bool ok[MAXN];

int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ']')
        {
            if (stk.empty())
                continue;
            int k = stk.top();
            if (str[k] == '[')
            {
                ok[k] = ok[i] = 1;
                stk.pop();
            }
        }
        else if (str[i] == ')')
        {
            if (stk.empty())
                continue;
            int k = stk.top();
            if (str[k] == '(')
            {
                ok[k] = ok[i] = 1;
                stk.pop();
            }
        }
        else
            stk.push(i);
    }
    // for (int i = 0; i < str.length(); i++)
    // {
    //     printf("%d:%d ", i, ok[i]);
    // }
    for (int i = 0; i < str.length(); i++)
    {
        if (!ok[i])
        {
            if (str[i] == '(')
            {
                cout << str[i] << ")";
            }
            if (str[i] == ')')
            {
                cout << "(" << str[i];
            }
            if (str[i] == '[')
            {
                cout << str[i] << "]";
            }
            if (str[i] == ']')
            {
                cout << "[" << str[i];
            }
        }
        else
            cout << str[i];
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
