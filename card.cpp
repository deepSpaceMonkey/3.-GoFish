//card.cpp
// -- EE 312 Project #6
//Ennis Salam and Jesse Valdelamar
//Updated: 4/17/2020

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

#include <string>
#include "card.h"

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;     //Read more about enum
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;     //Read more about enum
}

int Card::getRank()  const{// return rank, 1..13
    return myRank;
}

string Card::suitString(Suit s)      const{// return "s", "h",...
    if (s == spades){
        return "s";
    }
    else if (s == hearts){
        return "h";
    }
    else if (s == diamonds){
        return "d";
    }
    else {     // s == clubs
        return "c";
    }
}

string Card::rankString(int r)       const{     // return "A", "2", ..."Q"
    if (myRank == 1){
        return "A";
    }
    else if (myRank == 10){
        return "J";
    }
    else if (myRank == 11){
        return "Q";
    }
    else if (myRank == 12){
        return "K";
    }
    else{
        string str = intToString(r);     //converts int to str
        return str;
    }
}

bool Card::sameSuitAs(const Card& c) const{     // true if suit same as c
    if(c.mySuit == mySuit){
        return 1;
    }
    else{
        return 0;
    }
}

string Card::toString() const {     // return string version e.g. Ac 4h Js
    string tempSuit, tempRank;
    //string tempRank = intToString(myRank);    //converts int to str
   // string tempRank = to_string(myRank);     //converts int to str
    tempRank = intToString(myRank);
   // tempRank = this->rankString(myRank);
    tempSuit = this->suitString(mySuit);

    string completeSyntax = tempRank + tempSuit;
    return completeSyntax;
}


bool Card::operator == (const Card& rhs) const{
    if (this->toString() == rhs.toString()){
        return 1;
    }
    else{
        return 0;
    }
}

bool Card::operator != (const Card& rhs) const{
    if (this->toString() != rhs.toString()){
        return 1;
    }
    else{
        return 0;
    }
}

string Card::intToString (int x) const{
    if (x == 1){
        return ("1");
    }
    else if (x == 2){
        return ("2");
    }
    else if (x == 3){
        return ("3");
    }
    else if (x == 4){
        return ("4");
    }
    else if (x == 5){
        return ("5");
    }
    else if (x == 6){
        return ("6");
    }
    else if (x == 7){
        return ("7");
    }
    else if (x == 8){
        return ("8");
    }
    else if (x == 9){
        return ("9");
    }
    else if (x == 10){
        return ("10");
    }
    else if (x == 11){
        return ("11");
    }
    else if (x == 12){
        return ("12");
    }
    else{
        return ("13");
    }
}





