/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB05 Part 1
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //Read in filename, open ifstream & verify good input
    string filename, dump;
    cin >> filename;

    ifstream fin(filename);
    if(!fin){
        cout << "File not found!" << endl;
        return 1;
    }

    //Pull width parameter from file header
    int width;
    fin >> dump >> dump >> width;

    cout << "Enter position between 1 and " << width << ": "; //Read in position input
    int position;
    cin >> position;

    if(position > width){  //Verify valid position input
        cout << "Invalid position!" << endl;
        return 0;
    }

    for(int i=1;i>=0;i++){
        char test;
        if(!(fin >> test)){ //Check if player has reached end of board & discard first '@'
            cout << "You survived!" << endl;
            return 0;
        }
        else{ //If not end of board, proceed with game
            for(int p=1;p<position;p++) //Discard all position state indicators before selected position
                fin >> test;

            fin >> test; 
            //read in selected position state indicator
            if(test == 'X') { 
                //check if position is lethal
                cout << "You died on step " << i << endl;
                return 0;
            }
            else{ 
                //if not lethal, discard remainder of line & proceed to next row
                fin >> dump;
            }
        }
    } 
}