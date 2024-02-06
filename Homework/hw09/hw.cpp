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
cout << "How many cookies? "; //read in user input
cin >> cookies;
initial = cookies;

while(cookies>0){ //loop only runs while cookies is positive and greater than zero
    cout << "Cookies eaten on day " << day << ": ";
    cin >> eaten;
    if(eaten>cookies){ // ensures user has enough cookies in jar to eat
        cout << "Not enough cookies!" << endl;
        return 0;
    }
    cookies -= eaten;
    if(eaten>piggiest){ // checks for if this run of loop was the piggiest run
        piggiest = eaten;
    }
    if(cookies>0){ //used if statement to ensure that day does not increment if user runs out of cookies
        day++;
    }
}

cout << "You ate " << initial << " cookies over " << day << " days." << endl; // return cookie eating statistics to user
cout << "On your piggiest day you ate " << piggiest << " cookies." << endl;
return 0;
}