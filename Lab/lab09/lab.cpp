/*
Filename: lab.cpp
Author: MIDN Mark McCreary (274230)
LAB09
*/

#include <iostream>
#include <fstream>
using namespace std;

double** getRatings();

int main()
{    
    string cmd;
    int ind;

    
    double** ratings = getRatings();

    while(cmd != "quit")
    {
        double sum = 0;
        int count = 0;
        cin >> cmd >> ind;
        if(cmd == "movie")
        {
            for(int i = 0 ; i < 610 ; i++)
            {
                sum += ratings[i][ind];
                if(ratings[i][ind]) //must only increment count if rating value exists (i.e not 0)
                    count++;
            }
            cout << sum/double(count) << endl;
        }
        else if(cmd == "user")
        {   
            for(int i = 0 ; i < 9724 ; i++)
            {
                sum += ratings[ind][i];
                if(ratings[ind][i])
                    count++;
            }
            cout << sum/double(count) << endl;
        }
        else
            break;
    }
    
    //clean up
    for(int i = 0 ; i < 610 ; i++)
        delete[] ratings[i];
    delete[] ratings;

    return 0;
}

double** getRatings()
{
    //declare array, set all values to 0
    double** ratings = new double*[610];
    for(int i = 0 ; i < 610 ; i++)
    {
        ratings[i] = new double[9724];
        for(int j = 0 ; j < 9724 ; j++)
            ratings[i][j] = 0;
    }

    //begin reading in ratings from file by handling header
    ifstream fin("ratings.tsv");
    string dump;
    fin >> dump >> dump >> dump; 
    
    int uid, mid;
    double rat;
    while(fin >> uid >> mid >> rat)
        ratings[uid][mid] = rat;
    
    fin.close();
    return ratings;
}