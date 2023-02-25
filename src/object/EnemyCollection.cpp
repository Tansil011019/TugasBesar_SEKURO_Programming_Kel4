#include "EnemyCollection.hpp"

EnemyCollection::EnemyCollection(){
    this->Neff = 0;
}

int EnemyCollection::getNeff(){
    return this->Neff;
}

void EnemyCollection::addEnemy(EnemyPlayer enemy){
    this->arrOfEnemy.push_back(enemy);
    this->Neff++;
}

vector<EnemyPlayer> EnemyCollection::getEnemyArray(){
    return this->arrOfEnemy;
}

void EnemyCollection::removeEnemy(int index){
    this->arrOfEnemy.erase(arrOfEnemy.begin()+index);
    this->Neff--;
}

void EnemyCollection::reset(){
    this->arrOfEnemy.clear();
    this->arrOfEnemy.shrink_to_fit();
    this->Neff = 0;
}