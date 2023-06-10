#include "Player.h"
QString Player::getName() {
    return name;
}
QString Player::getNation() {
    return nation;
}
QString Player::getPosition()
{
    return position;
}
int Player::getMinutes(){
    return this->minutes;
}
int Player::getGoals(){
    return goals;
}
int Player::getAssists(){
    return assists;
}
