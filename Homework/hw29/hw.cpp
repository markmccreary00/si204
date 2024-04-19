#include <iostream>
using namespace std;

struct node{
    int value;
    node* next;
};

node* add2front(node* list, int value);

int main(){
    node* list = NULL;
    int temp = 1;
    while(temp > 0){
        cin >> temp;
        list = add2front(list, temp);
    }

    cout << list->next->next->next->value << endl;
}

node* add2front(node* list, int value){
    node* temp = new node;
    temp->value = value;
    temp->next = list;
    return temp;
}