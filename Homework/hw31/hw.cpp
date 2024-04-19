/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW31
*/

#include <iostream>
using namespace std;

struct node{
    node* next;
    string data;
};

node* add2front(node* list, string data);
void search(node* list, char c);
node* del(node* list);
void nuke(node* list);

int main(){
    node* list = NULL;
    cout << "Enter words followed by END:" << endl;
   
   
    string working;
    do{
        cin >> working;
        list = add2front(list, working);
    } while(working != "END");

    char c;
    cout << "What letter? ";
    cin >> c;

    search(list, c);   
    nuke(list);

    return 0;
}

node* add2front(node* list, string data){
    node* temp = new node;
    temp->data = data;
    temp->next = list;
    return temp;
}

void search(node* list, char c){
    if(list == NULL)
        return;
    else{
        if(list->data[0] == c)
            cout << list->data << endl;
        search(list->next, c);
    }
}

node* del(node* list){
    if(list == NULL)
        return NULL;
    else{
        node* nextTarget = list->next;
        delete list;
        return nextTarget;
    }
}

void nuke(node* list){
    while(list != NULL)
        list = del(list);
}