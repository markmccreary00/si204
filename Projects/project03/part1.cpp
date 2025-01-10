/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
Project 3, Part 1
*/

#include "myLib.h"

int main(){
    string filename;
    cout << "board file: ";
    cin >> filename;

    board current;
    getBoard(filename, current);

    startCurses();
    int row, col;
    getWindowDimensions(row, col);
    drawMap(current);

    char c;
    do {
        usleep(150000);
        c = inputChar();
    } while(c != 'y'); 
    endCurses();

    cout << "Player start: (" << current.start.row << "," << current.start.col << ")" << endl;
    cout << "Spawn spots: ";
    for(int i = 0 ; i < current.spawn_count ; i++){
        cout << "(" << current.spawns[i].row << "," << current.spawns[i].col << ") ";
    }
    cout << endl;

    return 0;
}

