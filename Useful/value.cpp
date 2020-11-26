#include <bits/stdc++.h>
using namespace std;
class Infected
{
private:
    double FusionRateOfSomaticCellAndSourceStone;
    double BloodSourceStoneCrystalDensity;

public:
    string Name;
    Infected()
    {
        FusionRateOfSomaticCellAndSourceStone = 0.00;
        BloodSourceStoneCrystalDensity = 0.00;
        Name = "";
    }
    Infected(double a, double b, string n)
    {
        FusionRateOfSomaticCellAndSourceStone = a;
        BloodSourceStoneCrystalDensity = b;
        Name = n;
    }
    double &Get_FusionRateOfSomaticCellAndSourceStone() { return this->FusionRateOfSomaticCellAndSourceStone; }
    double &Get_BloodSourceStoneCrystalDensity() { return this->BloodSourceStoneCrystalDensity; }
};
vector<Infected> v;
double get_average_of_FusionRateOfSomaticCellAndSourceStone()
{
    double total = 0.00;
    for (int i = 0; i < v.size(); i++)
    {
        total += v[i].Get_FusionRateOfSomaticCellAndSourceStone();
    }
    return total / (double)v.size();
}
double get_average_of_BloodSourceStoneCrystalDensity()
{
    double total = 0.00;
    for (int i = 0; i < v.size(); i++)
    {
        total += v[i].Get_BloodSourceStoneCrystalDensity();
    }
    return total / (double)v.size();
}
int main()
{
    // freopen("value.in", "r", stdin);
    // freopen("value.out", "w", stdout);
    double A, B;
    string str;
    cin >> A >> B >> str;
    while (A != -1.00 && B != -1.00)
    {
        Infected x = Infected(A, B, str);
        v.push_back(x);
        cin >> A >> B >> str;
    }
    printf("%.4lf\n%.4lf\n", get_average_of_FusionRateOfSomaticCellAndSourceStone(), get_average_of_BloodSourceStoneCrystalDensity());
    system("pause");
    return 0;
}