#include <iostream>
#include "ObjectPlayer.hpp"

ObjectPlayer::ObjectPlayer(){
    this->health = 10;
    this->coor.x = 0;
    this->coor.y = 0;
    this->attackRange = 2;
}

int ObjectPlayer::getHealth() const{
    return this->health;
}

int ObjectPlayer::getKillCount() const{
    return ObjectPlayer::killCount;
}

double ObjectPlayer::getAttackRange() const{
    return this->attackRange;
}

void ObjectPlayer::setHealth(int health){
    this->health = health;
}

void ObjectPlayer::setKillCount(int killCount){
    this->killCount = killCount;
}

coordinate ObjectPlayer::getCoordinate(){
    return this->coor;
}

void ObjectPlayer::setCoordinate(int x, int y){
    this->coor.x = x;
    this->coor.y = y;
}

bool ObjectPlayer::getStatus(){
    if(this->health > 0){
        return false;
    }else{
        return true;
    }
}

void ObjectPlayer::SOUTH(){
    this->coor.y +=1;
}

void ObjectPlayer::WEST(){
    this->coor.x -= 1;
}

void ObjectPlayer::EAST(){
    this->coor.x += 1;
}

void ObjectPlayer::NORTH(){
    this->coor.y -= 1;
}

void ObjectPlayer::reset(){
    this->health = 5;
    ObjectPlayer::killCount = 0;
    this->coor.x = 0;
    this->coor.y = 0;
}

void ObjectPlayer::killEnemy(){
    ObjectPlayer::killCount ++;
}