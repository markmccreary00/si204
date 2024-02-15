/*
Filename: p1.cpp
Author: MIDN Mark McCreary (274230)
Practicum 1, Part 1
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    char mod, dump, op;
    cin >> mod >> dump;
    int num1_int;
    double num2, result;

    if(mod == 'f'){
        cin >> num1_int >> dump >> op >> num2;
        if(op == '+'){
            result = num1_int + num2;
            cout << num1_int << " + " << num2 << " = " << result << endl; 
        }
        if(op == '-'){
            result = num1_int - num2;
            cout << num1_int << " - " << num2 << " = " << result << endl; 
        }
    }
    if(mod == 'r'){
       
        char working_char1, working_char2, working_char3;
        int working_int1, working_int2, working_int3;
        cin >> working_char1 >> working_char2 >> working_char3;

        switch(working_char1){
            case '0':
                working_int1 = 0;
                break;
            case '1':
                working_int1 = 1;
                break;
            case '2':
                working_int1 = 2;
                break;
            case '3':
                working_int1 = 3;
                break;
            case '4':
                working_int1 = 4;
                break;
            case '5':
                working_int1 = 5;
                break;
            case '6':
                working_int1 = 6;
                break;
            case '7':
                working_int1 = 7;
                break;
            case '8':
                working_int1 = 8;
                break;
            case '9':
                working_int1 = 9;
                break;
        }

        switch(working_char2){
            case '0':
                working_int2 = 0;
                break;
            case '1':
                working_int2 = 1;
                break;
            case '2':
                working_int2 = 2;
                break;
            case '3':
                working_int2 = 3;
                break;
            case '4':
                working_int2 = 4;
                break;
            case '5':
                working_int2 = 5;
                break;
            case '6':
                working_int2 = 6;
                break;
            case '7':
                working_int2 = 7;
                break;
            case '8':
                working_int2 = 8;
                break;
            case '9':
                working_int2 = 9;
                break;
        }

        switch(working_char3){
            case '0':
                working_int3 = 0;
                break;
            case '1':
                working_int3 = 1;
                break;
            case '2':
                working_int3 = 2;
                break;
            case '3':
                working_int3 = 3;
                break;
            case '4':
                working_int3 = 4;
                break;
            case '5':
                working_int3 = 5;
                break;
            case '6':
                working_int3 = 6;
                break;
            case '7':
                working_int3 = 7;
                break;
            case '8':
                working_int3 = 8;
                break;
            case '9':
                working_int3 = 9;
                break;
        }
        
        num1_int = (100 * working_int3) + (10 * working_int2) + working_int1;
        cin >> dump >> op >> num2;
        
        if(op == '+'){
            result = num1_int + num2;
            cout << num1_int << " + " << num2 << " = " << result << endl; 
        }
        if(op == '-'){
            result = num1_int - num2;
            cout << num1_int << " - " << num2 << " = " << result << endl;
        }
    }
    return 0;
}