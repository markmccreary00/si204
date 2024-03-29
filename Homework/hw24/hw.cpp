/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW23
*/

#include <iostream>
using namespace std;

struct Point3
{
  double x, y, z;
};

istream& operator>> (istream& is, Point3& p);
ostream& operator<< (ostream& os, Point3 p);
double operator* (Point3 a, Point3 b);


int main()
{
  Point3 a, b;

  cin >> a >> b;

  cout << "Inner product of " << a << " and " << b
       << " is " << a*b << endl;

  return 0;
}

istream& operator>> (istream& is, Point3& p)
{
    char c;
    return is >> c >> p.x >> c >> p.y >> c >> p.z >> c;
}

ostream& operator<< (ostream& os, Point3 p)
{
    return os << '(' << p.x << ", " << p.y << ", " << p.z << ')';
}

double operator* (Point3 a, Point3 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); 
}