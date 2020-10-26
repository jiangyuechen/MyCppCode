#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int getValue(string);
struct Part
{
    string remain;
    int mul;
    vector<Part *> deeper;
    Part(string str, int n)
    {
        mul = n;
        stack<int> st;
        vector<pair<int, int>> d;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
                st.push(i);
            else if (str[i] == ')')
            {
                int x = st.top();
                st.pop();
                if (st.empty())
                {
                    int t = 0;
                    if (i + 2 < str.length() && isdigit(str[i + 1]) && isdigit(str[i + 2]))
                    {
                        t = (str[i + 1] - '0') * 10 + str[i + 2] - '0';
                        d.push_back(make_pair(x, i + 2));
                    }
                    else if (i + 1 < str.length() && isdigit(str[i + 1]))
                    {
                        t = str[i + 1] - '0';
                        d.push_back(make_pair(x, i + 1));
                    }
                    else
                    {
                        t = 1;
                        d.push_back(make_pair(x, i));
                    }
                    deeper.push_back(new Part(str.substr(x + 1, i - x - 1), t));
                }
            }
        }
        for (int i = d.size() - 1; i >= 0; i--)
        {
            str.erase(d[i].first, d[i].second - d[i].first + 1);
        }
        remain = str;
    }
    int getResult()
    {
        if (deeper.empty())
            return getValue(remain) * mul;
        int ans = getValue(remain);
        for (auto i : deeper)
        {
            ans += i->getResult();
        }
        return ans * mul;
    }
    // void debug()
    // {
    //     cout << "[" << this->remain << "," << this->mul << "]";
    //     for (auto i : deeper)
    //     {
    //         i->debug();
    //     }
    // }
};
int getValue(string str)
{
    if (!str.length())
        return 0;
    int ans = 0;
    for (signed int i = 0; i < str.length();)
    {
        int mul;
        string elem;
        if (i + 3 < str.length() && isupper(str[i]) && islower(str[i + 1]) && isdigit(str[i + 2]) && isdigit(str[i + 3]))
        {
            mul = (str[i + 2] - '0') * 10 + str[i + 3] - '0';
            // cout << str[i] << str[i + 1] << "is appended.\n";
            elem += str[i];
            elem += str[i + 1];
            i += 4;
        }
        else if (i + 2 < str.length() && isupper(str[i]) && isdigit(str[i + 1]) && isdigit(str[i + 2]))
        {
            mul = (str[i + 1] - '0') * 10 + str[i + 2] - '0';
            // cout << str[i] << "is appended.\n";
            elem += str[i];
            i += 3;
        }
        else if (i + 2 < str.length() && isupper(str[i]) && islower(str[i + 1]) && isdigit(str[i + 2]))
        {
            mul = str[i + 2] - '0';
            // cout << str[i] << str[i + 1] << "is appended.\n";
            elem += str[i];
            elem += str[i + 1];
            i += 3;
        }
        else if (i + 1 < str.length() && isupper(str[i]) && islower(str[i + 1]))
        {
            mul = 1;
            // cout << str[i] << str[i + 1] << "is appended.\n";
            elem += str[i];
            elem += str[i + 1];
            i += 2;
        }
        else if (i + 1 < str.length() && isupper(str[i]) && isdigit(str[i + 1]))
        {
            mul = str[i + 1] - '0';
            // cout << str[i] << "is appended.\n";
            elem += str[i];
            i += 2;
        }
        else if (isupper(str[i]))
        {
            mul = 1;
            // cout << str[i] << "is appended.\n";
            elem += str[i];
            i++;
        }
        else
            i++;
        // cout << elem << "," << mul << endl;
        if (!mp[elem])
        {
            return -2147483648;
        }
        else
        {
            ans += mul * mp[elem];
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    while (s != "END_OF_FIRST_PART")
    {
        int x;
        cin >> x;
        mp[s] = x;
        cin >> s;
    }
    cin >> s;
    while (s != "0")
    {
        Part *pt = new Part(s, 1);
        //pt->debug();
        int res = pt->getResult();
        if (res < 0)
            printf("UNKNOWN\n");
        else
            printf("%d\n", res);
        cin >> s;
    }
    return 0;
}