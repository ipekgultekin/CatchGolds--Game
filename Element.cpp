#include "Element.h"
#include "Player.h"

Element::Element() {
    size = 0;
    representBoard = 'N'; //non-defined
    effect = 'N'; //non-defined
}

Element::Element(int size) {

    this->size = size;
}


void Food::Effect(Player& player) { //if the coordinates matches with "F"
    int effect = player.getBoardSize()/6; //the amount of effect is calculated according to instructors
    player.adjustHealth(effect); //it increases player object's health

}
   
void Wood::Effect(Player& player) {
    int effect = player.getBoardSize()/8;//the amount of effect is calculated according to instructors
    player.adjustHealth(effect); //it increases player object's health
}

void MedicalSupplies::Effect(Player& player) { //if the coordinates matches with "H"
    int effect = player.getBoardSize()/4;//the amount of effect is calculated according to instructors
    player.adjustHealth(effect);//it increases player object's health
}

void Wolf::Effect(Player& player) { //if the coordinates matches with "W"
    int effect = -player.getBoardSize()/4; //it is damage so it will be -
    player.adjustHealth(effect); //it decreases player object's health
    //polymorphism help us
}

void Bear::Effect (Player& player){
    int effect = -player.getBoardSize()/2; //it is damage so it will be -
    player.adjustHealth(effect); //it decreases player object's health
    //abstraction help us
}

void Gold::Effect(Player& player) {
    player.goldCounter(); //player object's gold count will increase
    //abstraction and encapsulation help us

}