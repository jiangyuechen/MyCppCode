#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int k, w, s;
struct gold
{
    int value;
    int weight;
    double average;
} a[1000];
bool comp(gold p, gold q)
{
    return p.average > q.average;
}
int main()
{
    memset(a, 0, sizeof(a));
    cin >> s >> w;
    for (int i = 1; i <= s; i++)
    {
        cin >> a[i].weight >> a[i].value;
        a[i].average = (double)a[i].value / a[i].weight;
    }
    sort(a + 1, a + s + 1, comp);
    int now = 0;
    int p = 0;
    double val = 0.0;
    while (now < w && p <= s)
    {
        if (now + a[p].weight <= w)
        {
            now += a[p].weight;
            val += a[p].value;
        }
        else
        {
            val += a[p].average * (w - now);
            now = w;
        }
        p++;
    }
    printf("%.2lf\n", val);
    //system("pause");
    return 0;
}