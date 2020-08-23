// go_fish.cpp
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
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "player.h"
#include "deck.h"
#include "card.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( ){

    ofstream myfile;
    myfile.open ("gofish_results.txt");

    int numCards = 5, i = 0, deckSize, round = 0;
    Card guess, e1, e2, j1, j2, remove;
    bool isTrue, emptyHand;
    string hand1, hand2;
    Player *p1 = new Player("Ennis");
    Player *p2 = new Player("Jesse");

    Deck* d = new Deck;  //create a deck of cards
    d->shuffle();


    for (i = 0; i < 7; i++) {     //each player has 7 cards
        p1->addCard(d->dealCard());
        p2->addCard(d->dealCard());
    }
    hand1 = p1->showHand();
    hand2 = p2->showHand();
    myfile << "Ennis's Cards: "<< hand1 << endl;
    myfile << "Jesse's Cards: "<< hand2 << endl;

    deckSize = d->size();
    while(deckSize > 0) {
        round = round + 1;
        while (p1->checkHandForBook(e1, e2)) {
            p1->removeCardFromHand(e1);
            p1->removeCardFromHand(e2);
            p1->bookCards(e1, e2);

        }
        while (p2->checkHandForBook(j1, j2)) {     //At his point no one has more than 1 card of a particular suit
            p2->removeCardFromHand(j1);
            p2->removeCardFromHand(j2);
            p2->bookCards(j1, j2);
        }


        isTrue = true;
        while (isTrue){      //This loop is player 1's turn

            if (p1->getHandSize() > 0) {     //If Ennis is not out of cards
                guess = p1->chooseCardFromHand();    //cout is in the method
                myfile << "Do you have any " << guess.getRank() << "'s?" << endl;
                isTrue = p2->cardInHand(guess);

                if (isTrue) {     //If Jesse has Ennis's guessed card
                    myfile << "Yes Jesse does :)" << endl;
                    remove = p2->removeCardFromHand(guess);
                    p1->addCard(remove);
                    p1->checkHandForBook(e1,e2);     //Here, the only cards that have the same suit are 1 from player and 1 taken from player
                    p1->removeCardFromHand(e1);
                    p1->removeCardFromHand(e2);
                    p1->bookCards(e1, e2);

                } else {     // If Jesse does not have Ennis's Card
                    myfile << "No Jesse doesn't :(" << endl;
                    deckSize = d->size();
                    isTrue = false;
                    if (deckSize > 0) {
                        p1->addCard(d->dealCard());
                        if (p1->checkHandForBook(e1,e2)){                 //Add card to book if dealt card shares suit with one of player's cards
                            p1->bookCards(e1, e2);
                            p1->removeCardFromHand(e1);
                            p1->removeCardFromHand(e2);
                        }
                    }
                }
            }
            else{
                if (deckSize > 0) {     //If Ennis has empty hand and there are still cards in deck, draw
                    p1->addCard(d->dealCard());
                    if (p1->checkHandForBook(e1,e2)){                 //Add card to book if dealt card shares suit with one of player's cards
                        p1->bookCards(e1, e2);
                        p1->removeCardFromHand(e1);
                        p1->removeCardFromHand(e2);
                    }
                }
                else{     //If deck is also empty, false
                    isTrue = false;
                }
            }

        }



        isTrue = true;
        while (isTrue) {     //This loop is player 2's turn
            if (p2->getHandSize() > 0) {     //If Ennis is not out of cards
                guess = p2->chooseCardFromHand();    //cout is in the method
                myfile << "Do you have any " << guess.getRank() << "'s?" << endl;
                isTrue = p1->cardInHand(guess);

                if (isTrue) {     //If Jesse has Ennis's guessed card
                    myfile << "Yes Ennis does :)" << endl;
                    remove = p1->removeCardFromHand(guess);
                    p2->addCard(remove);
                    p2->checkHandForBook(j1,j2);     //Here, the only cards that have the same suit are 1 from player and 1 taken from player
                    p2->removeCardFromHand(j1);
                    p2->removeCardFromHand(j2);
                    p2->bookCards(j1, j2);

                } else {     // If Ennis does not have Jesse's Card
                    myfile << "No Ennis doesn't :(" << endl;
                    deckSize = d->size();
                    isTrue = false;
                    if (deckSize > 0) {
                        p2->addCard(d->dealCard());
                        if (p2->checkHandForBook(j1,j2)){                 //Add card to book if dealt card shares suit with one of player's cards
                            p2->bookCards(j1, j2);
                            p2->removeCardFromHand(j1);
                            p2->removeCardFromHand(j2);
                        }
                    }

                }
            }
            else{
                if (deckSize > 0) {     //If Ennis has empty hand and there are still cards in deck, draw
                    p2->addCard(d->dealCard());
                    if (p2->checkHandForBook(j1,j2)){                 //Add card to book if dealt card shares suit with one of player's cards
                        p2->bookCards(j1, j2);
                        p2->removeCardFromHand(j1);
                        p2->removeCardFromHand(j2);
                    }
                }
                else{     //If deck is also empty, false
                    isTrue = false;
                }
            }

        }
        myfile << "\n End of Round " << round << ":" << endl;
        hand1 = p1->showHand();
        hand2 = p2->showHand();
        myfile << "Ennis's Cards: "<< hand1 << endl;
        myfile << "Jesse's Cards: "<< hand2 << "\n \n" << endl;
    }

    p1->removeCardFromHand(p1->returnFirst());
    myfile << "\n End of Round " << round + 1 << ":" << endl;
    hand1 = p1->showHand();
    hand2 = p2->showHand();
    myfile << "Ennis's Cards: "<< hand1 << endl;
    myfile << "Jesse's Cards: "<< hand2 << "\n \n" << endl;

    if (p1->getBookSize() > p2->getBookSize()){
        myfile << "Ennis WON!!!!! :)" << endl;
    }
    else if (p1->getBookSize() > p2->getBookSize()){
        myfile << "Jessie won :(" << endl;
    }

    else if (p1->getBookSize() == p2->getBookSize()){
        myfile << "It's a tie :(" << endl;
    }

    cout << " \n end of program" << endl;
    myfile << " \n end of program" << endl;

    myfile.close();

    delete d;
    delete p1;
    delete p2;

    return EXIT_SUCCESS;
    //return 0;
}




