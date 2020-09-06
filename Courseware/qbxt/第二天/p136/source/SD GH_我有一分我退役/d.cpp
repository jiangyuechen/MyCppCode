#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

signed main()
{
    srand(time(0));
    int a,temp=0;
    while (cin>>a)
    {
        temp=temp*a+a;
    }
    cout<<temp%rand();
    return 0;
}