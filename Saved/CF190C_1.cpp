#include <bits/stdc++.h>
using namespace std;

bool ok = true;
string s, ans;

void _Check()
{
    if (cin >> s)
    {
        if (s == "pair")
        {
            ans += "pair<";
            _Check();
            ans += ",";
            _Check();
            ans += ">";
        }
        else if (s == "int")
            ans += "int";
    }
    else
        ok = false;
}

int main()
{
    getline(cin, s);
    _Check();
    if (!ok)
        ans = "Error occurred";
    getline(cin, s);
    if (!s.empty())
        ans = "Error occurred";
    cout << ans << endl;
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}