/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW16
*/

#include <iostream>
using namespace std;

int gcd(int q1, int q2)
{
    int big = (q1 >= q2) ? q1 : q2;
    int small = (q1 <= q2) ? q1 : q2;
    int remainder;
    
    while((big % small) > 0)
    {
        remainder = big % small;
        big = small;
        small = remainder;
    }

    return small;
}

int main()
{
    int num1, num2;
    char dump, term;

    while(cin >> num1 >> dump >> num2 >> term)
    {
        if(gcd(num1, num2) == 1)
            cout << num1 << '/' << num2 << " is in lowest terms!" << endl;  
        if(term == ';')
            break;
    
    }
    return 0;
}