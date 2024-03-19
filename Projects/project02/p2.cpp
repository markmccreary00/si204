/*
Filename: p2.cpp
Author: MIDN Mark McCreary (274230)
Project 2, Part 2
*/

#include <iostream>
using namespace std;

int* makeDeck();
void deal(int* deck, int* hand, int* deckPos);
void print(int* hand);



int main()
{
    int* deck = makeDeck();

    //The first element of each hand array is tracks how many elements are being used, i.e how many cards are in each player's hand.
    int* dHand = new int[11];
    int* pHand = new int[11];
    dHand[0] = 0;
    pHand[0] = 0;
    

    //deckPos is incremented on each deal command to ensure that cards are being dealt off the deck in order.
    int deckPos = 0;

    string cmd;
    do{
        cout << "> ";
        cin >> cmd;
        if(cmd == "print-p")
            print(pHand);
        else if(cmd == "print-d")
            print(dHand);
        else if(cmd == "deal-p")
            deal(deck, pHand, &deckPos);
        else if(cmd == "deal-d")
            deal(deck, dHand, &deckPos);
        else if(cmd == "quit")
            return 0;
    }
    while(cmd != "quit");

    return 0;
}

int* makeDeck()
{
    int* deck = new int[52];
    for(int face = 1; face <= 4 ; face++)
    {
        for(int suit = 2; suit <= 14 ; suit++)
        deck[ ((face-1) * 13) + (suit - 2) ] = (100 * face) + suit;
    }
    cout << '[';
    for(int i = 0; i < 52 ; i++)
    {
        cout << deck[i];
        if(i != 51)
            cout << ' ';
    }
    cout << ']' << endl;
    return deck;
}

void deal(int* deck, int* hand, int* deckPos)
{
    hand[hand[0] + 1] = deck[*deckPos];
    (*deckPos)++;
    hand[0]++;
    return;
}

void print(int* hand)
{
    cout << '[';
    for(int i = 1; i <= hand[0] ; i++)
    {
        cout << hand[i];
        if(i != hand[0])
            cout << ' ';
    }
    cout << ']' << endl;
    return;
}
