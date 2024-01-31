/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW08
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Read in filename
    string filename;
    cout << "Filename: ";
    cin >> filename;
    ifstream fin(filename);

    if(!fin) //Check for valid filename
        {
            cout << "Invalid file name!" << endl;
            return 1;
        }
    
    string best_name;
    double best_score = 0;

    string dump;
    fin >> dump >> dump >> dump >> dump;

    while(fin)
        {
            string working_name;
            fin >> working_name;
            int hw, quiz, exam;
            fin >> hw >> quiz >> exam;
            double average = (0.2 * hw) + (0.2 * quiz) + (0.6 * exam);
            cout << working_name << "	" << average << endl;

            if(best_score > average)
            best_name = working_name;
        }

    cout << "The best student is " << best_name << "." << endl;
    fin.close();

    return 0;
}