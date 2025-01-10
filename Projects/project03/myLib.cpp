#include "myLib.h"

void getBoard(string filename, board &current){
    ifstream fin(filename);

    if(!fin){
        cout << "Error: File '" << filename  << "' not found!" << endl;
        return;
    }

    char dump;
    fin >> current.height >> dump >> current.width >> current.spawn_count;
    dump = fin.get();
   
    current.map = new char*[current.height];
    for(int i = 0 ; i < current.height ; i++) {
        current.map[i] = new char[current.width];
    }

    for(int i = 0 ; i < current.height ; i++){
        for(int j = 0 ; j < current.width ; j++){
            current.map[i][j] = fin.get();
        }
        dump = fin.get();
    }

    current.spawns = new Pos[current.spawn_count];

}

void drawMap(board &current){
    int spawnsTracker = 0;
    for(int i = 0 ; i < current.height ; i++){
        for(int j = 0 ; j < current.width ; j++){
            if(current.map[i][j] == 'Y'){
                drawChar(' ', i, j);
                current.start.row = i;
                current.start.col = j;
            }
            else if (current.map[i][j] == 'Z'){
                current.spawns[spawnsTracker].row = i;
                current.spawns[spawnsTracker].col = j;
                spawnsTracker++;
                drawChar(' ', i, j);
            }
            else if (current.map[i][j] == 'X'){
                current.target.row = i;
                current.target.col = j;
                drawChar(current.map[i][j], i, j);
            }
            else{
                drawChar(current.map[i][j], i, j);
            }

                
        }
    }
}

void playerInput(entity &player){
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
}

void computeNext(entity &en, board &current){
    drawChar(' ',en.position.row,en.position.col);

    Pos next = step(en.position, en.dir);
    if(current.map[next.row][next.col] == '#'){
        en.dir = turn(en.dir, 180);
    }
    next = step(en.position, en.dir);
    if(current.map[next.row][next.col] == '#'){
        en.dir = -1;
    }
        
    en.position = step(en.position, en.dir);

    drawChar(en.sprite,en.position.row,en.position.col);
}