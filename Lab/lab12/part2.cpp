/*
Filename: part2.cpp
Author: MIDN Mark A. McCreary (274230)
Lab 12, Part 2
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

    //create, read in list data
    Node* list = NULL;
    Pair P;
    while(fin >> P)
        list = add2front(list, P);

    //lets user crawl through list
    crawlList(list, list);

    //clean up & exit
    deleteList(list);
    return 0;
}