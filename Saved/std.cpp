#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
inline int read() {
    int s = 0, w = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1; ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
#define END_PROGRAM  \
    system("pause"); \
    return 0;
using namespace std;
const int MAXN = 1001;
int a[MAXN], k, t, n;
int ABS(int a) {
    return a>0?a:-a;
}
int main()
{
    t=read();
    while (t--) {
        n=read();
        k=read();
        int ans=0;
        for (int i=1;i<=n;i++) {
            a[i]=read();
        }
        for (int i=1;i<=n;i++) {
            int l, r;
            if (i==1) l=2, r=n;
            else if (i==n) l=1, r=n-1;
            else l=1, r=n;
            ans=ABS(a[l]+a[r]+i-k);
            if (ans==0)
            {
                printf("0");
                break;
            }
            while (l<r-1) {
                int ar=ABS(a[l+1]+a[r]+i-k), br=ABS(a[l]+a[r-1]+i-k);
                if (l==i) {
                    l++;
                    continue;
                }
                if (r==i) {
                    r--;
                    continue;
                }
                //cout<<l<<","<<r<<":ar:"<<ar<<" br:"<<br<<endl;
                if (ar<br) {
                    l++;
                    ans=min(ans, ar);
                }
                else {
                    r--;
                    ans=min(ans, br);
                }
            }
        }
        printf("%d\n", ans);
    }
    END_PROGRAM
}