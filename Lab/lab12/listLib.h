#pragma once
#include <fstream>
#include <iostream>

using namespace std;

struct Pair{
    string val;
    int num;
};

struct Node{
  Pair data;
  Node* next;
};

Node* add2front(Node* oldList, Pair P);
istream& operator>> (istream& in, Pair& P);

int countAll(Node* list);
void printList(Node* list);


Node* deleteFront(Node* list);
void deleteList(Node* list);