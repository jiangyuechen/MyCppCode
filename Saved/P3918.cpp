#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 10001;
int a[MAXN];
int n, k, ans;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1;i<=k;i++) {
        scanf("%d", a+i);
    }
    sort(a+1, a+k+1, greater<int>());
    int l=1, r=n;
    while (l<r) {
        ans+=a[l]*(r-l);
        l++;
        r--;
    }
    printf("%d\n", ans);
    END_PROGRAM
}