/*
Filename: shift.cpp
Author: MIDN Mark McCreary (274230)
Project 1, Part 5
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //First need to read in relevant filenames & rowshift value
    string fg_filename, bg_filename, out_filename;
    int rowshift, columnshift;
    cout << "Foreground file: ";
    cin >> fg_filename;
    cout << "Background file: ";
    cin >> bg_filename;
    cout << "Row shift: ";
    cin >> rowshift;
    cout << "Column shift: ";
    cin >> columnshift;
    cout << "Output file: ";
    cin >> out_filename;

    //Open filestreams
    ifstream fin1(fg_filename), fin2(bg_filename);
    ofstream fout(out_filename);

    //Verify input files are accessible before proceeding
    if(!fin1 || !fin2){
        cout << "Error: Input file not found" << endl;
        return 1;
    }

     //Check if fg would exceed bg height/width limits
    string header;
    int fg_width, fg_height, bg_width, bg_height, max_value;
    fin1 >> header >> fg_width >> fg_height >> max_value;
    fin2 >> header >> bg_width >> bg_height >> max_value;
    if((fg_height + rowshift) > bg_height || (fg_width + columnshift) > bg_width){
        cout << "Error: The foreground goes past the background" << endl;
        return 1;
    }

    //Write header, height/width, max_value to output file
    fout << header << endl << bg_width << " " << bg_height << endl << max_value << endl;

    //Write "rowshift" # of bg rows
    for(int j=0;j<rowshift;j++){
         for(int i=0;i<(bg_width);i++){
            int r_bg, g_bg, b_bg;
            fin2 >> r_bg >> g_bg >> b_bg;
            fout << r_bg << " " << g_bg << " " << b_bg << " ";
        }
        fout << endl;
    }

    for(int j=0;j<fg_height;j++){
        //Begin row by writing "columnshift" # of bg pixels
        for(int i=0;i<columnshift;i++){
            int r_bg, g_bg, b_bg;
            fin2 >> r_bg >> g_bg >> b_bg;
            fout << r_bg << " " << g_bg << " " << b_bg << " ";
        }
        //Run comparison for "fg_width" # of pixels
        for(int i=0;i<fg_width;i++){
            int r_fg, g_fg, b_fg, r_bg, g_bg, b_bg;
            fin1 >> r_fg >> g_fg >> b_fg;
            fin2 >> r_bg >> g_bg >> b_bg;
            //Check if fg pixel is green; if yes, write bg pixel, if not, write fg pixel
            if(r_fg == 0 && g_fg == max_value && b_fg == 0)
                fout << r_bg << " " << g_bg << " " << b_bg << " ";
            else
                fout << r_fg << " " << g_fg << " " << b_fg << " ";
        }
        //Write bg pixel values for remainder of row since no fg to compare with
        for(int i=0;i<(bg_width-(fg_width + columnshift));i++){
            int r_bg, g_bg, b_bg;
            fin2 >> r_bg >> g_bg >> b_bg;
            fout << r_bg << " " << g_bg << " " << b_bg << " ";
        }
        fout << endl;
    }
    
    //Write remainder of bg data to all rows after fg comparison terminates
    for(int j=0;j<(bg_height - (fg_height + rowshift));j++){
        for(int i=0;i<(bg_width);i++){
            int r_bg, g_bg, b_bg;
            fin2 >> r_bg >> g_bg >> b_bg;
            fout << r_bg << " " << g_bg << " " << b_bg << " ";
        }
        fout << endl;
    }

    //Clean up, output success message
    cout << "Image saved to " << out_filename << endl;
    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}