//
// Created by temex on 8/24/2024.
//

#ifndef GAME_BLACKJACK_BLACKJACK_H
#define GAME_BLACKJACK_BLACKJACK_H
using namespace std;
#include <iostream>
#include <string>
#include <fstream>


class Blackjack {
private:
    int card;
    int usedCards[11] = {};
    int usedCardsCounter;
    int player[6] = {};
    int playersCardsCounter;
    int dealer[6] = {};
    int dealersCardsCounter;
    int givenCardsCounter;
    int playersHand;
    int dealersHand;
    int winner; //0 no one 1 player 2 dealer
    
    string card1[6], card2[6], card3[6], card4[6],
            card5[6], card6[6], card7[6], card8[6],
            card9[6], card10[6], cardA[6], cardQ[6];
    string playerDisplay;
    string dealerDisplay;
    string playerCards[6];
    string dealerCards[6];

    bool stay;
    bool secondCard;
public:
    Blackjack(); //constructor


    bool Stay();    //verifies if user stayed
    void setStay(bool stay);    //setts stay to false - needed just for "activate switch"
    bool isDealersSecondCard();    //checks if dealers card isn't 2 if it is make it hidden
    void setSecondCard(bool secondCard);

    void startMenu();   //start display
    void endMenu();     //end display
    void bye();

    bool restart;
    bool reset();   //for restarting the game

    void cardsGenerator();   //generates cards
    void addCardsIntoUsed();    //adds cards into usedCards[]
    void checkCardsGenerator();    //checks if cards aren't repeated
    void doubleCheckCardsGenerator();   //checks if already full array is good to play with if isn't generates whole array again (2 last numbers have a small chance to be same, but it doesn't matter right?)

    void givePlayerCard();  //gives player card
    void giveDealerCard();  //gives dealer card
    void hitOrStay();   //gives player choice to get another card or stay
    void countPlayersCards();   //adds up all players cards
    void countDealersCards();   //add up all dealers cards
    void dealersHit();  //gives dealer card if he is below 17
    void checkAce();    //checks for ace and replaces it for 1 if above 21

    void winnerCheck();  //checks who won this round
    void winnerOver21();  //check for winner if both are over 21
    void winnerScreen();    //displays winner info

    void cardsDisplayLibrary();    //every card in a library from 1 to 12
    void displayPlayersCards();  //displays players cards
    void displayDealersCards();  //displays dealers cards
    void addCardsIntoPlayerCards();    //system that saves into var which will be printed
    void addCardsIntoDealerCards();    //system that saves into var which will be printed

    void space();   //2 blank lines
    void displayPlayersCount(); //displays players total cards count
    void displayDealersCount(); //displays dealers total cards count
    void displayPlayer();
    void displayDealer();

    //TESTING
    void displayCardsPlayer();
    void displayCardsDealer();
    void test();
    void test2();
    void test3();
};


#endif //GAME_BLACKJACK_BLACKJACK_H
