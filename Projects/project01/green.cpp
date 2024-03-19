/*
Filename: green.cpp
Author: MIDN Mark McCreary (274230)
Project 1, Part 3
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //First need to read in relevant filenames
    string fg_filename, bg_filename, out_filename;
    cout << "Foreground file: ";
    cin >> fg_filename;
    cout << "Background file: ";
    cin >> bg_filename;
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

    //Verify images are the same size
    string header;
    int fg_width, fg_height, bg_width, bg_height, max_value;
    fin1 >> header >> fg_width >> fg_height >> max_value;
    fin2 >> header >> bg_width >> bg_height >> max_value;
   
    if(fg_width != bg_width || fg_height != bg_height){
        cout << "Error: Images have different sizes" << endl;
        return 1;
    }

    //Write header, height/width, max_value to output file
    fout << header << endl << bg_width << " " << bg_height << endl << max_value << endl;

    //Parent for loop to repeat child loop across each row
    for(int j=0;j<bg_height;j++){
        //Child for loop to repeat task across each column
        for(int i=0;i<bg_width;i++){ 

            //Read in fg and bgpixels
            int r_fg, g_fg, b_fg, r_bg, g_bg, b_bg;
            fin1 >> r_fg >> g_fg >> b_fg;
            fin2 >> r_bg >> g_bg >> b_bg;

            //Check if fg pixel is green; if yes, write bg pixel, if not, write fg pixel
            if(r_fg == 0 && g_fg == max_value && b_fg == 0)
                fout << r_bg << " " << g_bg << " " << b_bg << " ";
            else
                fout << r_fg << " " << g_fg << " " << b_fg << " ";
        }
        //Start next line in output for next run of parent loop
        fout << endl;
    }
    
    //Clean up, output success message
    cout << "Image saved to " << out_filename << endl;
    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}