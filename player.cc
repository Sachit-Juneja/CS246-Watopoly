#include "player.h"
#include <string>

using namespace std;

Player::Player(std::string name): name{name} {

}
        
void Player::setPosition(int building) {
    currentPosition = building;
}

int Player::getPosition() {
    return currentPosition;
}


int Player::move(int numBuildings) {
    currentPosition = (((currentPosition + numBuildings) % 40) + 40) % 40; 
    return currentPosition;
}

string Player::getName() {
    return name;
}

int Player::addMoney(int amount) {
    money += amount;
    return money; 
}

int Player::getMoney() {
    return money;
}

