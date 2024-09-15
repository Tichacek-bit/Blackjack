//
// Created by temex on 8/24/2024.
//

#include "Blackjack.h"

Blackjack::Blackjack() : usedCardsCounter(0), card(0), givenCardsCounter(0),
                            playersCardsCounter(0), dealersCardsCounter(0),
                            stay(false), playersHand(0), dealersHand(0),
                            winner(0), secondCard(false) {}

void Blackjack::cardsGenerator() {
    int MIN=1;
    int MAX=11;
    card = (rand() % (MAX - MIN + 1)) + MIN;
}

void Blackjack::addCardsIntoUsed() {
    usedCards[usedCardsCounter] = card;
    usedCardsCounter += 1;
}

void Blackjack::checkCardsGenerator() {
    for(int i = 0; i < 10; i++){
        if(card == usedCards[i]){
            cardsGenerator();
            checkCardsGenerator();
        }
    }
}

void Blackjack::doubleCheckCardsGenerator() {
    for(int i = 0; i < 11; i++){
       for(int j = 0; j < 11; j++){
           if(i == j){
               break;
           }
            if(usedCards[i] != usedCards[j]){
                break;
                }
            else{
                for(int k = 0; k < 11; k++) {
                    cardsGenerator();
                    checkCardsGenerator();
                    addCardsIntoUsed();
                }
                doubleCheckCardsGenerator();
            }
       }
   }
}

void Blackjack::givePlayerCard() {
    player[playersCardsCounter] = usedCards[givenCardsCounter];
    playersCardsCounter += 1;
    givenCardsCounter += 1;
}

void Blackjack::giveDealerCard() {
    dealer[dealersCardsCounter] = usedCards[givenCardsCounter];
    dealersCardsCounter += 1;
    givenCardsCounter += 1;
}

void Blackjack::hitOrStay() {
    string choice;
    int a;
reset:
    cout << " Hit or Stay?\n";
    cout << "~";
    cin >> choice;
    if(choice == "h"){a = 1;}
    else if(choice == "H"){a = 2;}
    else if(choice == "hit"){a = 3;}
    else if(choice == "Hit"){a = 4;}
    else if(choice == "HIT"){a = 5;}
    else if(choice == "s"){a = 6;}
    else if(choice == "S"){a = 7;}
    else if(choice == "stay"){a = 8;}
    else if(choice == "Stay"){a = 9;}
    else if(choice == "STAY"){a = 10;}
    else{cout << " Try again.\n";goto reset;}

    switch (a) {
        case 1:
            givePlayerCard();
            checkAce();

            addCardsIntoPlayerCards();
            addCardsIntoDealerCards();

            displayDealer();
            displayDealersCards();
            displayDealersCount();
            space();
            displayPlayer();
            displayPlayersCards();
            displayPlayersCount();
            space();

            hitOrStay();
            break;
        case 2:
            givePlayerCard();
            checkAce();

            addCardsIntoPlayerCards();
            addCardsIntoDealerCards();

            displayDealer();
            displayDealersCards();
            displayDealersCount();
            space();
            displayPlayer();
            displayPlayersCards();
            displayPlayersCount();
            space();

            hitOrStay();
            break;
        case 3:
            givePlayerCard();
            checkAce();

            addCardsIntoPlayerCards();
            addCardsIntoDealerCards();

            displayDealer();
            displayDealersCards();
            displayDealersCount();
            space();
            displayPlayer();
            displayPlayersCards();
            displayPlayersCount();
            space();

            hitOrStay();
            break;
        case 4:
            givePlayerCard();
            checkAce();

            addCardsIntoPlayerCards();
            addCardsIntoDealerCards();

            displayDealer();
            displayDealersCards();
            displayDealersCount();
            space();
            displayPlayer();
            displayPlayersCards();
            displayPlayersCount();
            space();

            hitOrStay();
            break;
        case 5:
            givePlayerCard();
            checkAce();

            addCardsIntoPlayerCards();
            addCardsIntoDealerCards();

            displayDealer();
            displayDealersCards();
            displayDealersCount();
            space();
            displayPlayer();
            displayPlayersCards();
            displayPlayersCount();
            space();

            hitOrStay();
            break;
        case 6:
            stay = true;
            break;
        case 7:
            stay = true;
            break;
        case 8:
            stay = true;
            break;
        case 9:
            stay = true;
            break;
        case 10:
            stay = true;
            break;
        default:
            cout << "\n Try again\n";
            hitOrStay();
    }
}

bool Blackjack::Stay() {
    if(stay){
        return true;
    }
    return false;
}

void Blackjack::setStay(bool stay) {
    Blackjack::stay = stay;
}

void Blackjack::countPlayersCards() {
    playersHand = 0;
    for(int i = 0; i < 6; i++){
        playersHand += player[i];
    }
}

void Blackjack::countDealersCards() {
    dealersHand = 0;
    for(int i = 0; i < 6; i++){
        dealersHand += dealer[i];
    }
}

void Blackjack::dealersHit() {
    countDealersCards();
    if (dealersHand < 17){
        giveDealerCard();
        checkAce();
        dealersHit();
    }
}

void Blackjack::checkAce() {
    countPlayersCards();
    countDealersCards();
    if(playersHand >= 22){
        for(int i = 0; i < playersCardsCounter; i++){
            if(player[i] == 11){
                player[i] = 1;
                return;
            }
        }
    }
    else if(dealersHand >= 22){
        for(int i = 0; i < dealersCardsCounter; i++){
            if(dealer[i] == 11){
                dealer[i] = 1;
                return;
            }
        }
    }
}

void Blackjack::winnerCheck() {
    countPlayersCards();
    countDealersCards();
    if((dealersHand > 21) && (playersHand > 21)){
        winnerOver21();
    }
    else if((playersHand > 21) && (dealersHand <= 21)){
        winner = 2;
        return;
    }
    else if((playersHand <= 21) && (dealersHand > 21)){
        winner = 1;
        return;
    }
    else if(playersHand == dealersHand){
        if(playersCardsCounter < dealersCardsCounter){
            winner = 1;
            return;
        }
        else if(playersCardsCounter > dealersCardsCounter){
            winner = 2;
            return;
        }
    }
    else if((playersHand <= 21) && (dealersHand <= 21)){
        if(playersHand > dealersHand){
            winner = 1;
            return;
        }
        else if(playersHand < dealersHand){
            winner = 2;
            return;
        }
    }
    else{
        winner = 3;
    }
}

void Blackjack::winnerOver21() {
    if(playersHand < dealersHand){
        winner = 1;
        return;
    }
    else if(playersHand > dealersHand){
        winner = 2;
        return;
    }
}

void Blackjack::winnerScreen() {
    if(winner == 1) {
        cout << "   Player wins." << endl;
        space();
    }
    else if(winner == 2) {
        cout << "   Dealer wins." << endl;
        space();
    }
    else if(winner == 3){
        cout << "   TIE." << endl;
        space();
    }
    else if(winner == 0){
        cout << "winner 0 error" << endl;
    }
}

void Blackjack::cardsDisplayLibrary() {
    card1[0] = ".------.";  //1
    card1[1] = "|1.--. |";
    card1[2] = "| :/\\: |";
    card1[3] = "| (__) |";
    card1[4] = "| '--'1|";
    card1[5] = "`------'";
    card2[0] = ".------.";  //2
    card2[1] = "|2.--. |";
    card2[2] = "| (\\/) |";
    card2[3] = "| :\\/: |";
    card2[4] = "| '--'2|";
    card2[5] = "`------'";
    card3[0] = ".------.";  //3
    card3[1] = "|3.--. |";
    card3[2] = "| :(): |";
    card3[3] = "| ()() |";
    card3[4] = "| '--'3|";
    card3[5] = "`------'";
    card4[0] = ".------.";  //4
    card4[1] = "|4.--. |";
    card4[2] = "| :/\\: |";
    card4[3] = "| :\\/: |";
    card4[4] = "| '--'4|";
    card4[5] = "`------'";
    card5[0] = ".------.";  //5
    card5[1] = "|5.--. |";
    card5[2] = "| :/\\: |";
    card5[3] = "| (__) |";
    card5[4] = "| '--'5|";
    card5[5] = "`------'";
    card6[0] = ".------.";  //6
    card6[1] = "|6.--. |";
    card6[2] = "| (\\/) |";
    card6[3] = "| :\\/: |";
    card6[4] = "| '--'6|";
    card6[5] = "`------'";
    card7[0] = ".------.";  //7
    card7[1] = "|7.--. |";
    card7[2] = "| :(): |";
    card7[3] = "| ()() |";
    card7[4] = "| '--'7|";
    card7[5] = "`------'";
    card8[0] = ".------.";  //8
    card8[1] = "|8.--. |";
    card8[2] = "| :/\\: |";
    card8[3] = "| :\\/: |";
    card8[4] = "| '--'8|";
    card8[5] = "`------'";
    card9[0] = ".------.";  //9
    card9[1] = "|9.--. |";
    card9[2] = "| :/\\: |";
    card9[3] = "| (__) |";
    card9[4] = "| '--'9|";
    card9[5] = "`------'";
    card10[0] = ".------.";  //10
    card10[1] = "|10.-. |";
    card10[2] = "| :/\\: |";
    card10[3] = "| :\\/: |";
    card10[4] = "| '-'10|";
    card10[5] = "`------'";
    cardA[0] = ".------."; //11 / Ace
    cardA[1] = "|A.--. |";
    cardA[2] = "| (\\/) |";
    cardA[3] = "| :\\/: |";
    cardA[4] = "| '--'A|";
    cardA[5] = "`------'";
    cardQ[0] = ".------.";  //Question mark
    cardQ[1] = "|?.--. |";
    cardQ[2] = "| :(): |";
    cardQ[3] = "| ()() |";
    cardQ[4] = "| '--'?|";
    cardQ[5] = "`------'";
}

void Blackjack::displayPlayersCards() {
    cout << playerDisplay;
}

void Blackjack::displayDealersCards() {
    cout << dealerDisplay;
}

void Blackjack::addCardsIntoPlayerCards() {
    playerDisplay = "";
    int card_ = 0;
    int line = 1;
start:
        switch (player[card_]) {
            case 0:
                playerDisplay += "\n";
                card_ = 0;
                if(line == 7){
                    return;
                }
                else{
                    line++;
                }
                goto start;
            case 1:
                switch (line) {
                    case 1:
                        playerDisplay += card1[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card1[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card1[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card1[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card1[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card1[5] + " ";
                        card_++;
                        goto start;
                }
            case 2:
                switch (line) {
                    case 1:
                        playerDisplay += card2[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card2[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card2[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card2[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card2[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card2[5] + " ";
                        card_++;
                        goto start;
                }
            case 3:
                switch (line) {
                    case 1:
                        playerDisplay += card3[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card3[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card3[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card3[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card3[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card3[5] + " ";
                        card_++;
                        goto start;
                }
            case 4:
                switch (line) {
                    case 1:
                        playerDisplay += card4[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card4[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card4[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card4[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card4[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card4[5] + " ";
                        card_++;
                        goto start;
                }
            case 5:
                switch (line) {
                    case 1:
                        playerDisplay += card5[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card5[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card5[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card5[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card5[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card5[5] + " ";
                        card_++;
                        goto start;
                }
            case 6:
                switch (line) {
                    case 1:
                        playerDisplay += card6[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card6[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card6[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card6[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card6[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card6[5] + " ";
                        card_++;
                        goto start;
                }
            case 7:
                switch (line) {
                    case 1:
                        playerDisplay += card7[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card7[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card7[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card7[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card7[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card7[5] + " ";
                        card_++;
                        goto start;
                }
            case 8:
                switch (line) {
                    case 1:
                        playerDisplay += card8[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card8[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card8[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card8[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card8[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card8[5] + " ";
                        card_++;
                        goto start;
                }
            case 9:
                switch (line) {
                    case 1:
                        playerDisplay += card9[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card9[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card9[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card9[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card9[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card9[5] + " ";
                        card_++;
                        goto start;
                }
            case 10:
                switch (line) {
                    case 1:
                        playerDisplay += card10[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += card10[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += card10[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += card10[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += card10[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += card10[5] + " ";
                        card_++;
                        goto start;
                }
            case 11:
                switch (line) {
                    case 1:
                        playerDisplay += cardA[0] + " ";
                        card_++;
                        goto start;
                    case 2:
                        playerDisplay += cardA[1] + " ";
                        card_++;
                        goto start;
                    case 3:
                        playerDisplay += cardA[2] + " ";
                        card_++;
                        goto start;
                    case 4:
                        playerDisplay += cardA[3] + " ";
                        card_++;
                        goto start;
                    case 5:
                        playerDisplay += cardA[4] + " ";
                        card_++;
                        goto start;
                    case 6:
                        playerDisplay += cardA[5] + " ";
                        card_++;
                        goto start;
                }
        }
}

void Blackjack::addCardsIntoDealerCards() {
    dealerDisplay = "";
    int card_ = 0;
    int line = 1;
    int temp = 12;
    int tempDealer[6];
    for(int i = 0; i < 6; i++){
        tempDealer[i] = dealer[i];
    }
start:
    if(secondCard){
        tempDealer[1] = temp;
    }
    else{
        tempDealer[1] = dealer[1];
    }
    switch (tempDealer[card_]) {
        case 0:
            dealerDisplay += "\n";
            card_ = 0;
            if (line == 7) {
                return;
            } else {
                line++;
            }
            goto start;
        case 1:
            switch (line) {
                case 1:
                    dealerDisplay += card1[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card1[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card1[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card1[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card1[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card1[5] + " ";
                    card_++;
                    goto start;
            }
        case 2:
            switch (line) {
                case 1:
                    dealerDisplay += card2[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card2[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card2[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card2[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card2[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card2[5] + " ";
                    card_++;
                    goto start;
            }
        case 3:
            switch (line) {
                case 1:
                    dealerDisplay += card3[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card3[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card3[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card3[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card3[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card3[5] + " ";
                    card_++;
                    goto start;
            }
        case 4:
            switch (line) {
                case 1:
                    dealerDisplay += card4[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card4[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card4[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card4[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card4[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card4[5] + " ";
                    card_++;
                    goto start;
            }
        case 5:
            switch (line) {
                case 1:
                    dealerDisplay += card5[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card5[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card5[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card5[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card5[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card5[5] + " ";
                    card_++;
                    goto start;
            }
        case 6:
            switch (line) {
                case 1:
                    dealerDisplay += card6[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card6[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card6[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card6[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card6[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card6[5] + " ";
                    card_++;
                    goto start;
            }
        case 7:
            switch (line) {
                case 1:
                    dealerDisplay += card7[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card7[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card7[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card7[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card7[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card7[5] + " ";
                    card_++;
                    goto start;
            }
        case 8:
            switch (line) {
                case 1:
                    dealerDisplay += card8[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card8[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card8[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card8[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card8[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card8[5] + " ";
                    card_++;
                    goto start;
            }
        case 9:
            switch (line) {
                case 1:
                    dealerDisplay += card9[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card9[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card9[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card9[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card9[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card9[5] + " ";
                    card_++;
                    goto start;
            }
        case 10:
            switch (line) {
                case 1:
                    dealerDisplay += card10[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += card10[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += card10[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += card10[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += card10[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += card10[5] + " ";
                    card_++;
                    goto start;
            }
        case 11:
            switch (line) {
                case 1:
                    dealerDisplay += cardA[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += cardA[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += cardA[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += cardA[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += cardA[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += cardA[5] + " ";
                    card_++;
                    goto start;
            }
        case 12:
            switch (line) {
                case 1:
                    dealerDisplay += cardQ[0] + " ";
                    card_++;
                    goto start;
                case 2:
                    dealerDisplay += cardQ[1] + " ";
                    card_++;
                    goto start;
                case 3:
                    dealerDisplay += cardQ[2] + " ";
                    card_++;
                    goto start;
                case 4:
                    dealerDisplay += cardQ[3] + " ";
                    card_++;
                    goto start;
                case 5:
                    dealerDisplay += cardQ[4] + " ";
                    card_++;
                    goto start;
                case 6:
                    dealerDisplay += cardQ[5] + " ";
                    card_++;
                    goto start;
            }
    }
}

bool Blackjack::isDealersSecondCard() {
    if(dealer[1] != 0){
        return true;
    }
    else{
        return false;
    }
}

void Blackjack::setSecondCard(bool secondCard) {
    Blackjack::secondCard = secondCard;
}

void Blackjack::startMenu() {
    cout << " ______  __      ______  ______  __  __      __  ______  ______  __  __    \n"
            "/\\  == \\/\\ \\    /\\  __ \\/\\  ___\\/\\ \\/ /     /\\ \\/\\  __ \\/\\  ___\\/\\ \\/ /    \n"
            "\\ \\  __<\\ \\ \\___\\ \\  __ \\ \\ \\___\\ \\  _\"-.  _\\_\\ \\ \\  __ \\ \\ \\___\\ \\  _\"-.  \n"
            " \\ \\_____\\ \\_____\\ \\_\\ \\_\\ \\_____\\ \\_\\ \\_\\/\\_____\\ \\_\\ \\_\\ \\_____\\ \\_\\ \\_\\ \n"
            "  \\/_____/\\/_____/\\/_/\\/_/\\/_____/\\/_/\\/_/\\/_____/\\/_/\\/_/\\/_____/\\/_/\\/_/ \n";
    cout << "Rules are in same folder as .cpp file.\n";
    }

void Blackjack::endMenu() {
    string choice;
reset:
    cout << " Restart(Y/N)?\n";
    cout << "~";
    cin >> choice;
    if(choice == "y"){restart = true;}
    else if(choice == "Y"){restart = true;}
    else if(choice == "yes"){restart = true;}
    else if(choice == "Yes"){restart = true;}
    else if(choice == "YES"){restart = true;}
    else if(choice == "n"){restart = false;}
    else if(choice == "N"){restart = false;}
    else if(choice == "no"){restart = false;}
    else if(choice == "No"){restart = false;}
    else if(choice == "NO"){restart = false;}
    else{cout << " Try again.\n";goto reset;}
}

bool Blackjack::reset() {
    while(restart){
        return true;
    }
    return false;
}

void Blackjack::space() {
    cout << "\n\n";
}

void Blackjack::displayPlayersCount() {
    countPlayersCards();
    cout << " Total cards value: " << playersHand << endl;
}

void Blackjack::displayDealersCount() {
    countDealersCards();
    if(secondCard){
        cout << " Total cards value: " << dealersHand - dealer[1] << endl;
    }
    else{
        cout << " Total cards value: " << dealersHand << endl;
    }
}

void Blackjack::displayPlayer() {
    cout << " PLAYER" << endl;
}

void Blackjack::displayDealer() {
    cout << " DEALER" << endl;
}

void Blackjack::bye() {
    cout << " ______  ______  ______  _____   ______  __  __  ______    \n"
            "/\\  ___\\/\\  __ \\/\\  __ \\/\\  __-./\\  == \\/\\ \\_\\ \\/\\  ___\\   \n"
            "\\ \\ \\__ \\ \\ \\/\\ \\ \\ \\/\\ \\ \\ \\/\\ \\ \\  __<\\ \\____ \\ \\  __\\   \n"
            " \\ \\_____\\ \\_____\\ \\_____\\ \\____-\\ \\_____\\/\\_____\\ \\_____\\ \n"
            "  \\/_____/\\/_____/\\/_____/\\/____/ \\/_____/\\/_____/\\/_____/ \n";
}

//     |       functions for testing
//     \/
void Blackjack::displayCardsPlayer() {
    cout << "players cards" << endl;
    for(int i = 0; i < 6; i++){
        cout << player[i] << " ";
    }
    cout << endl;
}

void Blackjack::displayCardsDealer() {
    cout << "dealers cards" << endl;
    for(int i = 0; i < 6; i++){
        cout << dealer[i] << " ";
    }
    cout << endl;
}

void Blackjack::test() {
    countDealersCards();
    countPlayersCards();
    cout << "players count: " << playersHand << endl;
    cout << "dealers count: " << dealersHand << endl;
}

void Blackjack::test2() {
    cout << "secondCard: " << isDealersSecondCard() << endl;
}

void Blackjack::test3() {
    cout << card1[0] + " " << "is there a space" << endl;
}

