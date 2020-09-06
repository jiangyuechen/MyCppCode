#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
map<string, int> stu;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int op, k;
        string name;
        cin >> op;
        if (op == 1)
        {
            cin >> name >> k;
            auto it = stu.find(name);
            if (it != stu.end())
            {
                it->second = k;
            }
            else
            {
                stu.insert(make_pair(name, k));
            }
            cout << "OK" << endl;
        }
        else if (op == 2)
        {
            cin >> name;
            auto it = stu.find(name);
            if (it != stu.end())
            {
                cout << it->second << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if (op == 3)
        {
            cin >> name;
            auto it = stu.find(name);
            if (it != stu.end())
            {
                stu.erase(it);
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else
        {
            cout << stu.size() << endl;
        }
    }
    return 0;
}