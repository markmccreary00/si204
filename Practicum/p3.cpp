/*
Filename: p3.cpp
Author: MIDN Mark McCreary (274230)
Practicum 1, Part 3
*/

#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;

    
    for(int r=0;r<(num/2);r++){
        for(int j=0;j<r;j++)
            cout << "."; 
        cout << "@";
        for(int j=0;j<(num-(2*r)-2);j++)
            cout << ".";
        cout << "@";
        for(int j=0;j<r;j++)
            cout << ".";
        cout << endl;
    }

    if(num % 2 != 0){
        for(int j=0;j<(num/2);j++)
            cout << ".";
        cout << "@";
        for(int j=0;j<(num/2);j++)
            cout << ".";
        cout << endl;

        for(int r=0;r<(num/2);r++){
        for(int j=0;j<((num/2)-(r+1));j++)
            cout << "."; 
        cout << "@";
        for(int j=0;j<((2*r)+1);j++)
            cout << ".";
        cout << "@";
        for(int j=0;j<((num/2)-(r+1));j++)
            cout << ".";
        cout << endl;
        }
    }
    else{
        for(int j=0;j<((num/2)-1);j++)
            cout << ".";
        cout << "@@";
        for(int j=0;j<((num/2)-1);j++)
            cout << ".";
        cout << endl;

        for(int r=0;r<((num/2)-1);r++){
        for(int j=0;j<((num/2)-(r+2));j++)
            cout << "."; 
        cout << "@";
        for(int j=0;j<((2*r)+2);j++)
            cout << ".";
        cout << "@";
        for(int j=0;j<((num/2)-(r+2));j++)
            cout << ".";
        cout << endl;
    }
    }

    
    return 0;
}
