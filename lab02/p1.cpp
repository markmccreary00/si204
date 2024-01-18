/*
Filename: p1.cpp
Author: MIDN Mark McCreary (274230)
LAB02 Part 1
*/

#include <iostream>
using namespace std;

int main()
    {
        //Read in 4 bit user input
        char c1_lsb, c2, c3, c4_msb;
        cout << "Enter a 4-bit binary number:";
        cin >> c4_msb >> c3 >> c2 >> c1_lsb;

        //Store input for output prompt
        string user_input;
        user_input = c4_msb;
        user_input += c3;
        user_input += c2;
        user_input += c1_lsb;

        //Extract each bit from input
        int b1_lsb, b2, b3, b4_msb;
        b4_msb = c4_msb - 48;
        b3 = c3 - 48;
        b2 = c2 - 48;
        b1_lsb = c1_lsb - 48;

        //Compute decimal values from bit values & summate for output
        int d1_lsb, d2, d3, d4_msb, d_out;
        d4_msb = 8 * b4_msb;
        d3 = 4 * b3;
        d2 = 2 * b2;
        d1_lsb = 1 * b1_lsb;
        d_out = d4_msb + d3 + d2 + d1_lsb;

        //Return output to user
        cout << "In decimal " << user_input << " = " << d_out << endl;

        return 0;

    }
