#include <iostream>
using namespace std;

int main()
{
    int x, y;
    string sdump;

    cin >> y >> sdump >> x >> sdump;

    int** map = new int*[y];
    for(int i = 0 ; i < y ; i++)
        map[i] = new int[x];

    for(int i = 0 ; i < y ; i++)
    {
        for(int j = 0 ; j < x ; j++)
            cin >> map[i][j];
    }

    
    
    string cmd;
    while( cout << "> " && cin >> cmd && cmd != "quit" )
    {
        if(cmd == "crash")
        {
            string st_s;
            int ave, st;
            cin >> st_s >> sdump >> ave >> sdump;
            st = int(st_s[0] - '0');

            if(st_s[1] < 'A')
            {
                st = 10 * st;
                st += int(st_s[1] - '0');
            }

            map[st-1][ave-1] += 1;

            for(int i = 0 ; i < y ; i++)
            {
                for(int j = 0 ; j < x ; j++)
                    cout << map[i][j] << ' ';
                cout << endl;
            }
        }
        else
            cout << "invalid command!" << endl;
    }

    for(int i = 0 ; i < y ; i++)
        delete[] map[i];
    delete[] map;

    return 0;
}