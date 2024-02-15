/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB04 Part 2
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename, dump;
    cin >> filename;

    ifstream fin(filename);
    double degc, sumc, avgc, minc, maxc;
    minc = 10000;
    maxc = -10000;
    string date, mindate, maxdate;
    int count = 0;
    

    if(!fin)
    {
        cout << "Could not open file '" << filename << "'";
        return 1;
    }

    fin >> dump >> dump;
    while (fin >> date >> dump >> degc) {
        if (degc > maxc) {
            maxc = degc;
            maxdate = date;
            }
        if (degc < minc) {
            minc = degc;
            mindate = date;
            }
        
        sumc += degc;
        count++;
    }

    avgc = sumc / count;

    cout << "file: " << filename << endl;
    cout << "ave: " << (avgc * 9/5) + 32 << endl;
    cout << "min: " << (minc * 9/5) + 32 << " on " << mindate << endl;
    cout << "max: " << (maxc * 9/5) + 32 << " on " << maxdate << endl;

    fin.close();
    return 0;

}