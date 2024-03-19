/*
Filename: gray.cpp
Author: MIDN Mark McCreary (274230)
Project 1, Part 2
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){ //Read in in_filename and out_filename
    string in_filename, out_filename;
    cout << "Input file: ";
    cin >> in_filename;
    cout << "Output file: ";
    cin >> out_filename;
    ifstream fin(in_filename);
    ofstream fout(out_filename);

    if (!fin){ //Verify in_filename is accessible before proceeding
        cout << "Error: Input file not found" << endl;
        return 1;
    }

    string header; //Declare variables for non-recursive ppm file elements & read in; return before beginning to read recursive elements
    int width, height, max_value;
    fin >> header >> width >> height >> max_value;
    fout << header << endl << width << " " << height << endl << max_value << endl;
    

    //Parent loop (rows) should have a child loop (each column). 
    //Parent loop will repeat until it reaches max height value. 
    
    for(int row=0;row<height;row++){
        for(int column=0;column<width;column++){
            int r, g, b, gray;
            fin >> r >> g >> b;
            gray = (r + g + b)/3;
            for(int i=0;i<3;i++)
                fout << gray << " ";
        }
    }
    cout << "Image saved to " << out_filename << endl;
    fin.close();
    fout.close();
    return 0;
}