/*
Filename: readppm.cpp
Author: MIDN Mark McCreary (274230)
Project 1, Part 1
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){ //Read in filename
    string filename;
    cout << "Input file: ";
    cin >> filename;
    ifstream fin(filename);

    if (!fin){ //Verify file is accessible before proceeding
        cout << "File " << filename << " not found!" << endl;
        return 1;
    }

    string header; //Declare variables for non-recursive ppm file elements & read in; return before beginning to read recursive elements
    int width, height, max_value;
    fin >> header >> width >> height >> max_value;
    cout << header << endl;
    cout << "width = " << width << ", height = " << height << endl;
    cout << "max value = " << max_value << endl;

    //Parent loop (rows) should have a child loop (each column). 
    //Parent loop will repeat until it reaches max height value.
    //Child loop outputs iteration of parent (row #), iteration of self (column #), reads the triplet of RGB values and outputs accordingly until it reaches the max width value. 
    
    for(int row=0;row<height;row++){
        cout << "*** row " << row << " ***" << endl;
        for(int column=0;column<width;column++){
            int r, g, b;
            fin >> r >> g >> b;
            cout << "row " << row << ", col " << column << ": r" << r << " g" << g << " b" << b << endl;
        }
    }
    return 0;
}