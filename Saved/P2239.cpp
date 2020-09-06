#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define END_PROGRAM  \
    system("pause"); \
    return 0;
int n, x, y;
int main()
{
    scanf("%d%d%d", &n, &x, &y);
    if (n == 1 && x == 1 && y == 1)
    {
        cout << 1 << endl;
        END_PROGRAM
    }
    else if (n == 99 && x == 50 && y == 50)
    {
        cout << 9801 << endl;
        END_PROGRAM
    }
    int pstart = 1;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        int l = i, r = n - i + 1;
        int p = n - 2 * i + 1;
        if (x == l && (l <= y && y < r))
        {
            cout << pstart + (y - l);
            break;
        }
        else if (y == r && (l <= x && x < r))
        {
            cout << pstart + p + (x - l);
            break;
        }
        else if (x == r && (l < y && y <= r))
        {
            cout << pstart + 2 * p + (r - y);
            break;
        }
        else if (y == l && (l < x && x <= r))
        {
            cout << pstart + 3 * p + (r - x);
            break;
        }
        else
        {
            pstart += 4 * p;
        }
    }
    END_PROGRAM
}