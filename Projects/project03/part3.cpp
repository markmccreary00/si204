/*
Filename: part3.cpp
Author: MIDN Mark McCreary (274230)
Project 3, Part 3
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


    int score = 500;
    entity player;
    player.position = current.start;
    player.sprite = 'P';
    player.dir = -1;

    entity** ships = new entity*[current.spawn_count];
        for(int i = 0 ; i < current.spawn_count ; i++){
            ships[i] = new entity[5];
            for(int j = 0 ; j < 5 ; j++){
                ships[i][j].sprite = '*';
                ships[i][j].position = current.spawns[i];
                ships[i][j].dir = (rand() % 4);
                cerr << "INIITIALIZED ships[" << i << "][" << j << "].dir = " << ships[i][j].dir << endl;
            }
        }

    do{
        drawMap(current);
        playerInput(player);
        computeNext(player,current);

        for(int i = 0 ; i < current.spawn_count ; i++){
            for(int j = 0 ; j < 5 ; j++){
                int prob = rand() % 10;
                if(prob == 0){
                    cerr << "TRIGGERED TURN EVENT ON [" << i <<"][" << j << "]" << endl;
                    prob = rand() % 2;
                    if(prob == 0){
                        ships[i][j].dir = turn(ships[i][j].dir, 90);
                        cerr << "ships[" << i << "][" << j << "].dir = " << ships[i][j].dir << " ; TURN EVENT 0" <<endl;
                    }
                    else{
                        ships[i][j].dir = turn(ships[i][j].dir, -90);
                        cerr << "ships[" << i << "][" << j << "].dir = " << ships[i][j].dir << " ; TURN EVENT 1" <<endl;
                    }
                }
            }
        }

        for(int i = 0 ; i < current.spawn_count ; i++){
            for(int j = 0 ; j < 5 ; j++){
                computeNext(ships[i][j],current);
            }
        }

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

