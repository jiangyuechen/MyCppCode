#include <iostream>

class Pain
{
public:
    int Intensity;
    std::string Description;
    Pain() : Intensity(0), Description() {}
    Pain(int _i, std::string _d) : Intensity(_i), Description(_d) {}
};
void Suffer(Pain &p)
{
    std::cout << "I'm suffering " << p.Description << "!" << std::endl;
}

int main()
{
    int (*fp)(int, int) = [&](int a, int b)
    { return a + b; };
    Pain p = Pain(1, "Mental Pain");
    Suffer(p);
    return 0;
}