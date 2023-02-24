#include <iostream>
#include "object/ObjectPlayer.hpp"
#include "object/EnemyCollection.hpp"
#include "object/EnemyPlayer.hpp"
#include "attribute/map/Map.hpp"
#include <vector>
#include <math.h>
using namespace std;

// double distance(ObjectPlayer player, EnemyPlayer enemy){
//     return sqrt(pow((player.getCoordinate().x - enemy.getCoordinate().x), 2) + pow((player.getCoordinate().y - enemy.getCoordinate().y), 2));
// }

ObjectPlayer player;
EnemyCollection arrOfEnemy;
Map map;

void playerAction(){
    string choice;
    cout << "Input your choice : ";
    cin >> choice;
    if(choice == "NORTH"){
        player.NORTH();
    }else if(choice == "SOUTH"){
        player.SOUTH();
    }else if(choice == "EAST"){
        player.EAST();
    }else if(choice == "WEST"){
        player.WEST();
    }else{
        cout << "Your Input Is Wrong! Please reinput your choice!" << endl;
        playerAction();
    }
}

void move(){
    cout << "Please choose where to head" << endl;
    cout << "Input NORTH/SOUTH/EAST/WEST" << endl;
    playerAction();
}

void validateChoice(string choice, vector<EnemyPlayer>& addEnemyInRange){
    if(choice == "MOVE"){
        move();
    }else if(choice == "ATTACK"){
        cout << "This is enemy that you can attack, Please choose one and NUMBER" << endl;
        for(int i= 0; i< addEnemyInRange.size(); i++){
            cout << i+1 << " (" << addEnemyInRange[i].getCoordinate().x << "," << addEnemyInRange[i].getCoordinate().y << ")" << endl;
        }
        int choice;
        cout << "Tidak divalidasi lagi; Tolong periksa input" << endl;
        cout << "Please Input Your Choice : ";
        cin >> choice;
        addEnemyInRange[choice - 1].setHealth(addEnemyInRange[choice - 1].getHealth()-1);
    }else{
        chooseChoice(addEnemyInRange);
    }
}

void chooseChoice(vector<EnemyPlayer>& addEnemyInRange){
    cout << "Input Your Choice : ";
    string choice;
    cin >> choice;
    validateChoice(choice, addEnemyInRange);
}

void playerHandle(vector<EnemyPlayer>& addEnemyInRange){
    if(addEnemyInRange.size() == 0){
        move();
    }else if(addEnemyInRange.size() > 0){
        cout << "There is Enemy In Your Attack Range" << endl;
        cout << "Choose What To Do" << endl;
        cout << "1. MOVE" << endl;
        cout << "2. ATTACK" << endl;
        cout << "Input MOVE or ATTACK" << endl;
        chooseChoice(addEnemyInRange);
    }
}

void attackRangeMethod(vector<EnemyPlayer>& addEnemyInRange){
    cout << "U're in attack range!" << endl;
    for(int i= 0; i<addEnemyInRange.size(); i++){
        if(addEnemyInRange[i].getTurn()){
            cout << "Ure being attack! -1 health" << endl;
            player.setHealth(player.getHealth() - 1);
        }
    }
    playerHandle(addEnemyInRange);
}

bool checkDistance(){
    for(int i= 0; i<arrOfEnemy.getNeff(); i++){
        if(arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer() <= player.getAttackRange() || arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer() <= arrOfEnemy.getEnemyArray()[i].getAttackRange()){
            return true;
        }
    }
    return false;
}

void addEnemyInRange(vector<EnemyPlayer>& enemyInRange){
    for(int i= 0; i<arrOfEnemy.getNeff(); i++){
        if(arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer() <= player.getAttackRange() || arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer() <= arrOfEnemy.getEnemyArray()[i].getAttackRange()){
            arrOfEnemy.getEnemyArray()[i].setTurn(true);
            enemyInRange.push_back(arrOfEnemy.getEnemyArray()[i]);
        }
    }
}

void notification(int tick, bool* messageAdd){
    cout << "Notification" <<endl;
    if(tick == 0){
        cout << "Game Start" << endl;
        *messageAdd = false;
    }else if(*messageAdd){
        cout << "Tick : " << tick << endl;
        cout << "Enemy has spawned" << endl;
        *messageAdd = false;
    }else{
        cout << "Tick : " << tick << endl;
    }
}

void copyData(vector<EnemyPlayer> enemyInRange){
    for (int i= 0; i<arrOfEnemy.getNeff(); i++){
        for (int j= 0; j<enemyInRange.size(); i++){
            if(enemyInRange[j].getCoordinate().x == arrOfEnemy.getEnemyArray()[i].getCoordinate().x && enemyInRange[j].getCoordinate().y == arrOfEnemy.getEnemyArray()[i].getCoordinate().y){
                arrOfEnemy.getEnemyArray()[i].setHealth(enemyInRange[j].getHealth());
            }
        }
    }
}

void startGame(){
    bool messageAdd= false;
    int tick= 0;
    while(!player.getStatus()){
        if(tick % 10 == 0){
            EnemyPlayer enemy;
            arrOfEnemy.addEnemy(enemy);
            messageAdd = true;
        }
        notification(tick, &messageAdd);
        map.printMap();
        bool inAttackRange= checkDistance();
        vector<EnemyPlayer> enemyInRange;
        addEnemyInRange(enemyInRange);
        if(inAttackRange){
            attackRangeMethod(enemyInRange);
        }else{
            playerHandle(enemyInRange);
        }
        copyData(enemyInRange);
        for(int i= 0; i<arrOfEnemy.getNeff(); i++){
            if(arrOfEnemy.getEnemyArray()[i].getHealth() <= 0){
                arrOfEnemy.removeEnemy(i);
            }
        }
        tick++;
    }
    if(player.getStatus()){
        cout << "You End The Game" << endl;
        cout << "Kill Count : " << player.getKillCount() << endl;
        arrOfEnemy.reset();
        player.reset();
        chooseChoice();
    }
}

void display(){
    printf(
"                __/___\n"            
"          _____/______|\n"           
"  _______/_____\\_______\\_____\n"     
"  \\              < < <       |\n  "  
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
    );
    cout << "================" << endl;
    cout << "Battle Ship Game" << endl;
    cout << "================" << endl;
}

void chooseChoice(){
    display();
    cout << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit" << endl;
    validateChoice();
}

void validateChoice(){
    int choice;
    cout << "Please insert the number : ";
    cin >> choice;
    if (choice == 1){
        startGame();
    }else if(choice == 2){
        cout << "See You Again Sir ^^!" << endl;
        exit(0);
    }else{
        cout << "Your Input Is Wrong, Please Reinput!" << endl;
        chooseChoice();
    }
}

int main(){
    chooseChoice();
}