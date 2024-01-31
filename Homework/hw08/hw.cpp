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

    if(!fin) //Check for valid filename.
        {
            cout << "Invalid file name!" << endl;
            return 1;
        }
    
    string best_name;
    double best_score = 0;

    string dump;
    fin >> dump >> dump >> dump >> dump; //Discard words in header of table.

    while(fin)
    {
        //Read in grade values & student name.
        string working_name;
        fin >> working_name;
        int hw, quiz, exam;
        fin >> hw >> quiz >> exam; 
       
       /*This next block was my friend's idea. I couldn't get the loop to stop when the 
       file ran out of data, this was his solution. He explained to me how .empty() is a 
       "member function" that returns the boolean state of whether the parent string is empty or not, 
       as well as using break to essentially skip the remainder of the block in execution.*/
        if (working_name.empty()) 
        {
            break;
        }

        //Calculate average, return name/average.
        double average = (0.2 * hw) + (0.2 * quiz) + (0.6 * exam);
        cout << working_name << "	" << average << endl;

        if(average > best_score) //This block tracks the best student by comparing their score to the previous best score in the class.
        {
            best_name = working_name;
            best_score = average;
        }
            
    }

    //Return best student's name.
    cout << "The best student is " << best_name << "." << endl;
    fin.close();

    return 0;
}