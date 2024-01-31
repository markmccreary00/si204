#include <iostream>
#include <cmath>
using namespace std;

int main()
{

int p;
p = 1;
cout << &p << endl;
{
  int p;
  cout << &p << endl;
}
cout << &p << endl;

return 0;
}