#include <iostream>
#include "Map.hpp"
using namespace std;

Map::Map(){
    this->size_x = 20;
    this->size_y = 20;
}

bool checkEnemyCoordinate(int i, int j, vector<EnemyPlayer> enemyCollection){
    for(int k = 0; k < enemyCollection.size(); k++){
        if(enemyCollection[k].getCoordinate().x == j && enemyCollection[k].getCoordinate().y == i){
            return true;
        }
    }
    return false;
}

void Map::printMap(ObjectPlayer player, EnemyCollection arrOfEnemy){
    for(int i= 0; i<=size_x+2; i++){
        cout <<"#";
    }
    cout << endl;
    for(int i= (size_y/2)*(-1); i<= size_y/2; i++){
        for(int j= ((size_x/2)*(-1))-1; j<= (size_x/2)+1; j++){
            // cout << checkEnemyCoordinate(i, j, EnemyCollection::getEnemyArray()) << endl;
            if(j == (size_x/2)*(-1)-1 || j== (size_x/2)+1){
                cout << "#";
            }else{
                if(i == player.getCoordinate().y && j == player.getCoordinate().x){
                    cout << "P";
                }else if(checkEnemyCoordinate(i, j, arrOfEnemy.getEnemyArray())){
                    cout << "E";
                }else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    for(int i= 0; i<=size_x+2; i++){
        cout <<"#";
    }
}