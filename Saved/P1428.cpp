#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 101;
int a[MAXN], ans[MAXN];
int n;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<i;j++) {
            if (a[j]<a[i]) ans[i]++;
        }
    }
    for (int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    END_PROGRAM
}
// Eyjáfjállajôkulle