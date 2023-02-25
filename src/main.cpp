#include <iostream>
#include "object/ObjectPlayer.hpp"
#include "object/EnemyCollection.hpp"
#include "object/EnemyPlayer.hpp"
#include "attribute/map/Map.hpp"
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

ObjectPlayer player;
EnemyCollection arrOfEnemy;
Map map;
int ObjectPlayer::killCount = 0;
vector<EnemyPlayer> enemyInRange;

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

void chooseChoicePlayer();

void move(){
    cout << "Please choose where to head" << endl;
    cout << "Input NORTH/SOUTH/EAST/WEST" << endl;
    playerAction();
}

void validateChoice(string choice){
    if(choice == "MOVE"){
        move();
    }else if(choice == "ATTACK"){
        cout << "This is enemy that you can attack, Please choose one and NUMBER" << endl;
        for(int i= 0; i< enemyInRange.size(); i++){
            cout << i+1 << " (" << enemyInRange[i].getCoordinate().x << "," << enemyInRange[i].getCoordinate().y << ")" << endl;
        }
        int choice;
        cout << "Tidak divalidasi lagi; Tolong periksa input" << endl;
        cout << "Please Input Your Choice : ";
        cin >> choice;
        cout << "Before Enemy Health : " << enemyInRange[choice - 1].getHealth() << endl;
        enemyInRange[choice - 1].setHealth(enemyInRange[choice - 1].getHealth()-1);
        cout << "After Enemy Health : " << enemyInRange[choice - 1].getHealth() << endl;
    }else{
        chooseChoicePlayer();
    }
}

void chooseChoicePlayer(){
    cout << "Input Your Choice : ";
    string choice;
    cin >> choice;
    validateChoice(choice);
}

void playerHandle(){
    if(enemyInRange.size() == 0){
        move();
    }else if(enemyInRange.size() > 0){
        cout << "Choose What To Do" << endl;
        cout << "1. MOVE" << endl;
        cout << "2. ATTACK" << endl;
        cout << "Input MOVE or ATTACK" << endl;
        chooseChoicePlayer();
    }
}

void attackRangeMethod(){
    cout << "U're in attack range!" << endl;
    for(int i= 0; i<enemyInRange.size(); i++){
        cout << "Ure being attack! -1 health" << endl;
        player.setHealth(player.getHealth() - 1);
    }
    if(!player.getStatus()){
        playerHandle();
    }
}

bool checkDistance(){
    for(int i= 0; i<arrOfEnemy.getNeff(); i++){
        if(arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer(player.getCoordinate()) <= player.getAttackRange() || arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer(player.getCoordinate()) <= arrOfEnemy.getEnemyArray()[i].getAttackRange()){
            return true;
        }
    }
    return false;
}

void addEnemyInRange(){
    enemyInRange.clear();
    enemyInRange.shrink_to_fit();
    cout << "Distance With Player" << endl;
    for(int i= 0; i<arrOfEnemy.getNeff(); i++){
        cout << arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer(player.getCoordinate()) << " " << player.getAttackRange() << endl;
        if(arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer(player.getCoordinate()) <= player.getAttackRange() || arrOfEnemy.getEnemyArray()[i].getDistanceWithPlayer(player.getCoordinate()) <= arrOfEnemy.getEnemyArray()[i].getAttackRange()){
            enemyInRange.push_back(arrOfEnemy.getEnemyArray()[i]);
        }
    }
    cout << "This is Enemy In Attack Range" << endl;
    for(int i= 0; i< enemyInRange.size(); i++){
        cout << i+1 << ". " << enemyInRange[i].getCoordinate().x << "," << enemyInRange[i].getCoordinate().y << " Enemy Health : " << enemyInRange[i].getHealth() << endl;
    }
}

void notification(int tick, bool* messageAdd){
    cout << "Notification" <<endl;
    if(tick == 0){
        cout << "Game Start" << endl;
        cout << "Enemy has spawned" << endl;
        *messageAdd = false;
    }else if(*messageAdd){
        cout << "Tick : " << tick << endl;
        cout << "Enemy has spawned" << endl;
        *messageAdd = false;
    }else{
        cout << "Tick : " << tick << endl;
    }
}

void chooseChoice();

void startGame(){
    bool messageAdd= false;
    int tick= 0;
    while(!player.getStatus()){
        if(tick % 10 == 0 || tick == 0){
            // cout << "Im here" << endl;
            EnemyPlayer enemy;
            arrOfEnemy.addEnemy(enemy);
            messageAdd = true;
        }
        notification(tick, &messageAdd);
        cout << "Health : " << player.getHealth() << endl;
        cout << "This is Enemy Coordinate" << endl;
        for(int i= 0; i< arrOfEnemy.getNeff(); i++){
            cout << arrOfEnemy.getEnemyArray()[i].getCoordinate().x << "," << arrOfEnemy.getEnemyArray()[i].getCoordinate().y << " Enemy Health : " << arrOfEnemy.getEnemyArray()[i].getHealth() << endl;
        }
        map.printMap(player, arrOfEnemy);
        cout << endl;
        bool inAttackRange= checkDistance();
        addEnemyInRange();
        if(inAttackRange){
            attackRangeMethod();
        }else{
            playerHandle();
        }
        if(player.getStatus()){
            cout << "You End The Game" << endl;
            cout << "Kill Count : " << player.getKillCount() << endl;
            arrOfEnemy.reset();
            player.reset();
            chooseChoice();
        }
        cout << "Current Health : " << player.getHealth() << endl;
        arrOfEnemy.changeHealth(enemyInRange);
        for(int i= 0; i<arrOfEnemy.getNeff(); i++){
            if(arrOfEnemy.getEnemyArray()[i].getHealth() <= 0){
                arrOfEnemy.removeEnemy(i);
                player.killEnemy();
            }
        }
        tick++;
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

void validateChoice();

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
    system("cls");
    chooseChoice();
}