/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW22
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "What size? ";
    int h, w;
    char dump;
    cin >> h >> dump >> w;

    int** grid = new int*[h];
    for(int i = 0 ; i < h ; i++)
        grid[i] = new int[w];

    for(int i = 0; i < h ; i++)
    {
        for(int j = 0 ; j < w ; j++)
            cin >> grid[i][j]; 
    }

    cout << "rows: ";
    for(int i = 0 ; i < h ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < w ; j++)
            sum += grid[i][j];
        if(sum % 3 == 0)
            cout << i << " ";
    }

    cout << endl << "cols: ";
    for(int i = 0 ; i < w ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < h ; j++)
            sum += grid[j][i];
        if(sum % 3 == 0)
            cout << i << " ";
    }
    cout << endl;

    delete[] grid;
    return 0;
}