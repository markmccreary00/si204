/*
Filename: p1.cpp
Author: MIDN Mark McCreary (274230)
Project 2, Part 1
*/

#include <iostream>
using namespace std;

int main()
{
    int* deck = new int[52];
    for(int face = 1; face <= 4 ; face++)
    {
        for(int suit = 2; suit <= 14 ; suit++)
        deck[ ((face-1) * 13) + (suit - 2) ] = (100 * face) + suit;
    }
    cout << '[';
    for(int i = 0; i < 52 ; i++)
    {
        cout << deck[i];
        if(i != 51)
            cout << ' ';
    }
    cout << ']' << endl;
    return 0;
}