#include <iostream>
#include <list>

using namespace std;
int main()
{
   __int128_t x = 13822139291821039839812903218932;
   list<int> l = list<int>{1, 1, 0, 0, 1, 0, 1, 1};
   for (list<int>::iterator i = l.begin(); i != l.end(); i++)
   {
      if ((*i) == 1)
         i = l.erase(i);
   }
   for (list<int>::iterator i = l.begin(); i != l.end(); i++)
   {
      cout << *i << endl;
   }
   system("pause");
}