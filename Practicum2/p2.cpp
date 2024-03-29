#include <iostream>
using namespace std;

int main()
{
    string* snt = new string[100];
    int* sntB = new int[100];

    for(int i = 0; i < 100 ; i++)
        sntB[i] = 0;

    string temp;
    int n = 0;

    while(temp != ".")
    {
        cin >> temp;
        snt[n] = temp;
        for(int i = 1 ; i < temp.length() ; i++)
        {
            if(temp[i] == temp[0])
            {
                sntB[n] = 1;
            }
        }
        if(sntB[n] == 1)
        {
            for(int i = 1 ; i < temp.length() ; i++)
                {
                    if(snt[n][i] == snt[n][0])
                        snt[n][i] += 'A' - 'a';
                }
            snt[n][0] += 'A' - 'a';
        }
        
        n++;
    }

    for(int i = 0 ; i < 100 ; i++)
    {
        if(sntB[i] == 1)
            cout << snt[i] << ' ';
    }
    cout << endl;

    delete[] snt;
    delete[] sntB;

    return 0;

}