#include <bits/stdc++.h>
long long read()
{
    long long ans = 0;
    char last = ' ', ch = getchar();
    while (ch < '0' || ch > '9')
    {
        last = ch;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = (ans << 3) + (ans << 1) + (ch ^ 48);
        ch = getchar();
    }
    return last == '-' ? -ans : ans;
}
long long test;
clock_t start, end;
int main()
{
    start = clock();
    for (int i = 1; i <= 10000000; i++)
    {
        std::cin >> test;
    }
    end = clock();
}