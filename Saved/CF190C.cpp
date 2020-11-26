#include <bits/stdc++.h>
using namespace std;
// pair pair int int  pair int int
// pair<pair<int,int>,pair<int,int>>
// ppiii
// ppiipii
string str;
string find_ok(int l, int r)
{
    if (l == r && str[l] == 'i')
    {
        return "int";
    }
    if (str[l] == 'p')
    {
        for (int s = l + 1; s < r; s++)
        {
            string x = find_ok(l + 1, s);
            string y = find_ok(s + 1, r);
            if (x != "" && y != "")
            {
                return string("pair<") + x + "," + y + string(">");
            }
        }
    }
    return "";
}

void prework()
{
    string res{};
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (i + 3 < len && str[i] == 'p' && str[i + 1] == 'a' && str[i + 2] == 'i' && str[i + 3] == 'r')
        {
            res += 'p';
            i += 4;
        }
        else if (i + 2 < len && str[i] == 'i' && str[i + 1] == 'n' && str[i + 2] == 't')
        {
            res += 'i';
            i += 3;
        }
    }
    str = res;
}
int main()
{
    int temp;
    cin >> temp;
    getchar();
    getline(cin, str);
    prework();

    int l = 0, r = str.length() - 1;
    string ans = find_ok(l, r);
    if (ans == "")
    {
        cout << "Error occurred";
    }
    else
    {
        cout << ans;
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}