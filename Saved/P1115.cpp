#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 200002;
int a[MAXN];
int n, ans, tmp;
int main()
{
    void* p = malloc(10);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];

        tmp+=a[i];
        if (tmp>ans) tmp=0;
        if (tmp<0) tmp=0;
    }
    END_PROGRAM
}