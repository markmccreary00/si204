/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB06 Part 1
*/

#include <cstdlib>
#include <iostream>
using namespace std;

int rolldie();
int rolldie()
{
    int rng = 0;
    while(rng == 0 || rng == 7)
        rng = (rand() % 8);
    return rng;
}
int main()
{
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);

    for(int i = 0;i < 5;i++)
    {
        int n1 = rolldie();
        int n2 = rolldie();
        cout << "Player rolled " << n1 << " + " << n2 << " = " << (n1 + n2) << endl;
    }
}