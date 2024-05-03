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

void printJustWords(Node* list, Node* stop){
    if(list == NULL || list == stop)
        return;
    else{
        if(list->data.valid == 1)
            cout << list->data.val << " ";
        printJustWords(list->next, stop);
    }
}

int endScore(Node* list){
    if(list == NULL)
        return 0;
    else{
        int partial = (list->data.num * list->data.valid);
        return partial += endScore(list->next);
    }
}

void crawlList_p2(Node* current, Node* list){
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

        cout << endl;
        current->data.valid = 1;
        crawlList_p2(current->next,list);
    }
}

void crawlList_p3(Node* current, Node* list){
    if(current == NULL){
        cout << "List is: ";
        printJustWords(list, NULL);
        cout << endl << "Score is: " << endScore(list) << endl;
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

        cout << endl;
        current->data.valid = 1; //
        crawlList_p3(current->next,list);
    }
}

void crawlList_p4(Node* current, Node* list){
    if(current == NULL){
        cout << "Sentence is: ";
        printJustWords(list, NULL);
        cout << endl << "Score is: " << endScore(list) << endl;
        return;
    }
    else
    {
        cout << "The current node: (" << current->data.val << ' ' << current->data.num << ')' << endl;
        cout << "Sentence you made so far: ";
        printJustWords(list, current);
        cout << endl << "#words left: " << (count(list, NULL) - count(list, current) - 1) << endl;
        
        //read in accept/reject to node
        cout << "[a]ccept or [r]eject: ";
        char c;
        cin >> c;

        if(c == 'a')
            current->data.valid = 1;
        else
            current->data.valid = 0;

        cout << endl;
        crawlList_p4(current->next,list);
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