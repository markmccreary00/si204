/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB06 Part 3
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

int throwdice(int setpoint);
int throwdice(int setpoint)
{
    int n1, n2, sum;
    n1 = rolldie();
    n2 = rolldie();
    sum = n1 + n2;
    cout << "Player rolled " << n1 << " + " << n2 << " = " << sum;
    
    if(setpoint == 0)
    {
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
    else
    {
        if(sum == setpoint)
            return 0;
        else
        {
            if(sum == 7 || sum == 12)
                return -1;
            else
                return sum;
        }
    }
   
}

char play();
char play()
{
    int flag, setpoint = 0, count = 0;

    do
    {
        flag = throwdice(setpoint);
        if(flag == -1 || flag == 0)
        {
            if(flag == -1)
                cout << " House wins!" << endl;
            else
                cout << " Player wins!" << endl;
        }
        else
        {
            if(count == 0)
            {
                cout << " setpoint is " << flag << '!' << endl;
                setpoint = flag;
            }
            else
                cout << " roll again" << endl;
            count++;
        }
    }
    while(flag != -1 && flag != 0);
    
    char cont;
    cout << "Play again? ";
    cin >> cont;
    return cont;
}

int main()
{
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);

    char cont;
    cont = play();
    while(cont == 'y')
        cont = play();
    return 0;
}

