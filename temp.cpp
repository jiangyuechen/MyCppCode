#include <bits/stdc++.h>
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

unsigned short Hash(void *p)
{
    unsigned int val = reinterpret_cast<unsigned int>(p);
    return (unsigned short)(val ^ (val >> 16));
}

int main(void)
{
}