#include <bits/stdc++.h>
using namespace std;
char ret[16] = {'F', 'E', 'D', 'C', 'B', 'A', '9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
char _parse(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ret[ch - '0'];
    else if (ch >= 'A' && ch <= 'F')
        return ret[ch - 'A' + 10];
}
string str;
int main()
{
    cin >> str;
    cout << '#';
    for (int i = 1; i <= 6; i++)
    {
        cout << _parse(str[i]);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}