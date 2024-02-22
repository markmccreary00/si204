/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB06 Part 2
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

int throwdice();
int throwdice()
{
    int n1, n2, sum;
    n1 = rolldie();
    n2 = rolldie();
    sum = n1 + n2;
    cout << "Player rolled " << n1 << " + " << n2 << " = " << sum;

    if(sum == 7 || sum == 11 || sum == 2 || sum == 3 || sum == 12)
    {
        if(sum == 2 || sum == 3 || sum == 12)
            return -1;
        else
            return 0;
    }
    else
        return sum;

}



int main()
{
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);

    int flag;
    do
    {
        flag = throwdice();
        if(flag == -1 || flag == 0)
        {
            if(flag == -1)
                cout << " House wins!" << endl;
            if(flag == 0)
                cout << " Player wins!" << endl;
        }
        else
            cout << " roll again" << endl;
    }
    while(flag != -1 && flag != 0);

    return 0;
}

