/*
Filename: part1.cpp
Author: MIDN Mark A. McCreary (274230)
Lab 12, Part 1
*/

#include <fstream>
#include <iostream>
#include "listLib.h"

using namespace std;

int main(){
    string filename;
    cout << "Input file is: ";
    cin >> filename;

    ifstream fin(filename);
    if(!fin){
        cout << "Error: File '" << filename <<"' not found!'" << endl;
        return 1;
    }

    Node* list = NULL;
    Pair P;

    while(fin >> P)
        list = add2front(list, P);

    cout << "count is " << count(list) << endl;
    printList(list);
    cout << endl;
    deleteList(list);
    return 0;
}
