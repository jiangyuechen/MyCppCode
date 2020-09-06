#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    if (m == 1)
        cout << n << endl;
    else
        cout << (int)exp(log(n) / m) << endl;
    system("pause");
    return 0;
}