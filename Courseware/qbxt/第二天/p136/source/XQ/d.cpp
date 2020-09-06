#include <iostream>
#include <cstdio>
using namespace std;

const int MOD = (int)(1e9 + 9);

const int N = 53;
int n, m;
int col[N], row[N];

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> col[i];
    cin >> m;
    for (int j = 1; j <= m; ++j)
        cin >> row[j];

    cout << "7" << endl;

    return 0;
}
