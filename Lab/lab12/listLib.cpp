#include <fstream>
#include <iostream>
#include "listLib.h"

using namespace std;

Node* add2front(Node* oldList, Pair P){
    Node* temp = new Node;
    temp->data = P;
    temp->next = oldList;
    return temp;
}

istream& operator>> (istream& in, Pair& P){
    char c;
    return in >> c >> P.val >> P.num >> c;
}

int countAll(Node* list){
    if(list == NULL)
        return 0;
    else
        return 1 + count(list->next);
}

void printList(Node* list){
    if(list == NULL)
        return;
    else{
        cout << '(' << list->data.val << ' ' << list->data.num << ") ";
        printList(list->next);
    }
}

Node* deleteFront(Node* list){
    if(list == NULL)
        return NULL;
    
    Node* r = list->next;
    delete list;
    return r;
}

void deleteList(Node* list){
    while(list != NULL)
        list = deleteFront(list);
}