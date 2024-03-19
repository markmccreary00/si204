/*
Filename: p3.cpp
Author: MIDN Mark McCreary (274230)
Project 2, Part 3
*/

#include <iostream>
using namespace std;

int* makeDeck();
void deal(int* deck, int* hand, int* deckPos);
void print(int* hand);
void showHands(int* pHand, int* dHand);
void playRound(int* deck, int* pHand, int* dHand, int* deckPos, int rounds);


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

    for(int i = 0 ; i < 2 ; i++) //first cards dealt
    {
        deal(deck, pHand, &deckPos);
        deal(deck, dHand, &deckPos);
    }
   
   showHands(pHand, dHand);
   for(int rounds = 1; rounds <= 3; rounds++)
        playRound(deck, pHand, dHand, &deckPos, rounds);

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

void showHands(int* pHand, int* dHand)
{
    cout << endl << "Player: "; 
    print(pHand);
    cout << "Dealer: "; 
    print(dHand);
    cout << endl;
    return;
}

void playRound(int* deck, int* pHand, int* dHand, int* deckPos, int rounds)
{
    char cmd;

    cout << "Round " << rounds << " Player's turn" << endl << "hit or stand ? [h/s] ";
    cin >> cmd;
    if(cmd == 'h')
        deal(deck, pHand, deckPos);
    showHands(pHand, dHand);

    cout << "Round " << rounds << " Dealer's turn" << endl << "hit or stand ? [h/s] ";
    cin >> cmd;
    if(cmd == 'h')
        deal(deck, dHand, deckPos);
    showHands(pHand, dHand);

    return;
}