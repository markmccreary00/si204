/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW23
*/

#include <iostream>
#include <fstream>
using namespace std;

struct car
{
    char tag;
    double init, vel;
};

void givePos(car* data, int , int hr);

int main()
{
    string filename;
    cin >> filename;
    ifstream fin(filename);

    string dump;
    int n;

    fin >> dump >> dump >> n;

    car* data = new car[n];

    for(int l = 0 ; l < n ; l++)
        fin >> data[l].tag >> dump >> data[l].init >> dump >> data[l].vel;

    for(int hr = 0 ; hr < 9 ; hr++)
    {
        cout << "hour " << hr << " ";
        givePos(data, n, hr);
    }
    return 0;
}

void givePos(car* data, int n, int hr)
{
    for(int i = 0 ; i < n ; i++)
        cout << "[" << data[i].tag << ":" << data[i].init + hr * (data[i].vel) << "]";
    cout << endl;
    return;
}