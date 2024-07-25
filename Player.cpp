#include "Player.h"
#include "Element.h"


Player::Player(int boardSize) {

    this->boardSize = boardSize;
    this->health = 2 * boardSize; //according to instructor

    score = 0; //initialy our score is 0

    this->goldCount = 0;
}




void Player::goldCounter() {
        goldCount++;
        score+= 100; //it will be increase current score 100
        if (goldCount %3 == 0 && goldCount != 0){ //if player found 3 times Gold, then health will be increase
            adjustHealth(boardSize/4);
        }
}
   

void Player::adjustHealth(int adjust) {
    health += adjust;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}

int Player::getGoldCount() const {
    return goldCount;
}

void Player::setGoldCount(int goldCount) {
    Player::goldCount = goldCount;
}

int Player::getHealth()  {
    return health;
}

void Player::setHealth(int health) {
    Player::health = health;
}

int Player::getBoardSize() {
    return boardSize;
}