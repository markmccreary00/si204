/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW03
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //Read in length 1 and 2
    int f1, i1, f2, i2;
    char dump;
    cout << "Enter two lengths in feet and inches (larger first!)" << endl;
    cin >> f1 >> dump >> i1 >> dump;
    cin >> f2 >> dump >> i2 >> dump;

    //Compute difference & return result
    double x, y, x_in, y_in, delta_xy;
    int output_ft, output_in;
    x_in = double(i1 / 12.0);
    y_in = double(i2 / 12.0);
    x = f1 + x_in;
    y = f2 + y_in;
    delta_xy = x - y;
    output_ft = delta_xy;
    output_in = (delta_xy - output_ft) * 12;

    cout << "Difference is " << output_ft << " ' " << output_in << " \" ";
    return 0;

}
