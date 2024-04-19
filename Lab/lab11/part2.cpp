#include <iostream>
#include <string>
using namespace std;


void repeat(string s, int size);
void cantor_row(int size);


int main() {
    int size;
    cout << "size: ";
    cin >> size;
    cout << "Width-" << size << " Cantor set:" << endl;
    cantor_row(size);
    cout << endl;
}

void repeat(string s, int size) {
  if(size == 0) {
    return;
  }
  else{
    cout << s;
    repeat(s, size-1);
  }
}

void cantor_row(int size) {
    if(size == 1) {
        cout << 'X';
    }
    else {
        cantor_row(size/3);
        repeat("_", size/3);
        cantor_row(size/3);
    }
}

