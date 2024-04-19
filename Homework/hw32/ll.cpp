#include <iostream>
#include "ll.h"
using namespace std;

Node* add2front(int n, Node* L){
    Node* temp = new Node;
    temp->data = n;
    temp->next = L;
    return temp; 
}

Node* add2back(int n, Node* L){
    if(L == NULL){
        return add2front(n, L); 
    }
    else{
        L->next = add2back(n, L->next);
        return L;
    }
}

void print(Node* L){
    if(L == NULL){
        cout << endl;
        return;
    }
    else{
        cout << L->data << ' ';
        print(L->next);
    }
}

Node* searchBefore(int n, Node* L){
    if(L->next == NULL ||n == L->next->data || n == L->data)
        return L;
    else
        return searchBefore(n, L->next);
}

Node* searchTarget(int n, Node* L){
    if(L == NULL || n == L->data)
        return L;
    else
        return searchTarget(n, L->next);
}

Node* remove(int n, Node* L){
    Node* target = searchTarget(n, L);
    Node* previous = searchBefore(n, L);
    Node* destination = target->next;

    if(n == L->data){
        delete target;
        return destination;
    }
    else{
        previous->next = destination;
        delete target;
        return L;
    }
    
}

void enter_after(int d, int x, Node* L){
    Node* target = searchTarget(x, L);
    if(x == L->data){
        L->next = new Node{NULL,d};
        return;
    }
    else if(target->next == NULL)
        target->next = add2front(d, L);
    else{
        Node* destination = target->next;
        target->next = add2front(d, L);
        target->next->next = destination;
    }
}

Node* deleteFront(Node* L){
    if(L == NULL)
        return NULL;
    
    Node* r = L->next;
    delete L;
    return r;
}

void deletelist(Node* L){
    while(L != NULL)
        L = deleteFront(L);
}