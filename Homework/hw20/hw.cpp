/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW20
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "How many legs? ";
    int n;
    cin >> n;

    string* cities = new string[n+1];

    for(int i = 0; i < n ; i ++)
    {
        string working, temp1;
        cin >> working;

        //Store first city in leg in temp string
        for(int j = 0 ; j < 3 ; j++)
            temp1 += working[j];

        //If more than one leg, checks temp string against last city entry for mismatch
        if(n>1 && i > 0)
        {
            if(temp1 != cities[i])
            {
                cout << "city mismatch" << endl;
                return 1;
            }
        }

        cities[i] = temp1; //Redundant except for when i = 0; must set cities[0] equal to temp1 for above comparison to work
        
        //Store second city in cities[i+1]
        for(int j = 5 ; j >= 5 && j < 8 ; j++)
            cities[i+1] += working[j];
    }

    cout << "Reverse trip: ";
    for(int i = n ; i >= 0 ; i--)
    {
        cout << cities[i];
        if(i>0)
            cout << "->"; //Places arrow after all cities but last city
    }
    cout << endl;
    delete[] cities;
    return 0;
    
}