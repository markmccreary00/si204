/*
Filename: part1.cpp
Author: MIDN Mark McCreary (274230)
LAB03 Part 2
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "Enter three numbers: ";
	double a, b, c, l, s1, s2;
	cin >> a >> b >> c;
    string anglerelation, lengthrelation;
	
	if(a>b) //Order inputs by length, s1 (shortest) < s2 < l (longest)
	{
		 s1 = b;
		if(a>c)
		{
			l = a;
			s2 = c;
		}
		else
		{
			l =c ;
			 s2 = a;
		}
	}

	else
	{
		s1 = a;
		if(b>c)
		{
			l = b;
			s2 = c;
		}	
		else
		{
			l = c;
			s2 = b;
		}
	}
	
    if(s1 + s2 <= l) //Check viability of triangle inequality
    {
        cout << "Error! these lengths violate the triangle inequality!" << endl;
        return 0;
    }

	else //Classification logic goes here once inequality condition is met
    {
       if(((s1 * s1) + (s2 * s2)) == (l * l) ) //This block determines angle relation (right, acute, obtuse)
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

    cout << "This is a " << anglerelation << " " << lengthrelation << " triangle." << endl;
    return 0;
	}