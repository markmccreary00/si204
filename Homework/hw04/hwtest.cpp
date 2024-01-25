#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char c1, c2;
string s1, s2;

cin >> c1;
if( c1 <= 'Z' )
{
  cin >> c2;
  if( c2 <= 'Z' )
  {
    cin >> s1;
    cout << c1 << c2 << s1 << endl;
  }
}
else
{
  if( c1 >= 'a' )
  {
    cin >> s1 >> s2;
    cout << c1 << s1 << " " << s2 << endl;
  }
  else
  {
    cout << c1 << endl;
  }
};
}




