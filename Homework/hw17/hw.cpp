/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW17
*/

#include <iostream>
using namespace std;

int main()
{
    //Prompt user for n
    cout << "Number of words: ";
    int n;
    cin >> n;

    //Read in sentence to array of n# strings
    cout << "Sentence: ";
    string* sentence = new string[n];
     for(int i = 0; i<n ; i++)
        cin >> sentence[i];

    //Read out sentence in original order, add spaces after except for last word, add questionmark
    for(int i = 0; i<n ; i++)
    {
        cout << sentence[i];
        if(i != (n-1))
            cout << ' ';  
    }
    cout << "? ";

    //Read out sentence in reverse order, add spaces after except for last word, add exclamationmark
    for(int i=(n-1); i>=0 ; i--)
    {
        cout << sentence[i];
        if(i != 0)
            cout << ' ';
    }
    cout << '!' << endl;

    //Clean-up
    delete[] sentence;
    return 0;

}