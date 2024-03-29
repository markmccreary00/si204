#include <iostream>
using namespace std;

int main(){
    double* A = new double[1];
    A[0] = 3.0;
    cout << A[0][0] << endl;
    return 0;
}