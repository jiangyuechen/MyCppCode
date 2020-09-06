#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int rand_=rand();
    for (register int i=1;i<=rand_;i++)
    {
        srand(rand());
    }
    while (cin>>rand_);
    cout<<rand()%19260817<<' '<<rand()%19260817;
    return 0;
}