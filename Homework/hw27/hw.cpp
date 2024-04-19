/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW27
*/

#include <iostream>
using namespace std;

double pow(double x, int n);

int main(){
    double x;
    int n;
    cout << "Enter x and n: ";
    cin >> x >> n;
    cout << "x^n is " << pow(x, n) << endl;
    return 0;
}

double pow(double x, int n){
    if(n == 0){
        return 1;
    }
    else{
        double partial;
        partial = x  * pow(x, n-1);
        return partial;
    }
}