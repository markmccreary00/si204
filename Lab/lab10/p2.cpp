/*
Filename: p2.cpp
Author: MIDN Mark McCreary (274230)
LAB10
*/

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

struct cpos{
    char c;
    int x, y;
};

istream& operator>>(istream& in, cpos& a){
    char dump;
    return in >> a.c >> dump >> a.x >> dump >> a.y >> dump;
}

int main(){
    int n;
    cin >> n;
    cpos* data = new cpos[n];
    for(int i = 0; i < n ; i++)
        cin >> data[i];

    startCurses();
    char c;
    do { 

        for(int i = 0; i < n ; i++){
            drawCharAndRefresh(data[i].c, data[i].x, data[i].y);
            usleep(800000);
        }

        for(int i = 0; i < n ; i++){
            drawChar(' ', data[i].x, data[i].y);
        }

        refreshWindow();
        usleep(800000);
        c = inputChar();

    } while ( c!= 'q' );

    endCurses();

    return 0;

}

