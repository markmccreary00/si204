#pragma once
#include <iostream>
using namespace std;

struct Node{
    Node* next;
    int data;
};

Node* add2front(int n, Node* L);
Node* add2back(int n, Node* L);
void print(Node* L);
Node* searchTarget(int n, Node* L);
Node* remove(int n, Node* L);
void enter_after(int d, int x, Node* L);
Node* deleteFront(Node* L);
void deletelist(Node* L);