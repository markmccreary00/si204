/*
Filename: p1.cpp
Author: MIDN Mark McCreary (274230)
LAB07 Part 1
*/

#include <iostream>
using namespace std;

int* read(int N)
{
    char c;
    cin >> c;
    int* A = new int[N];
    for(int i = 0; i < N ; i++)
        cin >> A[i];
    return A;
}

void print(int* A, int N)
{
    for(int i = 0 ; i < N ; i++)
        cout << ' ' << A[i] << ' ';
    cout << endl;
    for(int i = 0 ; i < (2*N + 1) ; i++)
        cout << '-';
    cout << endl;
    for(int i = 0 ; i < N ; i++)
        cout << ' ' << char(65 + i) << ' ';
    cout << endl;
    return;
}

bool isInOrder(int* A, int N)
{
    int tracker = 1;
    for(int i = 0 ; i < (N-1) ; i++)
    {
        if(A[i+1]>=A[i])
            tracker++;
    }
    bool val = (tracker == N) ? true : false;
    return val;
}

int main()
{
  char c;
  int N;
  cin >> c >> c >> N;

  int* A = read(N);
  print(A,N);

  if (isInOrder(A,N))
    cout << "Is in order!" << endl;
  else
    cout << "Is not in order!" << endl;

  delete [] A;
  return 0;
}