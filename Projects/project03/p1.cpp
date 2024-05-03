/*
Filename: p1.cpp
Author: MIDN Mark McCreary (274230)
Project 3, Part 1
*/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "easycurses.h"
using namespace std;

struct board{
    int height, width, spawn_count;
    char** map;
};

void getBoard(string filename, board &current){
    ifstream fin(filename);

    if(!fin){
        cout << "Error: File '" << filename  << "' not found!" << endl;
        return;
    }

    char dump;
    fin >> current.height >> dump >> current.width >> current.spawn_count;
   
    current.map = new char*[current.height];
    for(int i = 0 ; i < current.height ; i++) {
        current.map[i] = new char[current.width];
    }

    for(int i = 0 ; i < current.height ; i++){
        for(int j = 0 ; j < current.width ; j++){
            current.map[i][j] = fin.get();
        }
    }
}

int main(){
    string filename;
    cout << "board file: ";
    cin >> filename;

    board current;
    getBoard(filename, current);

    startCurses();
    int row, col;
    getWindowDimensions(row, col);

    for(int i = 0 ; i < current.height ; i++){
        for(int j = 0 ; j < current.width ; j++){
            drawChar(current.map[i][j], i, j);
        }
    }
    refreshWindow();

    char c;
    do {
        usleep(150000); // pause (sleep) for .15 seconds
        c = inputChar();
    } while(c != 'y'); //loop exits with a 'y'
    endCurses();

    return 0;
}

