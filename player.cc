#include "player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player(int character) {
    if (character == 1) {
        name = "Goose";
        icon = 'G';
    } else if (character == 2) {
        name = "GRT Bus";
        icon = 'B';
    } else if (character == 3) {
        name = "Tim Hortons Doughnut";
        icon = 'D';
    } else if (character == 4) {
        name = "Professor";
        icon = 'P';
    } else if (character == 5) {
        name = "Student";
        icon = 'S';
    } else if (character == 6) {
        name = "Money";
        icon = '$';
    } else if (character == 7) {
        name = "Laptop";
        icon = 'L';
    } else if (character == 8) {
        name = "Pink tie";
        icon = 'T';
    } else {
        // Fallback if invalid input
        cout << "PLAYER CLASS CHARACTER ERROR (LINE SHOULD NOT BE REACHED)" << endl;
    }
    charNum = character;
}
        
void Player::setPosition(int building) { //0-39
    currentPosition = building;
}

int Player::getPosition() {
    return currentPosition;
}

int Player::getCharNum() {
    return charNum;
}

char Player::getIcon() {
    return icon;
}

int Player::getTimCups() {
    return timCups;
}

void Player::setTimCups(int cups) {
    timCups = cups;
    return;
}

int Player::move(int spaces) {
    currentPosition = (((currentPosition + spaces) % 40) + 40) % 40; 
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

void Player::setTimsLine(int num) {
    inTimsLineMoves = num;
}

int Player::getTimsLine() {
    return inTimsLineMoves;
}



