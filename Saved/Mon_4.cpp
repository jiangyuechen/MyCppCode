#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int a_origin_1[MAXN], a_origin_2[MAXN];
int n, q;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a_origin_1[i] = a_origin_2[i] = a[i];
    }
    while (q--)
    {
        int op, l1, r1, l2, r2;
        cin >> op;
        if (op == 1)
        {
            cin >> l1 >> r1 >> l2 >> r2;
            sort(a_origin_1 + l1, a_origin_1 + r1 + 1);
            sort(a_origin_2 + l2, a_origin_2 + r2 + 1);
            int k = a_origin_1[l1] - a_origin_2[l2];
            bool flag = false;
            for (int i = l1, j = l2; i <= r1 && j <= r2; i++, j++)
            {
                //cout<<"K:"<<a_origin_1[i]-a_origin_2[j]<<endl;
                if (a_origin_1[i] - a_origin_2[j] != k)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            for (int i = l1, j = l2; i <= r1 && j <= r2; i++, j++)
            {
                a_origin_1[i] = a[i];
                a_origin_2[j] = a[j];
            }
        }
        else
        {
            cin >> l1 >> r1;
            a[l1] = a_origin_1[l1] = a_origin_2[l1] = r1;
        }
    }
    system("pause");
    return 0;
}