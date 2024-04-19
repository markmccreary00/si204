#include <iostream>
using namespace std;

int calspace(int num);

int main()
{
  int n;
  cout << "Integer? ";
  cin >> n;

  cout << "#spaces= " << calspace(n) << endl;
  return 0;
}

int calspace(int num)
{
    int sp = 0;
    if( num < 0 ) 
    {
    sp++;         
    num = -num;   
    }
    if(num < 10)
        return sp += 1;
    else{
       sp++;
       return sp += calspace(num /10); 
    }
}