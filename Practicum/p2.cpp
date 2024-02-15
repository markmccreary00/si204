/*
Filename: p2.cpp
Author: MIDN Mark McCreary (274230)
Practicum 1, Part 2
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;

    ifstream fin(filename);
    if(!fin){
        cout << "Error: Input file not found" << endl;
        return 1;
    }

    int test, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    while(fin >> test){
        if(test >= 10 && test <= 19)
            count1++;
        if(test >= 20 && test <= 29)
            count2++;
        if(test >= 30 && test <= 39)
            count3++;
        if(test >= 40 && test <= 49)
            count4++;
    }

    cout << "[10,19]: ";
    for(int i=0;i<count1;i++)
        cout << '*';
    cout << endl;

    cout << "[20,29]: ";
    for(int i=0;i<count2;i++)
        cout << '*';
    cout << endl;

    cout << "[30,39]: ";
    for(int i=0;i<count3;i++)
        cout << '*';
    cout << endl;

    cout << "[40,49]: ";
    for(int i=0;i<count4;i++)
        cout << '*';
    cout << endl;

    return 0;
}