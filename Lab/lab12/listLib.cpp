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

int count(Node* list, Node* stop){
    if(list == NULL || list == stop)
        return 0;
    else
        return 1 + count(list->next, stop);
}

void print(Node* list, Node* stop){
    if(list == NULL || list == stop)
        return;
    else{
        cout << '(' << list->data.val << ' ' << list->data.num << ") ";
        print(list->next, stop);
    }
}

void endPrint(Node* list){
    while(list != NULL){
        cout << list->data.val << " ";
        //LEFT OFF HERE FOR PART 3; EDIT BASE CASE IN crawlList ONCE THIS FX IS FINISHED
    }
}

void crawlList(Node* current, Node* list){
    if(current == NULL){
        cout << "List is: ";
        print(list, NULL);
        cout << endl;
        return;
    }
    else
    {
        cout << "The current node: (" << current->data.val << ' ' << current->data.num << ')' << endl;
        cout << "Nodes before the current: ";
        print(list, current);
        cout << endl << "#nodes after the current: " << (count(list, NULL) - count(list, current) - 1) << endl;
        
        //read in accept/reject to node
        cout << "[a]ccept or [r]eject: ";
        char c;
        cin >> c;

        /*
        if(c == a)
            current->valid = 1;
        else
            current->valid = 0
        */

        cout << endl;
        current->valid = 1;
        crawlList(current->next,list);
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