#include <iostream>
using namespace std;

void foo1(int x, int y);
void foo2(int* x, int y);

int main() {
  int* A = new int[3];
  A[0] = 0; A[1] = 1; A[2] = 2;
  foo1(A[0], A[1]);
  cout << A[0] << " " << A[1] << endl;
  foo2(A, A[0]);
  cout << A[0] << " " << A[1] << " " << A[2] << endl;
}

void foo1(int x, int y){
  x++; y++;
}

void foo2(int* x, int y){
  x[y]++;
  // control_point_1
}