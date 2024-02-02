#include <iostream>
using namespace std;

int main(){

int total = 0;
int num;
char op = 'a';

cin >> total;

while(cin >> op){
    cin >> num;
	if(op == '='){
		break;
	}
	if(op == '+'){
		total = total + num;
	}
	else{
		total = total - num;
	}
}
cout << total << endl;	
return 0;
}

