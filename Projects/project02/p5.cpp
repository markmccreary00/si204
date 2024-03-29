/*
Filename: p5.cpp
Author: MIDN Mark McCreary (274230)
Project 2, Part 5
*/

#include <iostream>
using namespace std;

int* makeDeck();
void deal(int* deck, int* hand, int* deckPos);
void print(int* hand, int i);
void showHands(int* pHand, int* dHand);
void playRound(int* deck, int* pHand, int* dHand, int* deckPos, int rounds);


int main()
{
    int* deck = makeDeck();

    //The first element of each hand array is tracks how many elements are being used, i.e how many cards are in each player's hand.
    //Value of -1 indicates empty slot in hand, used showHands
    int* dHand = new int[11]{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int* pHand = new int[11]{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    //deckPos is incremented on each deal command to ensure that cards are being dealt off the deck in order.
    int deckPos = 0;

    //Shuffle and rand seed prompt
    char cmd;
    int seed;
    cout << "Shuffle: [n | u <seed>]: ";
    cin >> cmd >> seed;
    srand(seed);

    if(cmd == 'u')
    {
        for(int i = 0 ; i < 52 ; i++)
        {
            int j = rand() % 52;
            int temp;
            temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
        }
    }

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
    return deck;
}

void deal(int* deck, int* hand, int* deckPos)
{
    hand[hand[0] + 1] = deck[*deckPos];
    (*deckPos)++;
    hand[0]++;
    return;
}

void print(int* hand, int i)
{
    string clubs = "\u2663";
    string diamonds = "\u2666";
    string hearts = "\u2665";
    string spades = "\u2660";

    if(hand[i] != -1) 
    {
        if(hand[i] % 100 != 10) //handle spacing for face value 10 being two columns
            cout << ' ';
            
        string displayFace;
        switch(hand[i] % 100)
        {
            case 11:
                displayFace = "J";
                break;
            case 12:
                displayFace = "Q";
                break;
            case 13:
                displayFace = "K";
                break;
            case 14:
                displayFace = "A";
                break;
            default:
                displayFace = to_string(hand[i] % 100); //to_string function learned from stackOverflow
                break;
        }

        string displaySuit;
        switch(hand[i] / 100)
        {
            case 1:
                displaySuit = clubs;
                break;
            case 2:
                displaySuit = diamonds;
                break;
            case 3:
                displaySuit = hearts;
                break;
            case 4:
                displaySuit = spades;
                break;
        }

        cout << displayFace << displaySuit;
    }
    else
        cout << "   ";
}

void showHands(int* pHand, int* dHand)
{
    cout << endl << " Player Dealer" << endl;
    
    //determine amount of rows needed
    int maxRow = (pHand[0] > dHand[0]) ? pHand[0] : dHand[0];
    
    for(int i = 1; i <= maxRow ; i++)
    {
        cout << "| ";
        print(pHand, i);
        cout << "  | ";
        print(dHand, i);
        cout << "  |" << endl;
        
    }
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