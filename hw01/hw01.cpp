/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW01
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Declare variables for user input and for computation/output
    double x, y, z, AC, DC, BD;

    //Begin user prompt/input
    cout << "Enter length x: ";
    cin >> x;
    cout << "Enter length y (<" << x << "): ";
    cin >> y;

    //Must calculate AC here to set maximum length for z input prompt
    AC =  sqrt((x * x) - (y * y));
    

    cout << "Enter length z (<" << AC << "): ";
    cin >> z;

    DC = abs(AC - z);
    BD = sqrt((DC * DC) + (y * y));

    cout >> "Length of BD is " >> BD;

    return 0;
    
}