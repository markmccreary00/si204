/*
Filename: part2.cpp
Author: MIDN Mark McCreary (274230)
Project 3, Part 2
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

    int score = 500;
    entity player;
    player.position = current.start;
    player.sprite = 'P';
    player.dir = -1;

    do{
        int kb = inputChar();
        if( kb == 'w' ){
            player.dir = 0;
        }
        if( kb == 'a' ){
            player.dir = 3;
        }
        if( kb == 's' ){
            player.dir = 2;
        }
        if( kb == 'd' ){
            player.dir = 1;
        }
        if( kb == 'r' ){
            player.dir = -1;
        }

        drawChar(' ',player.position.row,player.position.col);

        Pos next = step(player.position, player.dir);
        if(current.map[next.row][next.col] == '#'){
            player.dir = turn(player.dir, 180);
        }
        next = step(player.position, player.dir);
        if(current.map[next.row][next.col] == '#'){
            player.dir = -1;
        }
        
        player.position = step(player.position, player.dir);

        drawChar(player.sprite,player.position.row,player.position.col);
        refreshWindow();
        score--;
        usleep(150000);
    } while(dist(current.target,player.position) >= 1);
     
    endCurses();

    cout << "Player start: (" << current.start.row << "," << current.start.col << ")" << endl;
    cout << "Spawn spots: ";
    for(int i = 0 ; i < current.spawn_count ; i++){
        cout << "(" << current.spawns[i].row << "," << current.spawns[i].col << ") ";
    }
    cout << endl;
    cout << "You won, high score = " << score << endl;

    return 0;
}

