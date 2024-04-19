#include <iostream>
using namespace std;

double harm (int n){
    if(n == 1){
        return 1.0;
    }
    else{
        double partial = 1.0/n;
        partial += harm(n-1);
        return partial;
    }
}

int main(){
    int n;
    cin >> n;
    cout << harm(n) << endl;
    return 0;
}

