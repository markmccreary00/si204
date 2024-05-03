/************************************************
p1.cpp

DO NOT DELETE ANY CODE BELOW. 
Only add code as necessary.
*************************************************/

#include <iostream>
using namespace std;

struct position
{
  int row, col;
};

struct movement
{
  char dir;
  int length;
};

istream& operator>> (istream& in, position& p);
istream& operator>> (istream& in, movement& v);
ostream& operator<< (ostream& out, position p);
position operator+ (position p, movement v);

int main()
{
  position p; 
  cout << "position? ";
  cin >> p;

  cout << "how many moves? ";
  int n; 
  cin >> n;

  for(int i=0; i<n; i++)
  {
    movement v;
    cin >> v;
    p = p + v;
    cout << p << endl;
  }

  return 0;
}

istream& operator>> (istream& in, position& p){
    char c;
    return in >> c >> p.row >> c >> p.col >> c;
}

istream& operator>> (istream& in, movement& v){
    return in >> v.dir >> v.length;
}

ostream& operator<< (ostream& out, position p){
    return out << '(' << p.row << ',' << p.col << ')';
}

position operator+ (position p, movement v){
    if(v.dir == 'N')
        p.row -= v.length;
    else if(v.dir == 'S')
        p.row += v.length;
    else if(v.dir == 'E')
        p.col += v.length;
    else   
        p.col -= v.length;

    return p;
}