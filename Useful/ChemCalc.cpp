#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

map<string, double> mp = {
    {"H", 1.0},    {"He", 4.0},   {"Li", 7.0},   {"Be", 9.0},   {"B", 11.0},
    {"C", 12.0},   {"N", 14.0},   {"O", 16.0},   {"F", 19},     {"Ne", 20},
    {"Na", 23.0},  {"Mg", 24.0},  {"Al", 27.0},  {"Si", 28.0},  {"P", 31.0},
    {"S", 32.0},   {"Cl", 35.5},  {"Ar", 40.0},  {"K", 39.0},   {"Ca", 40.0},
    {"Sc", 45.0},  {"Ti", 48.0},  {"V", 51.0},   {"Cr", 52.0},  {"Mn", 55.0},
    {"Fe", 56.0},  {"Co", 59.0},  {"Ni", 59.0},  {"Cu", 63.5},  {"Zn", 65.0},
    {"Ag", 108.0}, {"Ba", 137.0}, {"Pt", 195.0}, {"Au", 197.0}, {"Hg", 201.0},
    {"I", 127.0}};

double getValue(string);

struct Part {
    string remain;
    int mul;
    vector<Part *> deeper;
    Part(string str, int n) {
        mul = n;
        stack<int> st;
        vector<pair<int, int>> d;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(')
                st.push(i);
            else if (str[i] == ')') {
                int x = st.top();
                st.pop();
                if (st.empty()) {
                    int t = 0;
                    if (i + 2 < str.length() && isdigit(str[i + 1]) &&
                        isdigit(str[i + 2])) {
                        t = (str[i + 1] - '0') * 10 + str[i + 2] - '0';
                        d.push_back(make_pair(x, i + 2));
                    } else if (i + 1 < str.length() && isdigit(str[i + 1])) {
                        t = str[i + 1] - '0';
                        d.push_back(make_pair(x, i + 1));
                    } else {
                        t = 1;
                        d.push_back(make_pair(x, i));
                    }
                    deeper.push_back(new Part(str.substr(x + 1, i - x - 1), t));
                }
            }
        }
        for (int i = d.size() - 1; i >= 0; i--) {
            str.erase(d[i].first, d[i].second - d[i].first + 1);
        }
        remain = str;
    }
    double getResult() {
        if (deeper.empty()) return getValue(remain) * double(mul);
        double ans = getValue(remain);
        for (auto i : deeper) {
            ans += i->getResult();
        }
        return ans * double(mul);
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
double getValue(string str) {
    if (!str.length()) return 0.00;
    double ans = 0.00;
    for (signed int i = 0; i < str.length();) {
        int mul;
        string elem;
        if (i + 3 < str.length() && isupper(str[i]) && islower(str[i + 1]) &&
            isdigit(str[i + 2]) && isdigit(str[i + 3])) {
            mul = (str[i + 2] - '0') * 10 + str[i + 3] - '0';
            // cout << str[i] << str[i + 1] << "is appended.\n";
            elem += str[i];
            elem += str[i + 1];
            i += 4;
        } else if (i + 2 < str.length() && isupper(str[i]) &&
                   isdigit(str[i + 1]) && isdigit(str[i + 2])) {
            mul = (str[i + 1] - '0') * 10 + str[i + 2] - '0';
            // cout << str[i] << "is appended.\n";
            elem += str[i];
            i += 3;
        } else if (i + 2 < str.length() && isupper(str[i]) &&
                   islower(str[i + 1]) && isdigit(str[i + 2])) {
            mul = str[i + 2] - '0';
            // cout << str[i] << str[i + 1] << "is appended.\n";
            elem += str[i];
            elem += str[i + 1];
            i += 3;
        } else if (i + 1 < str.length() && isupper(str[i]) &&
                   islower(str[i + 1])) {
            mul = 1;
            // cout << str[i] << str[i + 1] << "is appended.\n";
            elem += str[i];
            elem += str[i + 1];
            i += 2;
        } else if (i + 1 < str.length() && isupper(str[i]) &&
                   isdigit(str[i + 1])) {
            mul = str[i + 1] - '0';
            // cout << str[i] << "is appended.\n";
            elem += str[i];
            i += 2;
        } else if (isupper(str[i])) {
            mul = 1;
            // cout << str[i] << "is appended.\n";
            elem += str[i];
            i++;
        } else
            i++;
        // cout << elem << "," << mul << endl;
        if (!mp[elem]) {
            return -2147483648;
        } else {
            ans += double(mul) * mp[elem];
        }
    }
    return ans;
}

int main() {
    string s;

    cin >> s;
    while (s != "0") {
        Part *pt = new Part(s, 1);
        // pt->debug();
        double res = pt->getResult();
        if (res < 0.00)
            printf("UNKNOWN\n");
        else
            printf("%.2lf\n", res);
        cin >> s;
    }
    return 0;
}