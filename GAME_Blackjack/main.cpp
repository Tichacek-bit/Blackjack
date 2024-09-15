#include "Blackjack.h"

int main() {
start:
    srand(time(NULL));
    Blackjack GAME;
    GAME.cardsDisplayLibrary();
    for (int i = 0; i <= 10; i++) {
        GAME.cardsGenerator();
        GAME.checkCardsGenerator();
        GAME.addCardsIntoUsed();
    }
    GAME.doubleCheckCardsGenerator();

    GAME.startMenu();
        GAME.givePlayerCard();
        GAME.giveDealerCard();

        GAME.givePlayerCard();
        GAME.giveDealerCard();
        GAME.setSecondCard(true);
        GAME.isDealersSecondCard();

        GAME.addCardsIntoPlayerCards();
        GAME.addCardsIntoDealerCards();

        GAME.displayDealer();
        GAME.displayDealersCards();
        GAME.displayDealersCount();
        GAME.space();
        GAME.displayPlayer();
        GAME.displayPlayersCards();
        GAME.displayPlayersCount();
        GAME.space();

        GAME.hitOrStay();
        GAME.Stay();
        GAME.setSecondCard(false);

        GAME.dealersHit();

        GAME.addCardsIntoPlayerCards();
        GAME.addCardsIntoDealerCards();

        GAME.displayDealer();
        GAME.displayDealersCards();
        GAME.displayDealersCount();
        GAME.space();
        GAME.displayPlayer();
        GAME.displayPlayersCards();
        GAME.displayPlayersCount();
        GAME.space();

        GAME.winnerCheck();
        GAME.winnerScreen();

        GAME.endMenu();
        if(GAME.reset()){goto start;}else{GAME.bye();}

    return 0;
}
