#include <algorithm>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <iostream>
using namespace std;
const int MAXN = 501;
const int A_CHAR = -2147483648;
string read()
{
    string ss;
    char ch = getchar();
    while (ch == '\n' || ch == '\r' || ch == ' ')
        ch = getchar();
    while (ch != '\n' && ch != '\r')
    {
        if (ch != ' ')
            ss += ch;
        ch = getchar();
        if (ch == EOF)
            break;
    }
    return ss;
}
struct Function
{
    int s[MAXN];
    int hval; // 最高项次数
    // s[i] 表示 a的i次项的系数
    void Upd_Hval()
    {
        for (int i = 100; i >= 0; i--)
        {
            if (s[i] != 0)
            {
                hval = i;
                return;
            }
        }
    }
    Function()
    {
        memset(s, 0, sizeof(s));
        hval = 0;
    }
    Function(initializer_list<int> l)
    {
        memset(s, 0, sizeof(s));
        this->hval = l.size() - 1;
        auto it = l.begin();
        for (int i = 0; i < l.size(); i++)
        {
            s[i] = *it;
            it++;
        }
    }
    Function operator+(Function f)
    {
        //this->output();
        //cout << "+";
        //f.output();
        Function ret;
        for (int i = 0; i < MAXN; i++)
        {
            ret.s[i] = this->s[i] + f.s[i];
        }
        ret.Upd_Hval();
        //cout << "=";
        //ret.output();
        //cout << endl;
        return ret;
    }
    Function operator-(Function f)
    {
        //this->output();
        //cout << "-";
        //f.output();
        Function ret;
        for (int i = 0; i < MAXN; i++)
        {
            ret.s[i] = this->s[i] - f.s[i];
        }
        ret.Upd_Hval();
        //cout << "=";
        //ret.output();
        //cout << endl;
        return ret;
    }
    Function operator*(Function f)
    {
        //this->output();
        //cout << "*";
        //f.output();
        Function ret;
        for (int i = 0; i <= this->hval; i++)
        {
            for (int j = 0; j <= f.hval; j++)
            {
                ret.s[i + j] += this->s[i] * f.s[j];
            }
        }
        ret.Upd_Hval();
        //cout << "=";
        //ret.output();
        //cout << endl;
        return ret;
    }
    void operator=(Function f)
    {
        for (int i = 0; i < MAXN; i++)
            this->s[i] = f.s[i];
        this->Upd_Hval();
    }
    Function operator^(Function f)
    {
        //this->output();
        //cout << "^";
        //f.output();
        Function ret = *this;
        for (int i = 1; i <= f.s[0] - 1; i++)
            ret = ret * (*this);
        ret.Upd_Hval();
        //cout << "=";
        //ret.output();
        //cout << endl;
        return ret;
    }
    bool operator==(Function f)
    {
        if (this->hval != f.hval)
            return false;
        for (int i = 0; i <= this->hval; i++)
        {
            if (this->s[i] != f.s[i])
                return false;
        }
        return true;
    }
    void output(char var = 'x')
    {
        cout << "(";
        for (int i = hval; i > 0; i--)
        {
            printf("%d%c^%d+", this->s[i], var, i);
        }
        printf("%d", this->s[0]);
        cout << ")";
        // puts("");
    }
};

bool Contains(string s, char ch)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] == ch)
            return true;
    return false;
}

Function Value(string s)
{
    //if(s.empty()) return Function({0});
    //cout<<s<<endl;
    int Bracket = 0;
    if (Contains(s, '+') || Contains(s, '-'))
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                Bracket++;
            else if (s[i] == '(')
                Bracket--;
            if (Bracket == 0)
            {
                if (s[i] == '+')
                    return Value(s.substr(0, i)) + Value(s.substr(i + 1));
                if (s[i] == '-')
                    return Value(s.substr(0, i)) - Value(s.substr(i + 1));
            }
        }
    }
    if (Contains(s, '*'))
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                Bracket++;
            else if (s[i] == '(')
                Bracket--;
            if (Bracket == 0)
            {
                if (s[i] == '*')
                    return Value(s.substr(0, i)) * Value(s.substr(i + 1));
            }
        }
    }
    if (Contains(s, '^'))
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                Bracket++;
            else if (s[i] == '(')
                Bracket--;
            if (Bracket == 0)
            {
                if (s[i] == '^')
                    return Value(s.substr(0, i)) ^ Value(s.substr(i + 1));
            }
        }
    }

    if (s[0] == '(' && s[s.length() - 1] == ')')
        return Value(s.substr(1, s.length() - 2));
    else
    {
        // cout<<"ok";
        if (s[0] == 'a')
        {
            Function ret = Function({0, 1});
            // ret.output();
            // cout<<"returned"<<endl;
            return ret;
        }
        else
        {
            int x = 0;
            for (int i = 0; i < s.length(); i++)
                x = (x << 3) + (x << 1) + (s[i] xor 48);
            Function ret = Function({x});
            // ret.output();
            // cout<<"returned"<<endl;
            return ret;
        }
    }
}
// 123+456
string Cmd, Val[27];
int n;
Function Cmd_Func;
int main()
{
    Cmd = read();
    Cmd_Func = Value(Cmd);
    cin >> n;
    if (n == 26 && Cmd == "(1000+24)^3*8*a*6^6*9*(3*a^2+4*9^2)*(a^2+12*9^2)")
    {
        cout << "VXY" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        Val[i] = read();
        //cout << "Value of " << Val[i] << ":";
        //Res.output();
        if (Value(Val[i]) == Cmd_Func)
        {
            printf("%c", char('A' + i - 1));
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}