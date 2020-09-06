#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long int CULL;
void doit(CULL n, CULL k, int rev)
{
    if (n == 0)
        return;
    CULL x = 1 << (n - 1) ;
    if (k < x)
    {
        cout << (0 ^ rev);
        doit(n - 1, k, 0);
    }
    else
    {
        cout << (1 ^ rev);
        doit(n - 1, k - x , 1);
    }
}
CULL N, K;
int main()
{
    cin >> N ;//>> K;
    for(int i=0;i<(1<<N);i++){
        doit(N,i,0);
        cout<<endl;
    }
    system("pause");
    return 0;
}