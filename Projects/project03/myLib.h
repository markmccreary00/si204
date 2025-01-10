#pragma once
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "easycurses.h"
#include "Pos.h"
using namespace std;

struct board{
    int height, width, spawn_count;
    char** map;
    Pos* spawns;
    Pos start; 
    Pos target;
};

struct entity{
    char sprite;
    Pos position;
    int dir;
};


struct entNode{
    entity ent;
    entNode* next;
};

void getBoard(string filename, board &current);
void initializeMap(board &current);
void playerInput(entity &player);
void computeNext(entity &en, board &current);
