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

    //Compute value of MSB
    int b4_msb_dec;
    bool b4_msb_bool;
    b4_msb_dec = (user_input
    b4_msb_bool = b4_msb_dec;

    //Compute value of bit 3
    int b3_dec;
    bool b3_bool;
    b3_dec = (user_input
    b3_bool = b3_dec;

    //Compute value of bit 2
    int b2_dec;
    bool b2_bool;
    b2_dec = (user_input
    b2_bool = b2_dec; 

    //Compute value of LSB
    int b1_lsb_dec;
    bool b1_lsb_bool;
    b1_lsb_dec = (user_input
    b1_lsb_bool = b2_dec;

    cout << "First three bits are " << b4_msb_bool << b3_bool << b2_bool << endl;

   

    return 0;
}