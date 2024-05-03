#include <iostream>
#include <fstream>

using namespace std;

struct Pair{
    string name;
    double price;
};

void priceCheck(string ask, Pair* prices, int l);
double add2cart(string ask, double amt, Pair* prices, int l);

int main(){
    cout << "Filename: ";
    string filename;
    cin >> filename;

    ifstream fin(filename);
    if(!fin){
        cout << "File not found!" << endl;
        return 1;
    }

    string dump;
    char dmp;
    int l;
    fin >> l >> dump;

    Pair* prices = new Pair[l];
    for(int i = 0; i < l ; i++){
        fin >> prices[i].name >> dmp >> prices[i].price;
    }

    double total = 0.0;
    string cmd = "";

    while(cmd != "checkout"){
        cout << "command: ";
        cin >> cmd;
        if(cmd == "price"){
            string ask;
            cin >> ask;
            priceCheck(ask, prices, l);
        }
        else if (cmd == "add"){
            double amt;
            string ask;
            cin >> amt >> dump >> ask;
            total += add2cart(ask, amt, prices, l);
        }
    }

    cout << "total is $" << total << endl;
    fin.close();
    delete[] prices;
    return 0;
}

void priceCheck(string ask, Pair* prices, int l){
    for(int i = 0 ; i < l ; i++){
        if(prices[i].name == ask){
            cout << ask << " are $" << prices[i].price << " per pound" << endl;
            return;
        }
    }
    cout << "Error! " << ask << " not found!" << endl;
    return;
}

double add2cart(string ask, double amt, Pair* prices, int l){
    for(int i = 0 ; i < l ; i++){
        if(prices[i].name == ask){
            return amt * prices[i].price;
        }
    }
    cout << "Error! " << ask << " not found!" << endl;
    return 0;
}