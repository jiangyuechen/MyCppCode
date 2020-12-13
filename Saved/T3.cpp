#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
string str;
int n, m;

int main()
{
    std::mt19937 random(111111);
    cout << random() << endl;
    n = read();
    m = read();
    cin >> str;
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}