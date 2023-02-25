#include "EnemyCollection.hpp"
#include <iostream>
using namespace std;

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

void EnemyCollection::changeHealth(vector<EnemyPlayer> enemyInRange){
    if (enemyInRange.size() > 0){
        for (int i= 0; i<this->Neff; i++){
            for (int j= 0; j<enemyInRange.size(); j++){
                if(enemyInRange[j].getCoordinate().x == this->arrOfEnemy[i].getCoordinate().x && enemyInRange[j].getCoordinate().y == this->arrOfEnemy[i].getCoordinate().y){
                    cout << "Copying" << endl;
                    this->arrOfEnemy[i].setHealth(enemyInRange[j].getHealth());
                    cout << enemyInRange[j].getHealth() << " TO " << arrOfEnemy[i].getHealth() << endl;
                }
            }
        }
    }
}