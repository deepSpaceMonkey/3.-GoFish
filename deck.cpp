// deck.cpp
// -- EE 312 Project 6
//Ennis Salam and Jesse Valdelamar
//Updated: April 17, 2020

/* Student information for project:
 *
 *
 * On our honor, Ennis Salam and Jesse Valdelamar, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Ennis Salam and Jesse Valdelamar
 * email address: ennis.salam@utexas.edu, valdelamarj13@utexas.edu
 * UTEID: emse4556, jv29493
 * Section 5 digit ID: 16090
 *
 */

#include <cstdlib>
#include "deck.h"
#include "card.h"
using namespace std;



Deck::Deck() {
    int cardRank[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int cardIndex;
    publicIndex = 0;
    for (cardIndex = 0; cardIndex < 13; cardIndex++){     //myCards is of type Card. Do that first
        Card tempCard(cardRank[cardIndex], tempCard.clubs);
        myCards[publicIndex] = tempCard;
        publicIndex++;
    }
    for (cardIndex = 0; cardIndex < 13; cardIndex++){     //myCards is of type Card. Do that first
        Card tempCard(cardRank[cardIndex], tempCard.hearts);
        myCards[publicIndex] = tempCard;
        publicIndex++;

    }
    for (cardIndex = 0; cardIndex < 13; cardIndex++){     //myCards is of type Card. Do that first
        Card tempCard(cardRank[cardIndex], tempCard.spades);
        myCards[publicIndex] = tempCard;
        publicIndex++;

    }
    for (cardIndex = 0; cardIndex < 13; cardIndex++){     //myCards is of type Card. Do that first
        Card tempCard(cardRank[cardIndex], tempCard.diamonds);
        myCards[publicIndex] = tempCard;
        publicIndex++;
    }

    publicIndex = publicIndex - 1;     //For compatibility with array. 52 cards but 51st element
}

int Deck::size() const {
    return publicIndex + 1;     //Since array index is actual - 1
}



Card Deck::dealCard() {
    if (publicIndex == -1){     //So the "fail" is publicIndex equaling -1. To check if deck is empty, Always check decksize = 0 or publicIndex = -1 instead of having a failed card because idk how to return failed card.
        Card tempCard = myCards[1];
        return  tempCard;
    }

    else{
        Card tempCard = myCards[publicIndex];
        publicIndex = publicIndex - 1;
        return tempCard;
    }
}

void Deck::shuffle() {

    int numCards = 52, i = 0;

    for (i = 0; i < (numCards * 4); i++){
        int randomNum1 = rand() % numCards;
        Card tempCard1 = myCards[randomNum1];
        int randomNum2 = rand() % numCards;
        Card tempCard2 = myCards[randomNum2];
        myCards[randomNum1] = tempCard2;
        myCards[randomNum2] = tempCard1;

    }

}



void Deck::operator = (const Card& rhs) const{
    *this = rhs;
}

