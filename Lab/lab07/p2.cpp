/*
Filename: p2.cpp
Author: MIDN Mark McCreary (274230)
LAB07 Part 2
*/

#include <iostream>
using namespace std;

int* read(int N);
void print(int* A, int N);
bool isInOrder(int* A, int N);
int startgame();
int play(int* A, int N);

int main()
{
  int N = startgame();
  int* A = read(N);
  print(A,N);

  int moves = play(A,N);
  
  cout << (3*moves) << " points! (" << moves << " moves)" << endl;

  delete [] A;
  return 0;
}

int* read(int N)
{
    int* A = new int[N];
    for(int i = 0; i < N ; i++)
        cin >> A[i];
    return A;
}

void print(int* A, int N)
{
    cout << endl;
    for(int i = 0 ; i < N ; i++)
        cout << ' ' << A[i] << ' ';
    cout << endl;
    for(int i = 0 ; i < (2*N + 1) ; i++)
        cout << '-';
    cout << endl;
    for(int i = 0 ; i < N ; i++)
        cout << ' ' << char(65 + i) << ' ';
    cout << endl;
    if(!(isInOrder(A,N)))
        cout << "> ";
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

int startgame()
{
    cout << "Welcome to SWARE!" << endl << "board> ";
    char c;
    int N;
    cin >> c >> c >> N >> c;
    return N;
}

int play(int* A, int N)
{
    string cmd;
    int moves = 0;
    while(!(isInOrder(A,N)) && cin >> cmd)
    {
        if(cmd == "swap")
        {
            int ind1_int, ind2_int, temp;
            char ind1_char, ind2_char;
            cin >> ind1_char >> ind2_char;
            ind1_int = ind1_char - 65;
            ind2_int = ind2_char - 65;

            temp = A[ind2_int];
            A[ind2_int] = A[ind1_int];
            A[ind1_int] = temp;
            moves++;
        }
        else
            cout << "Unknown move '" << cmd << "'" << endl;
        print(A,N);
    }
    return moves;
}