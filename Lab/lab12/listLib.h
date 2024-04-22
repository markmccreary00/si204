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
  bool valid;
};

Node* add2front(Node* oldList, Pair P);
istream& operator>> (istream& in, Pair& P);

int count(Node* list, Node* stop);
void print(Node* list, Node* stop);
void endPrint(Node* list);
void crawlList(Node* current, Node* list);

Node* deleteFront(Node* list);
void deleteList(Node* list);