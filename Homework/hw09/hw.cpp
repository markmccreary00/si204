/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW09
*/

#include <iostream>

using namespace std;

int main()
{
int cookies, initial, eaten, piggiest = 1, day = 1;
cout << "How many cookies? ";
cin >> cookies;
initial = cookies;

while(cookies>0){
    cout << "Cookies eaten on day " << day << ": ";
    cin >> eaten;
    if(eaten>cookies){
        cout << "Not enough cookies!" << endl;
        return 0;
    }
    cookies -= eaten;
    if(eaten>piggiest){
        piggiest = eaten;
    }
    if(cookies>0){
        day++;
    }
}

cout << "You ate " << initial << " cookies over " << day << " days." << endl;
cout << "On your piggiest day you ate " << piggiest << " cookies." << endl;
return 0;
}