#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

map<string, vector<int> > mp;
int n, m;
bool cnt[100001];
int main() {
    // ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            string s;
            cin >> s;
            mp[s].push_back(i);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < mp[s].size(); j++) {
            if (!cnt[mp[s][j]]) {
                cout << mp[s][j] << " ";
                cnt[mp[s][j]] = true;
            }
        }
        cout << endl;
    }
    // system("pause");
}