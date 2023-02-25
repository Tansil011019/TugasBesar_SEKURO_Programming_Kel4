#include "EnemyPlayer.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

int randomGenerator(){
    int randomInt = rand()%21-10;
    return randomInt;
}

EnemyPlayer::EnemyPlayer(){
    srand(time(nullptr));
    this->health = 5;
    this->coor.x = randomGenerator();
    this->coor.y = randomGenerator();
    this->attackRange = 2;
    this->distanceWithPlayer = sqrt(pow((ObjectPlayer::getCoordinate().x-this->coor.x), 2) + pow((ObjectPlayer::getCoordinate().y-this->coor.y), 2));
}

int EnemyPlayer::getHealth() const{
    return this->health;
}

double EnemyPlayer::getAttackRange() const{
    return this->attackRange;
}

double EnemyPlayer::getDistanceWithPlayer(coordinate player){
    return sqrt(pow((player.x-this->coor.x), 2) + pow((player.y-this->coor.y), 2));
}

void EnemyPlayer::setHealth(int health){
    cout << "Attack Successful" << endl;
    this->health = health;
}

coordinate EnemyPlayer::getCoordinate(){
    return this->coor;
}
