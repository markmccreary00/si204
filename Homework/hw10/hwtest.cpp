#include <iostream>
using namespace std;

int main(){

int i=1;
char c;

while(i <= 5){
for(int j=0;j<i;j++){
    c= 'A' + char(j);
    cout << c;
}
cout << endl;
i++;
}
}