#include "Player.hpp"

Player::Player() {

}
Player::Player(int id, std::string name, int score, int timestamp) {

}
Player::~Player() {
}

int Player::getId() {
    return id;
}
std::string Player::getName() {
    return name;
}
int Player::getScore() {
    return score;
}
int Player::getTimestamp() {
    return timestamp;
}