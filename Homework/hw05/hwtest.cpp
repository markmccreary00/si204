#include <iostream>
#include <cmath>
using namespace std;

int main()
{

string s, t, r;

cin >> s;
if( s == "hello" )
{
  cin >> t;
  string s;
  s = s + "." + t + ".world";
}

cin >> r;
s = s + "." + r + ".programmers";
cout << s << endl;

return 0;
}