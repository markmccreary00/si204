/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW05
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
//Read in year
cout << "Enter year: ";
int year;
cin >> year;

//Build logic tree
if(year % 4 == 0)
{
    if(year % 100 == 0)
    {
        if(year % 400 == 0)
        {
            cout << "Is Leap Year" << endl;
        }
        else
        {
            cout << "Is Not Leap Year" << endl;
        }
    }   
    else
    {
       cout << "Is Leap Year" << endl; 
    }
}    
else
{
    cout << "Is Not Leap Year" << endl;
}

return 0;
}