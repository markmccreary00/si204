/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW04
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //Read in user input
    char C1, C2, C3;
    cout << "Input a 3-letter word in uppercase letters: " ;
    cin >> C1 >> C2 >> C3;

    //Process characters from upper to lowercase
    cout << "Output: " << char(C1 + 32) << char(C2 + 32) << char(C3 + 32) << endl;

    return 0;
}