/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB04 Part 3
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename, outputname, dump;
    cin >> filename >> outputname;

    ifstream fin(filename);
    ofstream fout(outputname);
    double degc, sumc, avgc, minc, maxc;
    minc = 100;
    maxc = -100;
    string date, mindate, maxdate;
    int count = 0, hour = 1;

    if(!fin)
    {
        cout << "Could not open file '" << filename << "'" << endl;
        return 1;
    }
    if(!fout)
    {
        cout << "Could not create output file '" << outputname << "'" << endl;
        return 1;
    }
    fout << "day	hour	temp" << endl;
    
    fin >> dump >> dump;
    while (fin >> date >> dump >> degc) {
        fout << date << "	" << hour << "	" << ((degc * 9/5) + 32) << endl;
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

        if(hour < 24)
            hour++;
        else
            hour = 1;
    }

    avgc = sumc / count;

    cout << "file: " << filename << endl;
    cout << "ave: " << (avgc * 9/5) + 32 << endl;
    cout << "min: " << (minc * 9/5) + 32 << " on " << mindate << endl;
    cout << "max: " << (maxc * 9/5) + 32 << " on " << maxdate << endl;
    cout << "output in: " << outputname << endl;

    fin.close();
    fout.close();
    return 0;

}