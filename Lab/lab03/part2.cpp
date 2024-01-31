/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB03 Part 2
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "Enter side lengths: ";
	double a, b, c, l, s1, s2;
	cin >> a >> b >> c;
    string anglerelation, lengthrelation;
	
	if(a>=b && a>=c) //Determine longest side
    {
        l = a;
    }
    if(b>=a && b>=c)
    {
        l = b;
    }
    else
    {
        l = c;
    }

    if(a<=b && a<=c) //Determine shorest side
    {
        s1 = a;
    }
    if(b<=a && b<=c)
    {
        s1 = b;
    }
    else
    {
        s1 = c;
    }

    if(a>=b && a<=c) //Determine middle length side
    {
        s2 = a;
    }
    if(b>=a and b<=c)
    {
        s2 = b;
    }
    else
    {
        s2 = c;
    }

	
    if(s1 + s2 <= l) //Check viability of triangle inequality
    {
        cout << "Error! these lengths violate the triangle inequality!" << endl;
        return 0;
    }
	else //Classification logic goes here once inequality condition is met
    {
        if(((s1 * s1) + (s2 * s2)) == (l * l) ) //This block determines angle relation
        {
            anglerelation = "right";
        }
        else
        {
            if( ((s1 * s1) + (s2 * s2)) > (l * l))
            {
                anglerelation = "acute";
            }
            else
            {
                anglerelation = "obtuse";
            }
        }

    if(s1 != s2 && s2 != l && s1 != l) //This block determines length relation
    {
        lengthrelation = "scalene";
    }
    else
    {
        if( (s1 == s2 && s1 != l && s2 != l) || (s2 == l && s1 != s2 && s1 != l))
        {
            lengthrelation = "isosceles";
        }
        else
        {
            lengthrelation = "equilateral";
        }
    }

    }

    //Return results to user
    cout << "This is a " << anglerelation << " " << lengthrelation << " triangle." << endl;
    return 0;
	
    }