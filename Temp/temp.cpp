#include <bits/stdc++.h>
#include <future>
using namespace std;
constexpr int MAXN = 1000001;
int a[MAXN], n;

class Origin
{
private:
    char name[1001];

public:
    Origin(const char *_n);
    ~Origin();
};

Origin::Origin(const char *_n)
{
    strcpy(name, _n);
}

Origin::~Origin()
{
    delete[] name;
}

int main(void)
{
    const double pi = acos(-1);
}