#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define re register
using namespace std;
int a[100001], l[100001], r[100001];
int n, m;
int check(int num) {
    int r = 0, temp = 0;
    int head = 1;
    vector<int> breakpoints;
    breakpoints.push_back(1);
    for (int i = 1; i <= n; i++) {
        if (temp + a[i] <= num) {
            temp += a[i];
        } else {
            temp = a[i];
            r++;
        }
    }
    return r < m;
}
int main() {
    cin >> n >> m;
    int left = 0, right = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        right += a[i];
        left = max(left, a[i]);
    }
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (check(mid)) right = mid - 1;
        else left = mid + 1;
    }
    int num = m;
    l[1] = 1;
    r[m] = n;
    for (int i = n, cnt = 0; i >= 1; i--) {
        if (cnt + a[i] > left) {
            l[num] = i + 1;
            r[--num] = i;
            cnt = a[i];
        } else {
            cnt += a[i];
        }
    }
    for (int i = 1; i <= m; i++)
        cout << l[i] << " " << r[i] << '\n';
    return 0;
}
