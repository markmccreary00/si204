
#include <iostream>
using namespace std;
int main()
{
 int input, maximum, sum, count;
 sum = 0;
 count = 0;
 cout << "Enter numbers separated by spaces and terminated with a negative number." << endl;
 cin >> input;
 maximum = input;

 while(input >= 0)
 {
    sum = sum + input;
    count = count + 1;

    if(input > maximum)
    maximum = input;
    cin >> input;
 }
  double average = double(sum) / double(count);
  cout << "The average is " << average << endl;
  cout << "The maximum is " << maximum << endl;
}