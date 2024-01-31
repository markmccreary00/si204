/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB03 Part 1
*/

#include <iostream>
using namespace std;

int main()
{
    //Read in coordinates
    double x1, x2, x3, y1, y2, y3;
    char z;
    cin >> z >> x1 >> z >> y1 >> z >> z >> x2 >> z >> y2 >> z >> z >> x3 >> z >> y3 >> z;

    //Determine max/min x & y values
    double xmax, xmin, ymax, ymin;

    //Determine max x value
    if(x1>=x2)
    {
        if(x1>=x3)
        xmax = x1;
        else
        xmax = x3;
    }
    else
    {
        if(x2>=x3)
        xmax = x2;
        else
        xmax = x3;
    }

    //Determine min x value
     if(x1<=x2)
    {
        if(x1<=x3)
        xmin = x1;
        else
        xmin = x3;
    }
    else
    {
        if(x2<=x3)
        xmin = x2;
        else
        xmin = x3;
    }

    //Determine max y value
    if(y1>=y2)
      {
        if(y1>=y3)
        ymax = y1;
        else
        ymax = y3;
    }
    else
    {
        if(y2>=y3)
        ymax = y2;
        else
        ymax = y3;
    }

    //Determine min y value
    if(y1<=y2)
      {
        if(y1<=y3)
        ymin = y1;
        else
        ymin = y3;
    }
    else
    {
        if(y2<=y3)
        ymin = y2;
        else
        ymin = y3;
    }

    //Output bounding box coordinates
    cout << xmin << " " << ymin << endl; 
    cout << xmin << " " << ymax << endl; 
    cout << xmax << " " << ymax << endl; 
    cout << xmax << " " << ymin << endl; 
    cout << xmin << " " << ymin << endl; 

    //Output line break
    cout << endl;

    //Output triangle coordinates
    cout << x1 << " " << y1 << endl;
    cout << x2 << " " << y2 << endl;
    cout << x3 << " " << y3 << endl;
    cout << x1 << " " << y1 << endl;

    return 0;

}