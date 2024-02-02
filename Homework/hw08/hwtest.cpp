#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("food.txt");
int count = 0;
char c = 'x';
while(fin)
{
  if (c == '?')
    count = count + 1;
  fin >> c;
}

cout << count << endl;
}