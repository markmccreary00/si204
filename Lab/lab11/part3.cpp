#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void repeat(string s, int size);
void cantor_row(int width, int levels);


int main() {
    int size;
    cout << "size: ";
    cin >> size;
    cout << "Width-" << size << " Cantor set:" << endl;
    
    int levels;
    if(size == 1)
      levels = 0;
    else
      levels = cbrt(size);
    
    for(int i = 0 ; i <= levels ; i++) {
        cantor_row(size, i);
        cout << endl;
    }
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

void cantor_row(int width, int levels) {
    if(levels == 0 || width == 1)
      repeat("X", width);
    else {
      cantor_row(width/ 3 , levels-1);
      repeat("_", width/3);
      cantor_row(width/ 3 , levels-1); 
    }
}


