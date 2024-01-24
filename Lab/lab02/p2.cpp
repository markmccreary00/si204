/*
Filename: p2.cpp
Author: MIDN Mark McCreary (274230)
LAB02 Part 2
*/

#include <iostream>
using namespace std;

int main()
{
    //Read in decimal input
    int user_input;
    cout << "Enter a number between 0 and 15: ";
    cin >> user_input;

    // Compute bit values
    bool MSB, bit3, bit2, LSB;
    MSB = int(user_input / 8);
    bit3 = int((user_input - (8 * MSB)) / 4) ;
    bit2 = int((user_input - (8 * MSB) - (4 * bit3)) / 2);
    LSB = (user_input % 2);

    //Psuedo-concatonate bit values, return binary value to user
    cout << user_input << " in binary is " << MSB << bit3 << bit2 << LSB << endl;

    return 0;
}