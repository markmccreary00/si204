#include <iostream>
using namespace std;

int readN();
double* readnums(int n, char* c);
void reverse(double* A, double* B, char cA, char cB, int n);
void min(double* A, double* B, char cA, char cB, int n);


int main()
{

  //read N
  int n = readN();

  char cA, cB;
  //read the value of label and the first vector
  double* A = readnums(n, &cA);
  //read the value of second label and the second vector
  double* B = readnums(n, &cB);

  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "reverse" )
      reverse(A, B, cA, cB, n);
    else if ( cmd == "min" )
      min(A, B, cA, cB, n);
    else
      cout << "invalid command!" << endl;
  }

  delete [] A;
  delete [] B;

  return 0;
}
  
int readN()
{
    int n;
    cin >> n;
    return n;
}

double* readnums(int n, char* c)
{
    char dump;
    cin >> (*c) >> dump;
    double* A = new double[n];
    for(int i = 0 ; i < n ; i++)
        cin >> A[i];
    return A;
}

void reverse(double* A, double* B, char cA, char cB, int n)
{
    char vectorName;
    cin >> vectorName;
        
    if (vectorName == cA)
    {
        double* tempArr = new double[n];
        for(int i = 0 ; i < n ; i++)
            tempArr[i] = A[n-(i+1)];
        cout << '[';
        for(int i = 0 ; i < n ; i++)
        {
            cout << tempArr[i];
            if((i+1) != n)
                cout << ' ';
        } 
        cout << ']' << endl;

        delete[] tempArr;
    }
    else if(vectorName == cB)
    {
        double* tempArr = new double[n];
        for(int i = 0 ; i < n ; i++)
            tempArr[i] = B[n-(i+1)];

        cout << '[';
        for(int i = 0 ; i < n ; i++)
        {
            cout << tempArr[i];
            if((i+1) != n)
                cout << ' ';
        } 
        cout << ']' << endl;

        delete[] tempArr;
    }
    else
        cout << "no such vector!" << endl;
    return;
}

void min(double* A, double* B, char cA, char cB, int n)
{
    char vectorName;
    cin >> vectorName;

    if(vectorName == cA)
    {
        double workingMin = A[0];
        for(int i = 1 ; i < n ; i++)
        {
            if(A[i] < workingMin)
                workingMin = A[i];
        }

        cout << workingMin << endl;
    }
    else if(vectorName == cB)
    {
        double workingMin = B[0];
        for(int i = 1 ; i < n ; i++)
        {
            if(B[i] < workingMin)
                workingMin = B[i];
        }

        cout << workingMin << endl;
    }
    else
        cout << "no such vector!" << endl;

    return;
}