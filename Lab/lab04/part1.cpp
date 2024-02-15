/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB04 Part 1
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string filename, dump;
    cin >> filename;

    ifstream fin(filename);
    double degc, sumc, avgc;
    int count = 0;

    if(!fin)
    {
        cout << "Could not open file '" << filename << "'";
        return 1;
    }

    fin >> dump >> dump;
    while (fin >> dump >> dump >> degc) {
        sumc += degc;
        count++;
    }

    avgc = sumc / count;

    cout << "file: " << filename << endl;
    cout << "ave: " << (avgc * 9/5) + 32 << endl;

    fin.close();
    return 0;

}