/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW18
*/

#include <iostream>
using namespace std;

// ======================================
// Function prototypes below
// ======================================

int readN();
int* readData(int n);
void show(int* A, int n);
void swap(int* A, int n);

// ======================================
// main function
// TOUCH NOTHING INSIDE THE FUNCTION!!
// ======================================
int main()
{
  int n = readN();
  int* A = readData(n);

  string cmd;
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);
    cout << "cmd: ";
  }

  delete[] A;

  return 0;
}

// ======================================
// Function definitions below
// ======================================

int readN()
{
    int n;
    char dump;
    cin >> dump >> dump >> n;
    return n;
}

int* readData(int n)
{
    int* A = new int[n];
    for(int i=0;i<n;i++)
        cin >> A[i];
    return A;
}

void show(int* A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout << '[' << i << "] ";
        for(int j = 0;j<A[i];j++)
            cout << '*';
        cout << endl;
    }
    return;
}

void swap(int* A, int n)
{
    int ind1, ind2, temp;
    cin >> ind1 >> ind2;
    temp = A[ind1];
    A[ind1] = A[ind2];
    A[ind2] = temp;
    return;
}