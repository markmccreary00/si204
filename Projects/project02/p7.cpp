/*
Filename: p7.cpp
Author: MIDN Mark McCreary (274230)
Project 2, Part 7
*/

#include <iostream>
#include <unistd.h>
using namespace std;

int* makeDeck();
void deal(int* deck, int* hand, int* deckPos);
void showHands(int* pHand, int* dHand);
void print(int* hand, int i);
void playRound(int* deck, int* pHand, int* dHand, int* deckPos, int* rounds, char* lastCmd, int* gameStateCode);
void updateGameState(int* pHand, int* dHand, char cmd, char* lastCmd, int* gameStateCode);
int getScore(int* hand);


int main()
{
    int* deck = makeDeck();

    //The first element of each hand array is tracks how many elements are being used, i.e how many cards are in each player's hand.
    //The last element is used as a bool flag for if the array belongs to the dealer, used in obfuscating the dealer's top card
    //Value of -1 indicates empty slot in hand, used in showHands
    int* dHand = new int[12]{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1};
    int* pHand = new int[12]{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0};
    
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
    

    int rounds = 1, gameStateCode = -1;
    //for gameStateCode: -1 = active game ; 0 = double stand, tie game ; 1 = double stand, player wins ; 2 ; double stand, dealer wins ; 3 = player wins ; 4 = dealer wins
    char lastCmd;
    while(gameStateCode == -1)
    {
        playRound(deck, pHand, dHand, &deckPos, &rounds, &lastCmd, &gameStateCode);

        if(gameStateCode == 0)
        {
            delete[] deck;
            int* deck = makeDeck();
            for(int i = 0 ; i < 52 ; i++)
            {
                int j = rand() % 52;
                int temp;
                temp = deck[i];
                deck[i] = deck[j];
                deck[j] = temp;
            }

            deckPos = 0;
            lastCmd = ' ';
            delete[] pHand;
            delete[] dHand;
            int* dHand = new int[12]{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1};
            int* pHand = new int[12]{0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0};
            gameStateCode = -1;
            rounds = 1;

            for(int i = 0 ; i < 2 ; i++)
            {
                deal(deck, pHand, &deckPos);
                deal(deck, dHand, &deckPos);
            }
   
            showHands(pHand, dHand);
        }
        else if(gameStateCode == 1)
            cout << "Player wins" << endl;
        else if(gameStateCode == 2)
            cout << "Dealer wins" << endl;
        else if(gameStateCode == 3)
            cout << "Dealer busts, player wins" << endl;
        else if(gameStateCode == 4)
            cout << "Player busts, dealer wins" << endl;
        else
            sleep(0);
    }

    delete[] pHand;
    delete[] dHand;
    delete[] deck;

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
        if(hand[11] == 1 && i == 1) //handles obfuscation of dealer's top card using last element flag (line 24)
            cout << " **";
        else 
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

void playRound(int* deck, int* pHand, int* dHand, int* deckPos, int* rounds, char* lastCmd, int* gameStateCode)
{
    char cmd;

    cout << "Round " << *rounds << " Player's turn" << endl << "hit or stand ? [h/s] ";
    cin >> cmd;
    if(cmd == 'h')
        deal(deck, pHand, deckPos);
    updateGameState(pHand, dHand, cmd, lastCmd, gameStateCode);
    showHands(pHand, dHand);
    updateGameState(pHand, dHand, cmd, lastCmd, gameStateCode);
    if(*gameStateCode != -1)
        return;
    *lastCmd = cmd;
    

    cout << "Round " << *rounds << " Dealer's turn" << endl << "hit or stand ? [h/s] ";
   
    sleep(1);
        if(getScore(dHand) < 17)
            cmd = 'h';
        else
            cmd = 's';
    
    cout << cmd << endl;

    if(cmd == 'h')
        deal(deck, dHand, deckPos);
    updateGameState(pHand, dHand, cmd, lastCmd, gameStateCode);
    showHands(pHand, dHand);
    if(*gameStateCode != -1)
        return;
    *lastCmd = cmd;
    

    (*rounds)++;
    return;
}

void updateGameState(int* pHand, int* dHand, char cmd, char* lastCmd, int* gameStateCode)
{
    if(cmd == 's' && cmd == *lastCmd)
    {
        dHand[11] = 0; //remove obfuscation flag
        if((21 - getScore(dHand)) == (21 - getScore(pHand)))
        {
            *gameStateCode = 0;
            return;
        }
        else if((21 - getScore(dHand)) > (21 - getScore(pHand)))
        {
            *gameStateCode = 1;
            return;
        }
        else
         {
            *gameStateCode = 2;
            return;
        }
    }
    else if(getScore(dHand) > 21)
    {
        dHand[11] = 0; //remove obfuscation flag
        *gameStateCode = 3;
        return;
    }
    else if(getScore(pHand) > 21)
    {
        dHand[11] = 0; //remove obfuscation flag
        *gameStateCode = 4;
        return;
    }
    else
        return;
}

int getScore(int* hand)
{
    int total = 0;
    bool hasAce = 0;
    for(int i = 1 ; i <= hand[0] ; i++)
    {
        int cardValue;
        switch(hand[i] % 100)
        {
            default:
                cardValue = hand[i] % 100;
                break;
            case 11 : case 12 : case 13: //syntax learned from stackoverflow
                cardValue = 10;
                break;
            case 14:
                cardValue = 1;
                hasAce = 1;
                break;
        }
    total += cardValue;
    }

    int score = 0;
    if(total <= 11 && hasAce)
    {
        score = total + 10;
    }
    else
        score = total;

    return score;
}