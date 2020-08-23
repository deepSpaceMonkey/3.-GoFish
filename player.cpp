// player.cpp
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

#include "player.h"
#include <string>


using namespace std;


void Player::addCard(Card c){ //************
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){ //****************
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){

    int i, j;
    int size = myHand.size();

    if (size < 2){
        return false;
    }

    for (i = 0; i < size - 1 ; i++){
        for (j = i + 1; j < size; j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                c1=myHand[i];
                c2=myHand[j];
                return true;
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const{ // ************
    int size = myHand.size();         // Get the size of the vector
    int Rank = c.getRank();


    for(int i = 0; i < size; i ++){         // Traverse hand
        if(myHand[i].getRank() == Rank){
            return(true);
        }
    }
    return(false);         // No match?




}

Card Player::chooseCardFromHand() const{ // ***************
    long randomIndex = rand() % myHand.size();
    return myHand[randomIndex];


}

bool Player::cardInHand(Card c) const{   // ******************
    int size = myHand.size();     // Get the size of the vector

    for(int i = 0; i < size; i ++){        // Traverse hand
        if((myHand[i].getRank() == c.getRank()) ){
            return(true);
        }
    }
    return(false);       // No match?

}

// Should only work if the cardInHand returns a true!
Card Player::removeCardFromHand(Card c){ // ***************
    // Get the size of the vector
    int size = myHand.size();
    Card tempCard; // Temporary card

    // Traverse hand
    for(int i = 0; i < size; i ++){
        if((myHand[i].getRank() == c.getRank())){ //&& (myHand[i].sameSuitAs(c))
            tempCard = myHand[i];       // Copy the defunct card
            myHand.erase(myHand.begin() + i);     // Delete it from the vector...
            i = -1;
            size--;

        }
    }
    return(tempCard);


}

string Player::showHand() const{   // ****************

    string thisHand;
    int i;
    for (i = 0; i < myHand.size(); i++){
        if (i != myHand.size()){
            thisHand = thisHand + myHand[i].toString();     //Save time by using toString
            thisHand = thisHand + " ";     //Add space for clarity of read
        }
        else{
            thisHand = thisHand + myHand[i].toString();
        }
    }
    return thisHand;

}

string Player::showBooks() const{ // ***************
    string thisHand;
    int i;
    for (i = 0; i < myBook.size(); i++){
        if (i != myBook.size()){
            thisHand = thisHand + myBook[i].toString();     //Save time by using toString
            thisHand = thisHand + " ";     //Add space for clarity of read
        }
        else{
            thisHand = thisHand + myBook[i].toString();
        }
    }
    return thisHand;
}

int Player::getHandSize() const{
    return(myHand.size());
}

int Player::getBookSize() const{
    return(myBook.size());
}

bool Player::checkHandForPair(Card &c1, Card &c2){
    // Get the size of the vector
    int size = myHand.size();

    // Special cases, if there is less than 1 card in the book, always return a zero!
    if(size < 1){
        return(false);
    }

    // Traverse vector and search for match
    for(int exterior_i = 0; exterior_i < size; exterior_i ++) {

        for (int interior_i = 0; interior_i < size; interior_i++) {
            // Compares both cards to check if their the same, if interior and exterior is the same,
            // That means its comparing the *same* card!
            if(((myHand[interior_i].getRank()) == myHand[exterior_i].getRank()) &&
               (myHand[interior_i].sameSuitAs(myHand[exterior_i])) && (interior_i != exterior_i)){

                c1 = myHand[exterior_i];
                c2 = myHand[interior_i];

                return(true);

            }
        }
    }
    // No match?
    return(false);
}

bool Player::sameRankInHand(Card c) const{
    // Get the size of the vector
    int size = myHand.size();


    // Traverse hand
    for(int i = 0; i < size; i ++){
        if(c.getRank() == myHand[i].getRank() ){
            return(true);
        }
    }

    // No match?
    return(false);
}

void Player::findBooks() {
    int size = myHand.size(), i = 0;
    if (size < 4){     //Minimum 4 cards needed for book
        return;
    }
    for (i = 0; i < size - 1 ; i++){

    }
}

Card Player::returnFirst() const{
    return myHand[0];
}

