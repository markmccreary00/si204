#pragma once
#include <fstream>
#include <iostream>

using namespace std;

struct Pair{
    string val;
    int num;
    int valid;
};

struct Node{
  Pair data;
  Node* next;
};

Node* add2front(Node* oldList, Pair P);
istream& operator>> (istream& in, Pair& P);

int count(Node* list, Node* stop);

void print(Node* list, Node* stop);
void printJustWords(Node* list, Node* stop);

int endScore(Node* list);

void crawlList_p2(Node* current, Node* list);
void crawlList_p3(Node* current, Node* list);
void crawlList_p4(Node* current, Node* list);

Node* deleteFront(Node* list);
void deleteList(Node* list);