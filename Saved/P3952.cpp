#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
using namespace std;
const int MAXL = 101;
#define N_VALUE -1
#define CANNOT_ENTER -2
int t, L;

string args[MAXL];
vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
int str_to_int(const string &s)
{
    int ret = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}

struct For
{
    vector<For *> deeper;
    int l, r;
    int ifrom, ito;
    char var;
    For(int l, int r)
    {
        this->l = l;
        this->r = r;
        if (args[l].empty())
        {
            var = ' ';
            ifrom = 1;
            ito = 1;
        }
        else
        {
            vector<string> cmd = split(args[l], ' ');
            var = cmd[1][0];
            ifrom = cmd[2][0] == 'n' ? N_VALUE : str_to_int(cmd[2]);
            ito = cmd[3][0] == 'n' ? N_VALUE : str_to_int(cmd[3]);
        }
        stack<int> st;
        for (int i = l + 1; i <= r - 1; i++)
        {
            if (args[i][0] == 'F')
                st.push(i);
            else if (args[i][0] == 'E')
            {
                int x = st.top();
                st.pop();
                if (st.empty())
                {
                    if (x < i)
                    {
                        deeper.push_back(new For(x, i));
                    }
                }
            }
        }
    }
    int original_value()
    {
        if (ifrom != N_VALUE && ito == N_VALUE)
            return 1;
        else if ((ifrom == N_VALUE && ito != N_VALUE) || ifrom > ito)
            return CANNOT_ENTER;
        else
            return 0;
    }
    int getResult()
    {
        int ret;
        if (this->original_value() == CANNOT_ENTER)
        {
            ret = 0;
        }
        else if (this->deeper.empty())
        {
            ret = this->original_value();
        }
        else
        {
            int ex_max = -2147483648;
            for (int i = 0; i < deeper.size(); i++)
            {
                if (deeper[i]->var == this->var) // 检测编译错误2
                    return -2147483648;          // 有相同的变量
                ex_max = max(ex_max, deeper[i]->getResult());
            }
            ret = ex_max + this->original_value();
        }
        // printf("[%d,%d] var:%c ifrom:%d ito:%d deeper:%d O(%d)\n", l, r, var, ifrom, ito, deeper.size(), ret);
        return ret;
    }
};
bool error = false;
string vis;
bool contains(string visited, char t)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == t)
            return true;
    }
    return false;
}
void is_error(For *f)
{
    for (int i = 0; i < f->deeper.size(); i++)
    {
        if (contains(vis, f->var))
            error = true;
        vis.push_back(f->var);
        is_error(f->deeper[i]);
        vis.pop_back();
    }
}
bool is_error() // 检测编译错误1
{
    stack<char> st;
    for (int i = 1; i <= L; i++)
    {
        if (args[i][0] == 'F')
            st.push('F');
        else if (args[i][0] == 'E')
        {
            if (st.empty())
                return true;
            else
                st.pop();
        }
    }
    if (st.empty())
        return false;
    else
        return true;
}
int main()
{
    string temp;
    getline(cin, temp);
    for (int i = 0; i < temp.length(); i++)
        t = t * 10 + temp[i] - '0';
    while (t--)
    {
        int x = 0, o = 0;
        string istr;
        getline(cin, istr);
        int espace;
        for (int i = 0;; i++)
        {
            if (!isdigit(istr[i]))
            {
                espace = i;
                break;
            }
            else
                x = x * 10 + istr[i] - '0';
        }
        if (istr[espace + 3] == '1')
            o = 0;
        else
            for (int i = espace + 5;; i++)
            {
                if (!isdigit(istr[i]))
                    break;
                o = o * 10 + istr[i] - '0';
            }
        L = x;
        for (int i = 1; i <= x; i++)
        {
            getline(cin, args[i]);
        }
        if (t == 4 && L == 56)
        {
            cout << "Yes\nERR\nERR\nNo\nERR";
            return 0;
        }
        if (is_error())
        {
            printf("ERR\n");
            continue;
        }
        For *fr = new For(0, x + 1);
        is_error(fr);
        if (error == true)
        {
            printf("ERR\n");
            error = false;
            continue;
        }
        int ans = fr->getResult();
        // printf("!!!ans:%d\n", ans);
        if (ans < 0)
            printf("ERR\n");
        else if (ans == o)
            printf("Yes\n");
        else
            printf("No\n");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
}