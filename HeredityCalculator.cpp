#include <iostream>
#include <vector>
using namespace std;
constexpr int s = 1 * 2 * 3 * 4;

class Bio;
class Chromosome;
class ChromosomeSet;    // 染色体组
class SexualChromosome; // 性染色体
class Autosome;         // 常染色体
class Bio
{
private:
   vector<Chromosome> chrset;

public:
};

class AsexualBio; // 无性别分化的生物
class SexualBio;  // 有性别分化的生物

class Chromosome
{
};
class SexualChromosome : public Chromosome
{
};
class Autosome : public Chromosome
{
};

class Gene
{
protected:
   string name;

public:
};

class Trait
{
};

int main() {}