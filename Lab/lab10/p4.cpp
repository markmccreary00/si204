/*
Filename: p4.cpp
Author: MIDN Mark McCreary (274230)
LAB10
*/

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "easycurses.h"
using namespace std;

struct cpos{
    char c;
    int x, y, dir;
};

istream& operator>>(istream& in, cpos& a){
    char dump;
    return in >> a.c >> dump >> a.y >> dump >> a.x >> dump;
}

int main(){
    srand(time(0));

    int n;
    cin >> n;
    cpos* data = new cpos[n];
    for(int i = 0; i < n ; i++){
        cin >> data[i];
        data[i].dir = 1;
    }

    startCurses();

    int xmax, ymax;
    getWindowDimensions(ymax, xmax);
 
    for(int i = 0; i < n ; i++){
        drawChar(data[i].c, data[i].y, data[i].x);
    }

    refreshWindow();
    usleep(80000);

    char c;
    do {
        for(int i = 0; i < n ; i++){
            drawChar(' ', data[i].y, data[i].x);

/*
            if(rand() % 5 == 0){
                int r = rand()%2;

                if(data[i].dir == 1 || data[i].dir == 3){ //east or west
                    if(r == 1)
                        data[i].dir = 0;
                    else
                        data[i].dir = 2;
                }
                else {//data[i].dir == 0 || data[i].dir == 2 north or south
                    if(r == 1)
                        data[i].dir ==1;
                    else
                        data[i].dir = 3;
                }
            }
*/

            if(data[i].dir == 0){ //north
                if(data[i].y -= 1 < 0){
                   data[i].dir = 2;
                   data[i].y += 1;
                }
                else
                    data[i].y -= 1;
            } 
            else if (data[i].dir == 1){ //east
                if(data[i].x += 1 > xmax){
                   data[i].dir = 3;
                   data[i].x -= 1;
                }
                else
                    data[i].x += 1;
            } 
            
            else if (data[i].dir == 2){ //south
                if(data[i].y += 1 > ymax){
                   data[i].dir = 0;
                   data[i].y -= 1;
                }
                else
                    data[i].y += 1;
            }
            else{   // data[i].dir == 3 : west
                if(data[i].x -= 1 < 0){
                   data[i].dir = 1;
                   data[i].x += 1;
                }
                else
                    data[i].x -= 1;
            } 

            drawChar(data[i].c, data[i].y, data[i].x);
        }  
        refreshWindow();
        usleep(80000);
        c = inputChar();
    } while ( c!= 'q' );

    endCurses();
    return 0;
}

