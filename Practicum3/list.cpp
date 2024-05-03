/******************************************
list.cpp

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/
#include "list.h"

Node* add2front(Character x, Node* L){
  Node* temp = new Node;
  temp -> data = x;
  temp -> next = L;
  return temp;
}

Node* add2back(Character x, Node* L){
  if(L == NULL){
    return add2front(x, L);
  }
  else{
    L->next = add2back(x, L->next);
    return L;
  }
}

void print(Node* L){
  if(L == NULL){
    cout << endl;
    return;
  }
  else{
    cout << '[' << L->data.label << " (" << L->data.row << ',' << L->data.col << ")] ";
    print(L->next);
  }
}

void nodesLeftOf(Node* L, int col){
  if(L == NULL){
    return;
  }
  else{
    if(L->data.col < col)
      cout << '[' << L->data.label << " (" << L->data.row << ',' << L->data.col << ")] " << endl;
    nodesLeftOf(L->next, col);
  }
}

void removeThird(Node* L){
  Node* temp = L->next->next;
  L->next->next = temp->next;
  delete temp;
}

void deletelist(Node* L)
{
  if( L == NULL )
  {
    return;
  }
  else 
  {
    deletelist(L->next);
    delete L;
  }
}


