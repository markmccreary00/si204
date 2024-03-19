/*
Filename: lab08.cpp
Author: MIDN Mark McCreary (274230)
LAB08 Part 1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

int main()
{
  //test printSpaced function
  cout << "Testing printSpaced..." << endl;
  cout << "["; 
  printSpaced("wash"); 
  cout << "]" << endl;

  cout << "["; 
  printSpaced("HelloWorld!"); 
  cout << "]" << endl;

  
  //test mkShadowString function
  cout << endl << "Testing mkShadowString..." << endl;
  string s1 = "food";
  string s2 = mkShadowString(s1);
  cout << "original: " << s1 << endl;
  cout << "  shadow: " << s2 << endl;
  string s3 = "require";
  string s4 = mkShadowString(s3);
  cout << "original: " << s3 << endl;
  cout << "  shadow: " << s4 << endl;

  //test uncover function   
  cout << endl << "Testing uncover..." << endl;
  string u1 = "housepet";
  string u2 = "________";
  cout << u1 << endl << u2 << endl;
  
  string u3 = uncover(u1,u2,'e');
  if( u2 == u3 )
    cout << u3 << " there were not e's!"  << endl;
  else
    cout << u3 << " there were e's!"  << endl;
  u2 = u3;
 
  u3 = uncover(u1,u2,'q');
  if( u2 == u3 )
    cout << u3 << " there were not q's!"  << endl;
  else
    cout << u3 << " there were q's!"  << endl;

  //test crossOut function
  cout << endl << "Testing crossOut..." << endl;
  string t1 = "Go get good food!";
  cout << t1 << endl;
  t1 = crossOut('o',t1);
  cout << t1 << endl;
  t1 = crossOut('g',t1);
  cout << t1 << endl;
   
  return 0;
}

void printSpaced(string s)
{
    for(int i = 0; i < s.length() ; i++)
    {
      cout << s[i];
      if((i+1)<s.length())
        cout << ' ';
    }
    return;
}

string mkShadowString(string s)
{
    string working = "_";
    for(int i = 1; i < s.length() ; i++)
        working += '_';
    return working;
} 

string uncover(string original, string covered, char c)
{
    for(int i = 0; i < original.length() ; i++)
    {
        if(original[i] == c)
            covered[i] = c;
    }
    return covered;
}

string crossOut(char c, string s)
{
    for(int i = 0; i < s.length() ; i++)
    {
        if(s[i] == c)
            s[i] = '*';
    }
    return s;
}
