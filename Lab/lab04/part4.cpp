/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB04 Part 4
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
    string date, mindate, maxdate, lastdate;
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
    
    fin >> dump >> dump;
    while (fin >> date >> dump >> degc) {

        if(date==lastdate)
            fout << "	" << ((degc * 9/5) + 32);
        else{
            if(count==0)
                fout << date << "	" << ((degc * 9/5) + 32);
            else
                fout << endl << date << "	" << ((degc * 9/5) + 32);
        }
            
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
        lastdate = date;
    }
    fout << endl;
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