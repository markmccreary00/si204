/*
Filename: p3.cpp
Author: MIDN Mark McCreary (274230)
LAB10
*/

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

struct cpos{
    char c, dir;
    int x, y;
};

istream& operator>>(istream& in, cpos& a){
    char dump;
    return in >> a.c >> dump >> a.y >> dump >> a.x >> dump;
}

int main(){
    int n;
    cin >> n;
    cpos* data = new cpos[n];
    for(int i = 0; i < n ; i++){
        cin >> data[i];
        data[i].dir = 'e';
    }

    startCurses();
 
    for(int i = 0; i < n ; i++){
        drawChar(data[i].c, data[i].y, data[i].x);
    }

    refreshWindow();
    usleep(80000);

    for(int frame=0; frame < 20; frame++){
        for(int i = 0; i < n ; i++){
            drawChar(' ', data[i].y, data[i].x);

            if(data[i].dir == 'n')
                data[i].y += 1;
            else if (data[i].dir == 'e')
                data[i].x += 1;
            else if (data[i].dir == 's')
                data[i].y -= 1;
            else //west
                data[i].x -= 1;

            drawChar(data[i].c, data[i].y, data[i].x);
        }  
        refreshWindow();
        usleep(80000);
    }

    endCurses();
    return 0;
}

