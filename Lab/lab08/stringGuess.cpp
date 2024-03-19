/*
Filename: stringGuess.cpp
Author: MIDN Mark McCreary (274230)
LAB08 Part 2
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
bool play(string word);

int main()
{
    cout << "Welcome to String Guess!" << endl << "Enter a seed value: ";
    int seed;
    cin >> seed;
    srand(seed);
    int n = rand() % 1466;

    string word;
    ifstream fin("words07.txt");
    for(int i = 0; i<=n ; i++)
        fin >> word;

    if(play(word))
        cout << "You win!!!! The word was " << word << endl;
    else
        cout << "You lose!!!! The word was " << word << endl;
    fin.close();
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

bool play(string word)
{
    string shadow, shadowCopy;
    shadow = mkShadowString(word);
    string choices = "abcdefghijklmnopqrstuvwxyz";
    int guesses = 8;

    while(shadow != word && guesses > 0)
    {
        cout << "Wrong guesses remaining: " << guesses << "  " << choices << endl;
        printSpaced(shadow);
        cout << endl << ": ";

        char c;
        cin >> c;
        shadowCopy = shadow;
        shadow = uncover(word, shadow, c);
        if(shadow == shadowCopy)
        {
            guesses--;
            cout << "There were no " << c << "'s!" << endl;
        }
            
        choices = crossOut(c, choices);
    }
    if(guesses == 0)
        return false;
    else
        return true;
}