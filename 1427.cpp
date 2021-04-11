#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

priority_queue<int, vector<int>, greater<int> > qmin;
priority_queue<int, vector<int>, less<int> > qmax;
int n;
int MinNum, MaxNum;
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        qmin.push(x);  // 进入队列
        qmax.push(x);
    }
    while (qmin.size() != 1) {
        int s = qmin.top();
        qmin.pop();
        int t = qmin.top();
        qmin.pop();
        qmin.push(s * t + 1);
    }
    MinNum = qmin.top();
    while (qmax.size() != 1) {
        int s = qmax.top();
        qmax.pop();
        int t = qmax.top();
        qmax.pop();
        qmax.push(s * t + 1);
    }
    MaxNum = qmax.top();
    printf("%d\n", -MaxNum + MinNum);
    system("pause");
    return 0;
}