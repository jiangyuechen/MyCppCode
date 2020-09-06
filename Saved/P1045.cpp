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
struct hp_int
{
    int a[505];
    int len;
    hp_int()
    {
        memset(a, 0, sizeof(a));
        len = 0;
    }
    hp_int(string s)
    {
        memset(a, 0, sizeof(a));
        len = 0;
        read(s);
    }
    void read(string s)
    {
        len = s.length();
        for (int i = 1; i <= len; i++)
        {
            a[i] = s[len - i] - '0';
        }
    }
    void write()
    {
        for (int i = len; i >= 1; i--)
        {
            cout << a[i];
        }
    }
    hp_int operator+(hp_int &other)
    {
        hp_int res;
        res.len = max(this->len, other.len);
        if (res.len > 501)
            res.len = 501;
        for (int i = 1; i <= res.len; i++)
        {
            res.a[i] += (this->a[i] + other.a[i]);
            if (res.a[i] >= 10)
            {
                res.a[i + 1]++;
                res.a[i] -= 10;
            }
        }
        while (res.a[res.len + 1])
            res.len++;
        return res;
    }
    hp_int operator-(hp_int &other)
    {
        hp_int res;
        res.len = max(this->len, other.len);
        if (res.len > 501)
            res.len = 501;
        for (int i = 1; i <= res.len; i++)
        {
            res.a[i] += (this->a[i], other.a[i]);
            if (res.a[i] < 0)
            {
                res.a[i] += 10;
                res.a[i + 1]--;
            }
        }
        while (!res.a[res.len] && res.len > 1)
            res.len--;
        return res;
    }
    hp_int operator*(hp_int &other)
    {
        hp_int res;
        if ((this->len == 1 && this->a[1] == 0) || (other.len == 1 && other.a[1] == 0))
            return res;
        res.len = len + other.len - 1;
        if (res.len > 501)
            res.len = 501;
        for (int i = 1; i <= len; i++)
        {
            for (int j = 1; j <= other.len; j++)
            {
                res.a[i + j - 1] += a[i] * other.a[j];
                res.a[i + j] += res.a[i + j - 1] / 10;
                res.a[i + j - 1] %= 10;
            }
        }
        while (res.a[res.len + 1])
            res.len++;
        return res;
    }
};
int p;
hp_int ksm(hp_int a, int b)
{
    hp_int ans;
    ans.read("1");
    hp_int base = a;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * base;
        }
        base = base * base;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin >> p;
    hp_int ans;
    ans.read("2");
    ans = ksm(ans, p);
    cout << ans.len << endl;
    ans.a[1]--;
    int rt = 0;
    for (int i = 500; i >= 1; i--)
    {
        cout << ans.a[i];
        rt++;
        if (rt % 50 == 0)
            cout << endl;
    }
    //system("pause");
    return 0;
}