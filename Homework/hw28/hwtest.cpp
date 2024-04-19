#include <iostream>
using namespace std;

char fun(int x);

int main()
{
  fun(3);
  cout << "KITTENS" << endl;
  fun(5);
  return 0;
}

char fun(int x)
{
  if (x <= 2)
  {
    cout << "meow" << endl;
    return 'A';
  }
  else
  {
    char letter = fun(x-1);
    cout << letter << " " << x << endl;
    return (letter + 1);
  }
}