/*
Filename: hw.cpp
Author: MIDN Mark McCreary (274230)
HW19
*/

#include <iostream>
#include <string>
using namespace std;

// TO DO: Give function prototypes

void get_names(string* pcan1, string* pcan2);
void display_results(string can1, int count1, string can2, int count2);
bool update_counts(string sel, string can1, int* pcount1, string can2, int* pcount2);

// *** DON'T CHANGE main()!! ****
int main() 
{
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}


// TO DO: Give function definitions

void get_names(string* pcan1, string* pcan2)
{
    cout << "Candidate names: ";
    cin >> *pcan1 >> *pcan2;
    return;
}

bool update_counts(string sel, string can1, int* pcount1, string can2, int* pcount2)
{
    if(sel == can1)
    {
        (*pcount1)++;
        return 1;
    }
    else if(sel == can2)
    {
        (*pcount2)++;
        return 1;
    }
    else if (sel == "END")
    {
        return 0;
    }
    else
    {
        cout << "Invalid name" << endl;
        return 1;
    }
    return 0;
}

void display_results(string can1, int count1, string can2, int count2)
{
    if(count1== count2)
        cout << "Tie!" << endl;
    else
        cout << ((count1>count2)?can1:can2) << " wins with " << ((count1>count2)?count1:count2) << " out of " << (count1 + count2) << " votes " << endl;
    return;
}



