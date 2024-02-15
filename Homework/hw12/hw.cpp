/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW12
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //First step, read in user parameters
    int height, width, offset;
    cout << "Enter height (greater than 2): ";
    cin >> height;
    cout << "Enter width  (greater than 2): ";
    cin >> width;
    cout << "Enter offset: ";
    cin >> offset;

    for(int i=0;i<height;i++){ //For loop to print "height" amount of rows
        for(int s=0;s<offset;s++) //At beginning of, row, insert offset
            cout << " ";
        if(i==0 || i==(height-1)){ //First and last row should be solid stars
            for(int w=0;w<width;w++)
                cout << '*';
            cout << endl;
        }
        else{ //Middle rows should start and end with stars, middle should be spaces
            cout << "*";
            for(int w=0;w<(width-2);w++)
                cout << " ";
            cout << '*' << endl;
        }
    }

    return 0;
}